#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include <time.h>

using namespace std;

int E, R, N; 
vector<int> v; 

__int64 consume(int leftE, int l, int r, int count) {
    if (l == r) return 0; 

    int mv = 0; 
    int p = 0; 
    for (int i=l; i<r; i++) {
        if (v[i] > mv) {
            mv = v[i];
            p = i; 
        }
    }

    int ae = leftE + (p - l) * R; 
    int ce = 0; 

    if (ae <= E) {
        // not overflow at p
        ce = min(ae, count);

        int res = ce * v[p]; 
        if (ce == count) {
            return res;
        }
        else {
            res += consume(R, p+1, r, count - ce); 
            return res; 
        }
    }
    else {
        // overflow at p
        int res = 0; 
        res += consume(leftE, l, p, ae - E);

        count -= (ae - E); 

        ce = min(E, count);

        res += ce * v[p]; 
        
        
        if (ce == count) {
            return res;
        }
        else {
            res += consume(R, p+1, r, count - ce); 
            return res; 
        }
    }
    
}

__int64 solution(int leftE, int l, int r) {
    if (l == r) return 0; 

    int mv = 0; 
    int p = 0; 
    for (int i=l; i<r; i++) {
        if (v[i] > mv) {
            mv = v[i];
            p = i; 
        }
    }

    __int64 res = 0; 
    int ae = leftE + (p - l) * R; 
    if (ae > E) {
        res = E * v[p]; 
    }
    else {
        res = ae * v[p]; 
    }

    // right part
    res += solution(R, p+1, r); 

    // left part
    if (ae > E) {
        int waste = ae - E; 
        res += consume(leftE, l, p, waste); 
    }

    return res; 
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "wrong number of parameter" << endl;
        return -1;
    }

    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "cannot open file " << argv[1] << endl;
        return -1;
    }

    string ln;  
    inf >> ln;

    int number = atoi(ln.c_str());

    for (int cases=0; cases<number; cases++) 
    {
        
        inf >> ln; E = atoi(ln.c_str()); 
        inf >> ln; R = atoi(ln.c_str()); 
        inf >> ln; N = atoi(ln.c_str()); 
        
        v.clear();
        for (int i = 0; i<N; i++) {
            inf >> ln; 
            v.push_back(atoi(ln.c_str())); 
        }

        // print result
        cout << "Case #" << (cases + 1) << ": " << solution(E, 0, N) << endl;
    }

    return 0;
}
