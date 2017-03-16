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

s64 C, D, V;
vector<s64> P;

void Smart()
{
}

void Fill(vector<bool> &b) {
	s32 d = P.size();
	for (s64 i = 0; i < (1LL << d); i++) {
		s64 c = 0;
		FOR(j, 0, d) {
			if (i & (1LL << j)) c += P[j];
		}
		if (c <= V) b[c] = true;
	}
}

void Naive()
{
	vector<bool> b(V + 1);
	for (s32 k=0; ; k++) {
		Fill(b);
		s32 p = 0;
		bool ok = true;
		FOR(i, 1, V+1) {
			if (!b[i]) {
				p = i;
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << k;
			break;
		}
		P.push_back(p);
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
		P.clear();
		cin >> C >> D >> V;
		P.assign(D, 0);
		FOR(i, 0, D) cin >> P[i];
		cout << "Case #" << tt+1 << ": ";
		Naive();
		cout << endl;
	}

	return 0;
}
