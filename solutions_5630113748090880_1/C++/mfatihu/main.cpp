/* 
 * File:   main.cpp
 * Author: mehmetfatihuslu
 *
 * Created on April 12, 2014, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) {

    fstream inputFile, outputFile, logFile;
    int T,N,K,C,S;   
    
    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);       
    logFile.open("log",ios::out);       
    
    inputFile >> T;
    
    for(int dongu=1; dongu<=T; dongu++) {
        
        inputFile >> N;
        int *liste = new int[2501];
        
        for(int i=0;i<2501;i++)
            liste[i] = 0;
        
        for(int i=0;i<2*N-1;i++){
            
            for(int j=0;j<N;j++){
                
                int buffer;
                inputFile >> buffer;
                liste[buffer]++;
            }
        }
        
        outputFile << "Case #" <<dongu <<": ";
        
        for(int i=0;i<2501;i++)
            if(liste[i]%2==1)
                outputFile<<i<<" ";
            
        outputFile << endl;
                
    }
    
    return 0;
}

