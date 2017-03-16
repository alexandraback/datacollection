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
s64 N, X, Y;

void Smart()
{
}

#define M 100 
s32 h[M][M];
double p[M][M];

#define H(x,y) h[x+M/2][y+2]
#define P(x,y) p[x+M/2][y+2]
vector<pair<s32,s32>> r;

void Next(s32 n, s32 x, s32 y, double q)
{
    if (n == N) return;
    for (;;y+=2) {
        if (!H(x,y)) break;
    }
    while (true) {
        s32 b1 = H(x+1,y-1);
        s32 b2 = H(x-1,y-1);
        if (b1 && b2) {
            r.push_back(pair<s32,s32>(x,y));
            H(x,y) = 1;
            P(x,y) += q;
            Next(n+1, 0, 0, q);
            H(r.back().first,r.back().second) = 0;
            r.pop_back();
            break;
        } else if (b1) {
            x --;   y --;
            continue;
        } else if (b2) {
            x ++;   y --;
            continue;
        } else {
            Next(n, x-1, y-1, 0.5*q);
            Next(n, x+1, y-1, 0.5*q);
            break;
        }
    }
}

void Naive()
{
    r.clear();
    FOR (i,0,M) FOR (j,0,M) h[i][j]=p[i][j]=0;
    FOR (i,-M/2,M/2) H(i,-1) = H(i,-2) = 1;
    Next(0,0,0,1.0);
    if (X+M/2<0 || X+M/2>=M || Y+2<0 || Y+2>=M) cout << 0;
    else cout << P(X,Y);
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
		cout << "Case #" << tt+1 << ": ";
        cin >> N >> X >> Y;
		Naive();
		cout << endl;
	}

	return 0;
}
