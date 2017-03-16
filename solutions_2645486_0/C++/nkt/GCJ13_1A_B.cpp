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
map<int,int> G[2];

int main()
{
	ifstream inp("B-small-attempt0.in");
    ofstream out; out.open("output.txt");

    int t;
    inp>>t;

    for (int ii = 1; ii <= t; ii++)
    {
        int e,r,n;
        vector<int> v;
        G[0].clear(); G[1].clear();
        inp>>e>>r>>n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            inp>>x;
            v.PB(x);
        }

        G[0][e] = 0;
        int k = 0;
        map<int,int>::iterator ij;

        for (int i = 0; i < n; i++)
        {
            int kk = 1-k;
            G[kk].clear();
            for (ij = G[k].begin(); ij != G[k].end(); ij++)
            {
                for (int j = 0; j <= (*ij).first; j++)
                {
                    int nn = (*ij).first-j+r;
                    if (nn > e) nn = e;
                    G[kk][nn] = max(G[kk][nn],(*ij).second+v[i]*j);
                }
            }

            k = 1 - k;
        }

        int res = 0;
        for (int i = 0; i <= 1; i++)
            for (ij = G[i].begin(); ij != G[i].end(); ij++)
                res = max(res,(*ij).second);

        out<<"Case #"<<ii<<": "<<res<<endl;
        //cout<<res<<endl;
    }
    out.close();
	return 0;
}
