// prlblem2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std; 

double c, f, x; 


double ans() {
    double res = 0; 
    double rate = 2; 
    do {
        double timec = c / rate; 
        double y = c * (rate + f) / f; 

        double test = x / rate; 

        if ((x - y < DBL_EPSILON) || (x / rate < 0.00000001)) {
            res += x / rate; 
            break;
        }
        else {
            res += c / rate; 
            rate += f; 
        }
    } while (true); 

    return res; 
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf(argv[1]); 
    // ifstream inf("D:\\codejam\\prlblem2\\Debug\\test.txt"); 

    int n = 0; 
    inf >> n; 
    for (int ca=1; ca<=n; ca++) {
        inf >> c >> f >> x; 

        double res = ans(); 
        printf ("Case #%d: %.7f\n", ca, res);
    }

	return 0;
}

