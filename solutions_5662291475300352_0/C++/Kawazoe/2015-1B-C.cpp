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

s64 N, D[10], H[10], M[10];

void Smart()
{
}

void Swap(s64 &a, s64 &b) {
	s64 tmp = a;
	a = b;
	b = tmp;
}

void Naive()
{
	s64 d[10], m[10];
	s32 h = 0;
	FOR(i, 0, N) {
		FOR(j, 0, H[i]) {
			d[h] = D[i];
			m[h] = M[i] + j;
			h++;
		}
	}
	if (m[0] < m[1]) {
		Swap(m[0], m[1]);
		Swap(d[0], d[1]);
	}
	double t0 = (360.0 - d[0]) / 360.0 * m[0];
	double t1 = (720.0 - d[1]) / 360.0 * m[1];
	s32 a = (t1-t0 > 1.0e-9) ? 0 : 1;
	cout << a;
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
		cin >> N;
		FOR(i, 0, N) cin >> D[i] >> H[i] >> M[i];
		Naive();
		cout << endl;
	}

	return 0;
}
