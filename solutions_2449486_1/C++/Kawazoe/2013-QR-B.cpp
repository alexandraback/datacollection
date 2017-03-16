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

#define L 120
s32 f[L][L];
s32 N,M;

void Smart()
{
}

void Print()
{
    FOR (i,0,N) {
        FOR (j,0,M) cout << f[i][j];
        cout << endl;
    }
    cout << endl;
}

void Naive()
{
    bool all;
    cin >> N >> M;
    FOR (i,0,N) FOR (j,0,M) cin >> f[i][j];
    FOR (a,1,101) {
        FOR (i,0,N) {
            all=true;
            FOR (j,0,M) {
                if (!(f[i][j]==a || f[i][j]==0)) all=false;
            }
            if (all) {
                FOR (j,0,M) f[i][j] = 0;
            }
//            Print();
        }
        FOR (i,0,M) {
            all=true;
            FOR (j,0,N) {
                if (!(f[j][i]==a || f[j][i]==0)) all=false;
            }
            if (all) {
                FOR (j,0,N) f[j][i] = 0;
            }
  //          Print();
        }
        FOR (i,0,N) FOR (j,0,M) if (f[i][j]==a) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
		Naive();
		cout << endl;
	}

	return 0;
}
