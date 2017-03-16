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
	int t;
	ifstream inp("B-large.in");
	ofstream out; out.open("output.txt");

	inp>>t;

	for (int ii = 1 ; ii <= t; ii++)
	{
	    int r[101],c[101],a[101][101];
	    memset(r,0,sizeof(r)); memset(c,0,sizeof(c));
	    int n,m;
	    inp>>n>>m;
	    for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                //cout<<i<<" "<<j<<endl;
                inp>>a[i][j];
            }

        //cout<<n<<" "<<m<<endl;
	    bool pos = true;
	    for (int k = 100; k >= 1; k--)
	    {
	        for (int i = 1; i <= n; i++)
            {
                if (!pos) break;
                for (int j = 1; j <= m; j++)
                {
                    if (a[i][j] != k) continue;
                    //cout<<i<<" "<<j<<endl;
                    int cnt = 0;
                    if (r[i] == 0)
                    {
                        r[i] = a[i][j];
                    } else if (r[i] != a[i][j]) cnt++;

                    if (c[j] == 0) c[j] = a[i][j];
                    else if (c[j] != a[i][j]) cnt++;
                    if (cnt == 2)
                    {
                        pos = false;
                        break;
                    }
                }
            }
	    }


	    out<<"Case #"<<ii<<": ";
	    if (pos) out<<"YES"<<endl; else out<<"NO"<<endl;

	}

	out.close();
	return 0;
}
