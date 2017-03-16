/* 
 * File:   main.cpp
 * Author: nickeveritt
 *
 * Created on May 5, 2012, 3:01 PM
 */

#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <iostream.h>
#include <fstream.h>

using namespace std;

/*
 * 
 */

double codeJamStartClock;
int caseCount;
static int largeCases;
string problemFileName;
ofstream resultFile;
ifstream problemFile;

void programStart() {
    cerr << "program started" << endl;
    resultFile.open("/Users/nickeveritt/Desktop/result.txt");
    string problemPath = "/Users/nickeveritt/Desktop/";
    string problemPathFile = problemPath + problemFileName;
    problemFile.open(problemPathFile.c_str());
    if (!resultFile.is_open()) cerr << "error opening result file" << endl;
    if (!problemFile.is_open()) cerr << "error opening problem file" << endl;
    problemFile >> caseCount;
    codeJamStartClock = clock();
    cerr << "cases: " << caseCount << endl;
}

void programEnd() {
    double programEndClock = clock();
    double timeDiff = programEndClock - codeJamStartClock;
    double timePerCase = 0;
    if (caseCount > 0) timePerCase = timeDiff / (double)caseCount;
    cerr << "program ended" << endl;
    cerr << "time taken     : " << (timeDiff/1000) << "s" << endl;
    cerr << "time per case  : " << timePerCase << "ms" << endl;
    double timeForLarge = timePerCase * (double)largeCases / 1000.0;
    cerr << "time for large : " << timeForLarge << "s" << endl;
    cerr << "viability      : ";
    if (timeForLarge <= 300) cerr << "excellent";
    else
        if (timeForLarge <= 360) cerr << "good";
        else
            if (timeForLarge <= 420) cerr << "caution";
            else
                if (timeForLarge <= 480) cerr << "poor";
                else
                    cerr << "not viable";
    cerr << endl;
    resultFile.close();
    problemFile.close();
}


int numClasses;
int numInherits[1100];
int inherits[1100][1100];



bool reachable(int fromClass, int toClass, int path[], int pathLen) {
    
    bool isReachable = false;
    
    if (fromClass == toClass) {
        return true;
    }
    
    for (int i=0; i<numInherits[fromClass]; i++) {
        
        bool beenBefore = false;
        for (int j=0; j<pathLen; j++) {
            if (path[j] == inherits[fromClass][i]) beenBefore = true;
        }
        
        beenBefore = false;
        if (!beenBefore) {
            
            path[pathLen] = inherits[fromClass][i];
            pathLen++;
            
            if ( reachable(inherits[fromClass][i],toClass,path,pathLen) ) {
                isReachable = true;
            }
        
        }
    }
    
    return isReachable;
}



int main(int argc, char** argv) {
    largeCases = 50;
    problemFileName = "A-small-attempt2.in";
    programStart();
    
    
    for (int caseNumber=0; caseNumber<caseCount; caseNumber++) {
        
        // problem file reader

        
        problemFile >> numClasses;
        
        cerr << "CASE " << (caseNumber+1) << " has " << numClasses << " classes" << endl;
        
        for (int n=0; n<numClasses; n++) {
            problemFile >> numInherits[n];
            cerr << "class " << n+1 << " inherits from " << numInherits[n] << " classes: "; 
            for (int i=0; i<numInherits[n]; i++) {
                int inheritance;
                problemFile >> inheritance;
                inheritance--;
                inherits[n][i] = inheritance;
                cerr << (inherits[n][i]+1) << " ";
            }
            cerr << endl;
        }
        
        // solve
        
        bool containsDiamond = false;
        
        for (int n1=0; n1<numClasses; n1++) {
            cerr << "completed " << n1+1 << " of " << numClasses << "classes" << endl;
            for (int n2=0; n2<numClasses; n2++) {
                
                int reachableCount = 0;
                for (int m=0; m<numInherits[n1]; m++) {
                    
                    int path[1100];
                    path[0] = n1;
                    int pathLen = 1;
                    if (reachable(inherits[n1][m],n2,path,pathLen)) reachableCount++;
                    
                    if (reachableCount >= 2) {
                        // contains diamond
                        containsDiamond = true;
                        cerr << "diamond found" << endl;
                        
                        m = numInherits[n1] + 1;
                        n2 = numClasses + 1;
                        n1 = numClasses + 1;
                    }
                    
                    
                }
                

                
                
            }
            
            
        }
        
        // output solution     
        resultFile << "Case #" << (caseNumber+1) << ": ";
        if (containsDiamond) resultFile << "Yes"; else resultFile << "No";
        resultFile << endl;
        
    }
    programEnd();
    return 0;
}

