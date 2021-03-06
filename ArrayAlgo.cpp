//
//  ArrayAlgo.cpp
//  Algorithms
//
//  Created by Sandip Pal on 3/1/19.
//  Copyright © 2019 Sandip Pal. All rights reserved.
//

#include "ArrayAlgo.hpp"


vector<int> ArrayAlgo::Aunion(vector<int> &a , vector <int> &b)
{
    vector<int> output;
    int firstLeft = 0 , secondLeft = 0;
    int count = 0;
    
    while( (firstLeft < a.size()) && (secondLeft < b.size()) ){
        int num = 0;
        if( a[firstLeft] < b[secondLeft]){
            output.push_back(a[firstLeft]);
            num = a[firstLeft];
            firstLeft++ ;
            
            
        }
        else if(a[firstLeft] > b[secondLeft]){
            output.push_back(b[secondLeft]);
            num = b[secondLeft];
            secondLeft++;
            
        }
        else{  // equality
            
            output.push_back(b[secondLeft]);
            num = b[secondLeft];
            
        }
        // Now skip in both the arrays
        while(a[firstLeft] == num){
            firstLeft++;
        }
        while(b[secondLeft] == num){
            secondLeft++;
        }
        
        count++;
        
        // Fill with the remainder of the other array in the output array
        if(firstLeft == a.size()){
            while(secondLeft < b.size()){
                output.push_back(b[secondLeft]);
                count++;
            }
            
            
        }
        if(secondLeft == b.size()){
            while(firstLeft < a.size()){
                output.push_back(a[firstLeft]);
                count++;
            }
            
        }
        
    }
    
    return output;

    
}


vector<int> ArrayAlgo::Aintersect(vector<int> &a, vector<int> &b){
    
    int firstLeft = 0 , secondLeft = 0;
    
    int count = 0;
    vector<int> output;
    while( (firstLeft < a.size()) && (secondLeft < b.size()) ){
        if( a[firstLeft] < b[secondLeft]){
            firstLeft++ ;
        }
        else if(a[firstLeft] > b[secondLeft]){
            
            secondLeft++;
        }
        else{ // equality
            int num = a[firstLeft];
            output.push_back(num);
            count++;
            // Now skip in both the arrays
            while(a[firstLeft] == num){
                firstLeft++;
            }
            while(b[secondLeft] == num){
                secondLeft++;
            }
        }
        
    }

    
    return output;
    
    
}


bool ArrayAlgo::iSRotated(vector<int> a, vector<int> b){
    if(a.size() != b.size()) return false;
    int retVal = true;
    vector<int> c(a);
    for(int i = 0 ; i < a.size(); i++){
        c.push_back(a[i]);
    }
    for(int i = 0 ; i < a.size() ; i++){
        int start = 0;
        retVal = true;
        while(start < b.size()){
            if(c[i + start] == b[start]){
                
            }
            else{
                retVal = false;
                break;
            }
            start++;
        }
        if(retVal == true) break;
    }
    
    return retVal;
}
