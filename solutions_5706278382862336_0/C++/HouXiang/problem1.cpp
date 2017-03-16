// problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set> 
#include <algorithm>

using namespace std; 

long long getlong(string s) {
    long long res = 0; 
    for (int i=0; i<s.size(); i++) {
        res *= 10; 
        res += s[i] - '0';
    }
    return res; 
}

long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    else return gcd(b, a%b); 
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf (argv[1]);
    // ifstream inf("D:\\codejam\\problem1\\Debug\\test.txt"); 

	int TC;
    inf >> TC; 

	for (int T = 1; T <= TC; T++){
        string s; 
        inf >> s; 
        long long fenzi, fenmu; 
        fenzi = getlong( s.substr(0, s.find('/')) );
        fenmu = getlong( s.substr(s.find('/') + 1));

        long long g = gcd(fenmu, fenzi);

        fenzi /= g; 
        fenmu /= g; 

        bool ok = true;
        long long f = fenmu; 
        while (ok) {
            if (f == 1) break;
            else if (f % 2 != 0) {
                ok = false;
                break;
            }
            else {
                f /= 2; 
            }
        }

        if (!ok) {
            cout << "Case #" << T << ": " << "impossible" << endl;
            continue;
        }

        long long ans = 0; 
        while (true) {
            ans++; 
            fenzi *= 2; 
            if (fenzi >= fenmu) break;
        }


        cout << "Case #" << T << ": " << ans << endl;
	}
	return 0;
}

