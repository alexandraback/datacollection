#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include "bigint.h"
#include <cstring>

using namespace std;

int main()
{
//   ifstream fin("A-small-attempt1.in");
//  ofstream fout("A-small-attempt1.out");
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    int T;
    long double r, ink;
    fin >> T;
    
    for (int t = 1 ; t <= T; t++)
    {  
		fin >> r >> ink;
		if (t == 12)
			cout << -(2.0*r-1.0) << " " << sqrt((2.0*r-1.0)*(2.0*r-1.0)+8.0*ink) << " ";
			
		long double temp = (-(2.0*r-1.0) + sqrt((2.0*r-1.0)*(2.0*r-1.0)+8.0*ink))/4.0;
		if (t == 12) cout << temp<< endl;
		int ans = (int) floor(temp);
		
		fout << "Case #" << t << ": ";
		if (ans == 0) ans = 1;
        fout << ans << endl;
    }
}
