#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cmath>

#define PB push_back
#define MP make_pair
#pragma comment(linker, "/STACK:16777216")

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

/*
inline int read_int()
{
    register char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}
*/

/*
struct matrix
{
    int64 a[2][2];
};

matrix mul(matrix A,matrix B)
{
    matrix C;
    memset(C.a,0,sizeof(C.a));
    for (int i = 0; i <= 1;i ++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % md;
    return C;
}

matrix pow(matrix A, int64 p)
{
    if (p == 1) return A;
    if (p & 1) return mul(A,pow(A,p-1));
    matrix X = pow(A,p >> 1);
    return mul(X,X);
}

*/

int main()
{
    ifstream inp("A-small-attempt1.in");
    ofstream out; out.open("output.txt");
	int t;

	inp>>t;


	for (int ii = 1; ii <= t; ii++)
	{
	    int64 r,t;
	    inp>>r>>t;
        int64 res;
        int64 low = 1,high = 2*1e18,mid = 0;
        while (low <= high)
        {
            mid = (low+high)/2;
            //cout<<mid<<endl;
            if (t/mid == (2*r-1+2*mid))
            {
               res = mid;
               //cout<<res<<endl;
               low = mid+1;
            }
            else if (t/mid > (2*r-1+2*mid))
            {
                res = mid;
                low = mid+1;
            }

            else high = mid-1;
        }
        out<<"Case #"<<ii<<": "<<res<<endl;
        //cout<<"Res = "<<res<<endl;
	    //cout<<t/(r*2+1)<<endl;
	}
	out.close();
	return 0;
}
