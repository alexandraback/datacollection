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
void newwar(int res) {
    if (v1.empty()) {
        best = best < res ? res : best; 
    }
    else {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end()); 

        if (v1[0] > v2.back()) {
            best = best < res + v1.size() ? res + v1.size() : best;
            return;
        }
        else if (v1.back() < v2[0]) {
            return; 
        }

        int i=0; 
        for (; i<v1.size(); i++) {
            if (v1[i] > v2[0])
                break;
        }

        if (i < v1.size()) {
            int i1 = v1[i];
            int i2 = v2[0];
            v1.erase(v1.begin() + i);
            v2.erase(v2.begin());
            newwar(res+1);
            v1.push_back(i1);
            v2.push_back(i2);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        {
            int i1 = v1[0]; 
            int i2 = v2.back();
            v1.erase(v1.begin());
            v2.erase(v2.end() - 1);
            newwar(res);
            v1.push_back(i1);
            v2.push_back(i2);
        }
    }
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

        newwar(0);

        v1 = vb1; 
        v2 = vb2;

        printf ("Case #%d: %d %d\n", ca, best, normalwar());
    }

	return 0;
}

