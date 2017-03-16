/*
 * File:   main.cpp
 * Author: mehmetfatihuslu
 *
 * Created on April 12, 2014, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;


int main(int argc, char** argv) {

    fstream inputFile, outputFile, logFile;
    int T,N,deceit,optimal = 0;
    double *naomi,*ken;

    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);
    logFile.open("log",ios::out);

    inputFile >> T;

    for(int dongu=1; dongu<=T; dongu++) {

    	inputFile >> N;
    	logFile <<N<<endl;

    	naomi = new double[N];
    	ken = new double[N];

    	for(int i=0;i<N;i++){

    		inputFile >> naomi[i];
    	}

    	for(int i=0;i<N;i++){

    		inputFile >> ken[i];
    	}

    	std::sort(naomi, naomi+N);
    	std::sort(ken,ken+N);

    	double* tempnaomi = new double[N];
    	double* tempken = new double[N];

    	for(int i=0;i<N;i++){

    		tempnaomi[i]=naomi[i];
    		tempken[i]=ken[i];
    	}

    	int npoint = N;
    	int kpoint = N;

    	int nwin = 0;

    	for(int i=0;i<N;i++){

    		if(tempnaomi[npoint-1]>tempken[kpoint-1]){

    			nwin++;
    			npoint--;
    			kpoint--;
    			for(int j=0;j<kpoint;j++){
    				tempken[j]=tempken[j+1];
    			}
    		}
    		else {

    			npoint--;
    			kpoint--;
    			for(int j=0;j<kpoint;j++){
    				if(tempken[j]>tempnaomi[npoint-1]){

    					for(int k=j;k<kpoint;k++){
    						tempken[k]=tempken[k+1];
    					}
    				}
    			}
    		}
    	}

    	int optimal = nwin;
    	for(int i=0;i<N;i++){

    		tempnaomi[i]=ken[i];
    		tempken[i]=naomi[i];
    	}

    	npoint = N;
    	kpoint = N;

    	nwin = 0;

    	for(int i=0;i<N;i++){

    		if(tempnaomi[npoint-1]>tempken[kpoint-1]){

    			nwin++;
    			npoint--;
    			kpoint--;
    			for(int j=0;j<kpoint;j++){
    				tempken[j]=tempken[j+1];
    			}
    		}
    		else {

    			npoint--;
    			kpoint--;
    			for(int j=0;j<kpoint;j++){
    				if(tempken[j]>tempnaomi[npoint-1]){

    					for(int k=j;k<kpoint;k++){
    						tempken[k]=tempken[k+1];
    					}
    				}
    			}
    		}
    	}

    	int deceit = N-nwin;

        outputFile << "Case #" <<dongu <<": "<<deceit<<" "<<optimal<<endl;
    }

    return 0;
}

