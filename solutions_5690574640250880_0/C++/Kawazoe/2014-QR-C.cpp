#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "windows.h"
//#include "../../gmp_int.h"
//#include "../../common.h"
#define MAX(a, b)		((a)>(b)?(a):(b))
#define MAX3(a, b, c)	(MAX((a),MAX((b),(c))))
#define FOR(a,b,c)		for (s32(a)=(b);(a)<(s32)(c);(a)++)
#define BL				{char bl[10];cin.getline(bl, 10);}
#define GL(c)			cin.getline(c, sizeof(c))
typedef char					s8;
typedef unsigned char			u8;
typedef short					s16;
typedef unsigned short			u16;
typedef int						s32;
typedef unsigned int			u32;
typedef long long int			s64;
typedef unsigned long long int	u64;
using namespace std;

ifstream test_input;
#define cin test_input

s32 R,C,M, f[5][5], e[5][5];

void Smart()
{
}


s32 Num(s32 i, s32 j) {
    s32 c=0;
    if (i>0) {
        if (j>0) c += f[i-1][j-1];
        c += f[i-1][j];
        if (j<C-1) c += f[i-1][j+1];
    }
    if (i<R-1) {
        if (j>0) c += f[i+1][j-1];
        c += f[i+1][j];
        if (j<C-1) c += f[i+1][j+1];
    }
    if (j>0) c += f[i][j-1];
    if (j<C-1) c += f[i][j+1];
    return c;
}

void Print() {
    cout << endl;
    FOR (i,0,R) {
        FOR (j,0,C) {
            if (f[i][j]==1) cout << "*";
            else cout << Num(i,j);
        }
        cout << endl;
    }
    cout << endl;
}

void Do(s32 i, s32 j) {
    if (i<0 || i>=R || j<0 || j>=C) return;
    if (e[i][j]==1) return;
    if (f[i][j]==1) return;
    e[i][j]=1;
    if (Num(i, j) == 0) {
        Do(i-1, j-1);
        Do(i-1, j);
        Do(i-1, j+1);
        Do(i, j-1);
        Do(i, j+1);
        Do(i+1, j-1);
        Do(i+1, j);
        Do(i+1, j+1);
    }
}

bool Ok() {
    FOR (i,0,R) FOR (j,0,C) {
        if (f[i][j]==0 && e[i][j]==0) return false;
    }
    return true;
}

void Output(s32 x, s32 y) {
    cout << endl;
    FOR (i,0,R) {
        FOR (j,0,C) {
            if (f[i][j]==1) cout << "*";
            else if (i==x && j==y) cout << "c";
            else cout << ".";
        }
        cout << endl;
    }
}

bool Check() {
    FOR (i,0,R) FOR (j,0,C) {
        if (f[i][j]==1) continue;
        //if (Num(i,j)!=0) continue;
        memset(e,0,sizeof(s32)*5*5);
        Do(i, j);
        if (Ok()) {
            Output(i,j);
            return true;
        }
    }
    return false;
}

bool Next(s32 i, s32 j, s32 m) {
    if (m==0) {
        //Print();
        if (Check()) return true;
        return false;
    }
    if (i==R) return false;
    bool b;
    s32 i_next = j==C-1 ? i+1: i;
    s32 j_next = j==C-1 ? 0: j+1;
    f[i][j]=1;
    b = Next(i_next, j_next, m-1);
    if (b) return true;
    f[i][j]=0;
    b = Next(i_next, j_next, m);
    if (b) return true;
    return false;
}

void Naive()
{
    memset(f,0,sizeof(s32)*5*5);
    if (!Next(0,0,M)) cout << "Impossible";
}

int main(int argc, char* argv[])
{
	cout.precision(15);
	if (argc!=2) {
		cout << "Need input file name." << endl;
		return 0;
	}
	test_input.open(argv[1]);
	if (test_input.fail()) {
		cout << "Cannot open input file " << argv[1] << "." << endl;
		return 0;
	}

    s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
        cin >> R >> C >> M;
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
