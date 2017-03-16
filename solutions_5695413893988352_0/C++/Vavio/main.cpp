//
//  main.cpp
//  CountingSheep
//
//  Created by TT on 09/04/2016.
//  Copyright © 2016 TT. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <iomanip>
#include <fstream>
#include <unordered_map>


#define READ_FILE 0
#define ULL_MAX
using namespace std;

typedef unsigned long long ull;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small.out");

ull minC, minJ, minD;

string C, J;
int R = 10;
int N;

int *a;

ull diff(ull c, ull j){
    if (c > j){
        return c - j;
    }
    return j - c;
}

void process(){
    string tmpC(C), tmpJ(J);
    int k = 0;
    for (int i=0; i<C.length(); ++i){
        if (tmpC[i] == '?'){
            tmpC[i] = a[k] + '0';
            k++;
        }
    }
    
    for (int i=0; i<J.length(); ++i){
        if (tmpJ[i] == '?'){
            tmpJ[i] = a[k] + '0';
            k++;
        }
    }
    
    ull uC = stoull(tmpC), uJ = stoull(tmpJ);
    ull tmpD = diff(uC, uJ);
    if (tmpD < minD){
        minD = tmpD;
        minC = uC;
        minJ = uJ;
    } else if (tmpD == minD){
        if (uC < minC || uJ < minJ){
            minC = uC;
            minJ = uJ;
        }
    }
    
}


void enumerate(int n)
{
    if (n == N)
    {
        process();
        return;
    }
    
    for (int r = 0; r < R; ++r){
        a[n] = r;
        enumerate(n+1);
    }
}

void fMain(int t){
    if (READ_FILE){
        cin >> C >> J;
    } else {
        fin >> C >> J;
    }
    
    N = 0;
    for (int i=0; i<C.length(); ++i){
        if (C[i] == '?'){
            N++;
        }
        
        if (J[i] == '?'){
            N++;
        }
    }
    
    a = new int[N];
    memset(a, 0, N);
    minD = minC = minJ = ULONG_LONG_MAX;
    
    
    enumerate(0);
    if (READ_FILE){
        cout << "Case #" << t << ": ";
        cout << setw((int)C.length()) << setfill('0') << minC <<  " ";
        cout << setw((int)C.length()) << setfill('0') << minJ << endl;
    } else {
        fout << "Case #" << t << ": ";
        fout << setw((int)C.length()) << setfill('0') << minC <<  " ";
        fout << setw((int)C.length()) << setfill('0') << minJ << endl;
    }
    
    cout << N << endl;
}




int main(int argc, const char * argv[]) {
    int T;
    if (READ_FILE){
        cin >> T;
    } else {
        fin >> T;
    }
    for (int t = 1; t <=T; ++t){
        fMain(t);
    }
    fin.close();
    fout.flush();
    fout.close();
    return 0;
}
