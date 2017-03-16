// problem4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<double> v1, v2; 

int normalwar() {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int res = 0; 
    for (int i=0; i<v1.size(); i++) {
        int ind = -1; 
        for (int j=0; j<v2.size(); j++) {
            if (v2[j] > v1[i]) {
                ind = j;
                break;
            }
        }
        if (ind == -1) {
            v2.erase(v2.begin());
            res++;
        }
        else {
            v2.erase(v2.begin() + ind);
        }
    }
    return res; 
}

int best = 0; 
int newwar() {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int res = 0; 

    for (int i=0; i<v1.size(); i++) {
        if (v1[i] < v2[0]) {
            v2.erase(v2.end() - 1);
        }
        else {
            res++;
            v2.erase(v2.begin());
        }
    }

    return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf (argv[1]); 
    // ifstream inf("D:\\codejam\\problem4\\Debug\\test.txt");

    int t; 
    inf >> t; 

    for (int ca=1; ca<=t; ca++) {
        int n; 
        v1.clear(); 
        v2.clear();
        best = 0; 

        inf >> n; 

        for (int i=0; i<n; i++) {
            double d = 0; 
            inf >> d; 
            v1.push_back(d); 
        }

        for (int i=0; i<n; i++) {
            double d = 0; 
            inf >> d; 
            v2.push_back(d); 
        }
        
        vector<double> vb1, vb2; 
        vb1 = v1; 
        vb2 = v2; 

        int res1 = newwar();

        v1 = vb1; 
        v2 = vb2;

        printf ("Case #%d: %d %d\n", ca, res1, normalwar());
    }

	return 0;
}

