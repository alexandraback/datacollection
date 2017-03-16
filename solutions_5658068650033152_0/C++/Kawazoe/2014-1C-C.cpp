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

s32 N, M, K;

void Smart()
{
}

void Naive()
{
    s32 s[6][7][21];

    s[3][3][8]=7;
    s[3][3][9]=8;

    s[3][4][8]=6;
    s[3][4][9]=7;
    s[3][4][10]=8;
    s[3][4][11]=9;
    s[3][4][12]=10;

    s[3][5][8]=6;
    s[3][5][9]=7;
    s[3][5][10]=8;
    s[3][5][11]=8;
    s[3][5][12]=9;
    s[3][5][13]=10;
    s[3][5][14]=11;
    s[3][5][15]=12;

    s[3][6][8]=6;
    s[3][6][9]=7;
    s[3][6][10]=8;
    s[3][6][11]=8;
    s[3][6][12]=9;
    s[3][6][13]=10;
    s[3][6][14]=10;
    s[3][6][15]=11;
    s[3][6][16]=12;
    s[3][6][17]=13;
    s[3][6][18]=14;

    s[4][4][8]=6;
    s[4][4][9]=7;
    s[4][4][10]=7;
    s[4][4][11]=8;
    s[4][4][12]=8;
    s[4][4][13]=9;
    s[4][4][14]=10;
    s[4][4][15]=11;
    s[4][4][16]=12;

    s[4][5][8]=6;
    s[4][5][9]=7;
    s[4][5][10]=7;
    s[4][5][11]=8;
    s[4][5][12]=8;
    s[4][5][13]=9;
    s[4][5][14]=9;
    s[4][5][15]=10;
    s[4][5][16]=10;
    s[4][5][17]=11;
    s[4][5][18]=12;
    s[4][5][19]=13;
    s[4][5][20]=14;

    if (N>M) {
        s32 tmp = N;
        N = M;
        M = tmp;
    }
    s32 r=0;
    if (N==1 || N==2) {
        r = K;
    } else if (K<=4) r = K;
    else if (K==5) r = 4;
    else if (K==6) r = 5;
    else if (K==7) r = 6;
    else r = s[N][M][K];

    cout << r;
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
        cin >> N >> M >> K;
		Naive();
		cout << endl;
	}

	return 0;
}
