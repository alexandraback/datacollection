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

int64 res[1000000];

bool palin(int64 x)
{
    stringstream ss;
    ss << x;
    string s = ss.str();

    for (int j = 0; j <= ((s.length()-1)/2); j++)
    {
        if (s[j] != s[s.length()-1-j]) return false;
    }

    return true;

}
int main()
{
    int64 lim = (int64)1e14;
    //cout<<lim<<endl;
	int t;
	ifstream inp("C-large-1.in");
	ofstream out;
	out.open("output.txt");

	inp>>t;
	res[0] = 3;
	res[1] = 1; res[2] = 4; res[3] = 9;

    int i = 2;

	for (int i = 10; i <= 10000000; i++)
	{
	    if (palin(i))
	    {
	        int64 sq = (int64)i*i;
	        if (palin(sq)) res[++res[0]] = sq;
	    }
	}

    //cout<<res[0]<<endl;
    //for (int i = 1; i <= res[0]; i++) cout<<res[i]<<endl;

	for (int ii = 1; ii <= t; ii++)
	{
        int64 a,b;
        inp>>a>>b;
        int pos1 = 0, pos2 = 0;
        for (int i = 1; i <= res[0]; i++)
        {
            if ((pos1 == 0) && (res[i] >= a)) pos1 = i;
            if (res[i] <= b) pos2 = i;
        }
        int64 op = 0;
        if (pos1 == 0) op = 0; else op = pos2-pos1+1;
        if (op < 0) op = 0;
        //cout<<pos1<<" "<<pos2<<endl;
        //if (pos2 - pos1 + 1 < 0) pos2 = pos1 - 1;
        out<<"Case #"<<ii<<": "<<op<<endl;
	}

	out.close();
	return 0;
}
