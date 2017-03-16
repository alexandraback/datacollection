/* 
 * File:   main.cpp
 * Author: mfatihuslu
 *
 * Created on April 27, 2013, 4:07 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#define AND &&
#define OR ||

using namespace std;

    fstream inputFile, outputFile, logFile;
    int T;
    long long t,r;

/*
 * 
 */
int main(int argc, char** argv) {


    
    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);
    logFile.open("log",ios::out);
    
    inputFile >> T;
    
    for(int i=0; i<T; i++) {
        
        inputFile >> r >> t;
        
        long long result = 0;
        
        for(int j=1;true;j++){
            
            if(j*2*r + 2*j*j - j > t)
                    break;
            
            result ++;
        }
            
        
        outputFile << "Case #" << i+1 << ": " << result << endl; 
        
    }
    
    outputFile <<"";
    
    return 0;

}

