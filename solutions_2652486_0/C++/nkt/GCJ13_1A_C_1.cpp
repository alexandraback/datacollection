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
	ifstream inp("C-small-1-attempt1.in");
	ofstream out; out.open("output.txt");
    int t;
	inp>>t;
    out<<"Case #1:"<<endl;
    int r,n,m,k;
    inp>>r>>n>>m>>k;
	for (int ii = 1; ii <= 100; ii++)
	{



        int x[4];
        int val[8];
        for (int i = 1; i <= k ; i++) inp>>val[i];
        bool mark[200];
        bool ok;
        for (x[1] = 2; x[1] <= 5; x[1]++)
            for (x[2] = 2; x[2] <= 5; x[2]++)
                for (x[3] = 3; x[3] <= 5; x[3]++)
                {
                    memset(mark,false,sizeof(mark));
                    mark[1] = true; mark[x[1]] = true;
                    mark[x[2]] = true; mark[x[3]] = true;
                    mark[x[1]*x[2]] = true;
                    mark[x[2]*x[3]] = true;
                    mark[x[1]*x[3]] = true;
                    mark[x[1]*x[2]*x[3]] = true;
                    ok = true;
                    for (int i = 1; i <= k; i++)
                        if (!mark[val[i]])
                        {
                            ok = false;
                            break;
                        }
                    if (ok)
                    {
                        out<<x[1]<<x[2]<<x[3]<<endl;
                        x[1] = 5; x[2] = 5; x[3] = 5;
                        break;
                    }

                }
        if (!ok) out<<111<<endl;
	}

	out.close();
	return 0;
}
