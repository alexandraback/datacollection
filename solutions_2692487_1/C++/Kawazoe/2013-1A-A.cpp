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
#define RAND(a,b)		((a)+(s32)(rand()*((b)-(a)+1.0)/(1.0+RAND_MAX)))
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

s64 A, N, M[1000], INF=10000000000LL;

void Smart()
{
}

void Naive()
{
    sort(M, M+N);
    bool all=false;
    s64 a=A, c=0, cmin=INF;

    for (s32 i=0; i<N;) {
        if (a > M[i]) {
            a += M[i];
            i ++;
        } else {
            if (a == 1) {
                all=true;
                break;
            }
            // Removeしたときのコストは？
            cmin = min(cmin, c+N-i);
            // Addしてみる
            c ++;
            a += a-1;
        }
    }
    if (all) cout << N;
    else if (cmin == INF) cout << 0;
    else cout << min(cmin,c);
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

	s32 num_of_trial = 100;
	cin >> num_of_trial;

	FOR (tt,0,num_of_trial) {
        cin >> A >> N;
        FOR (i,0,N) cin >> M[i];
        //A = RAND(1,100);
        //N = RAND(1,10);
        //FOR (i,0,N) M[i] = RAND(1,100);
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
