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
    int T,K,C,S;   
    
    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);       
    logFile.open("log",ios::out);       
    
    inputFile >> T;
    string line;
    getline(inputFile, line);
    

    
    for(int dongu=1; dongu<=T; dongu++) {
        
        int start = 999;
        int finish = 1000;
        int active = 999;
        char reference;
        char* finalArray = new char[2000];
        
        getline(inputFile, line);
        reference = line.at(0);
        outputFile << "Case #" <<dongu <<": ";
       
        for(int i=0;i<line.length();i++){
            
            finalArray[active] = line.at(i);
            
            if(i<line.length()-1){
                
                if(reference>line.at(i+1)){
                    
                    active = finish;
                    finish = finish+1;
                }
                else{
                
                    reference = line.at(i+1);
                    active = start-1;
                    start = start-1;
                }
            }
        }
        
        for(int i=start;i<finish;i++)
            outputFile << finalArray[i];
            
        outputFile << endl;
                
    }
    
    return 0;
}

