/*
ID: zachary11
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;
int minSolve;

template <typename Type>
string toString(Type t){
	stringstream ss;
        string s;
	ss << t;
        ss >> s;
        return s;
}

template <typename Type>
char toChar(Type t){
	stringstream ss;
        char s;
	ss << t;
        ss >> s;
        return s;
}

void eat(long &size, vector<long> &motes){
    for(int i=motes.size(); i>0; i--){
        if(size > motes[0]){
            size+=motes[0];
            motes.erase(motes.begin());
        } else break;
    }
}

int createSolve(long size, vector<long> motes, int remove){
    motes.erase(motes.end() - remove, motes.end());
    //for(int i=0; i<motes.size(); i++) cout << " " << motes[i] << " ";
    //cout << "finish" << endl;
    int createCount = 0;
    while(createCount < minSolve && motes.size() > 0){
        size = 2*size - 1;
        createCount++;
        //cout << size << " " << motes.size();
        eat(size, motes);
        //cout << " to " << size << " " << motes.size() << " with cc " << createCount << " and r " << remove << endl;
    }
    //cout << remove << " " << createCount << endl;
    return createCount + remove;
}

int solve(long &size, vector<long> &motes){
    eat(size, motes);
    minSolve =  motes.size();
    for(int i=motes.size()-1; i>=0; i--){
        int current = createSolve(size, motes, i);
        if(current < minSolve) minSolve = current;
    }
    return minSolve;
}

int main() {
    ofstream fout("codeJam.out");
    ifstream fin("codeJam.in");
    long caseNumber=0;
    fin >> caseNumber;
    for(long i=1; i<=caseNumber; i++){
        
        long size;
        int numMotes;
        vector<long> motes;
        fin >> size >> numMotes;
        for(int i=0; i<numMotes; i++){
            long mote;
            fin >> mote;
            motes.push_back(mote);
        }
        sort(motes.begin(), motes.end());
        
        string solution = toString(solve(size, motes));
        fout << "Case #" << i << ": " << solution << endl;
        cout << "Case #" << i << ": " << solution << endl;
    }
    
    return 0;
}
