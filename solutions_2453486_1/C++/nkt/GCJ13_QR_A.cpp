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

	ifstream inp("A-large.in");
	ofstream out;
	out.open("output.txt");

	inp>>t;
	int board[5][5];

	for (int ii = 1; ii <= t; ii++)
	{
	    int cnt = 0;
	    memset(board,0,sizeof(board));

	    for (int  i = 0; i < 4; i++)
	    {
	        string s;
	        inp>>s;
	        for (int j = 0; j < 4; j++)
	        {
	            if (s[j] == 'X') board[i][j] = 'X';
	            else if (s[j] == 'O') board[i][j] = 'O';
	            else if (s[j] == 'T') board[i][j] = 'T';
	            if ((s[j] == 'X') || (s[j] == 'O') || (s[j] == 'T')) cnt++;
	        }
	    }

	    int win = 0;
	    int sum2 = 0; int sum3 = 0;
	    for (int i = 0; i < 4; i++)
	    {
	        int sum = 0,sum1 = 0;
	        for (int j = 0; j < 4; j++)
	        {
	            if ((board[i][j] == 'X') || (board[i][j] == 'T')) sum++;
	            if ((board[j][i] == 'X') || (board[j][i] == 'T')) sum1++;
	        }
	        if ((board[i][i] == 'X') || (board[i][i] == 'T')) sum2++;
	        if ((board[i][3-i] == 'X') || (board[i][3-i] == 'T')) sum3++;

            if (sum1 == 4) win = 1;
            if (sum == 4) win = 1;
            if (sum2 == 4) win = 1;
            if (sum3 == 4) win = 1;
	    }

	    if (win)
	    {
	        out<<"Case #"<<ii<<": X won"<<endl;
	        continue;
	    }
        sum2 = 0; sum3 = 0;
	    for (int i = 0; i < 4; i++)
	    {
	        int sum = 0,sum1 = 0;
	        for (int j = 0; j < 4; j++)
	        {
	            if ((board[i][j] == 'O') || (board[i][j] == 'T')) sum++;
	            if ((board[j][i] == 'O') || (board[j][i] == 'T')) sum1++;
	        }
	        if ((board[i][i] == 'O') || (board[i][i] == 'T')) sum2++;
	        if ((board[i][3-i] == 'O') || (board[i][3-i] == 'T')) sum3++;
            //cout<<ii<<" "<<(board[i][i] == 'O')<<" "<<sum2<<endl;
            if (sum1 == 4) win = 1;
            if (sum == 4) win = 1;
            if (sum2 == 4) win = 1;
            if (sum3 == 4) win = 1;
	    }

	    if (win)
	    {
	        out<<"Case #"<<ii<<": O won"<<endl;
	        continue;
	    }

        if (cnt == 16) out<<"Case #"<<ii<<": Draw"<<endl;
	    else out<<"Case #"<<ii<<": Game has not completed"<<endl;
	    string s;
        if (ii < t) getline(inp,s);
	}

    out.close();

	return 0;
}
