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
#define M 300

s32 N, X;
s32 s[M];

void Smart()
{
}

double Get(s32 i, double p)
{
	double q=p;
	FOR (j,0,N) {
		if (j==i) continue;
		q += max(0, (s[i]+X*p-s[j])/X);
	}
	return q;
}

void Naive()
{
	double p, m;
	X=0;
	cin >> N;
	FOR (i,0,N) cin >> s[i];
	FOR (i,0,N) X+=s[i];
	FOR (i,0,N) {
		double l=0, r=1;
		while (true) {
			m=0.5*(l+r);
			p=Get(i, m);
			if (fabs(p-1.0)<1.0e-10) break;
			if (p>1.0) r=m;
			else l=m;
			if (m<1.0e-8) break;
		}
		if (m<1.0e-8) m=0;
		cout << 100*m << " ";
	}
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
