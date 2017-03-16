/* 
 * File:   main.cpp
 * Author: mfatihuslu
 *
 * Created on April 27, 2013, 5:18 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define AND &&
#define OR ||

using namespace std;

    fstream inputFile, outputFile, logFile;
    int T;
    int E,R,N;
    int *v;
    
    int Vlen;

/*
 * 
 */
    
int solve(int E,int R,int N,int*v){
    
    if(N==1){
        
        return E*v[Vlen-1];
    }
    else{
        
        int max = 0;
        int tempOrder = 0;
        
        for(int i=0;i<=E;i++){
            
            int maxE = E<(E-i+R)?E:(E-i+R);
            int temp = solve(maxE,R,N-1,v) + i*v[Vlen-N];
            
            //logFile << "N=" << N << " iken " << i << " adet kullandi, kazanci " << temp << " oldu" << endl;
            
            if(temp > max){
                
                max = temp;
                tempOrder = i;
            }
                
               
        }
        
        
        
        return max;
    }
}

int main(int argc, char** argv) {


    
    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);
    logFile.open("log",ios::out);
    
    inputFile >> T;
    
    for(int i=0; i<T; i++) {
        
        inputFile >> E >> R >> N;
        //logFile << "case " <<i<<endl;
        
        v = new int[N];
        
        for(int j=0;j<N;j++)
            inputFile >> v[j];
        
        Vlen = N;
        
        int result = solve(E,R,N,v);
        
        outputFile << "Case #" << i+1 << ": " << result << endl; 
        
    }
    
    outputFile <<"";
    
    return 0;

}

