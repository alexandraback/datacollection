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

s32 J, P, S, K;
s64 Smart()
{
	return 0;
}
vector<s32> Make(s32 j, s32 p, s32 s) {
	vector<s32> v;
	v.push_back(j);
	v.push_back(p);
	v.push_back(s);
	return v;
}

s64 Naive()
{
	map<vector<s32>, s32> x, y;
	vector<vector<s32>> a;
	for (s32 s = 1; s <= S; s++) {
		for (s32 p = 1; p <= P; p++) {
			for (s32 j = 1; j <= J; j++) {
				vector<s32> v = Make(j, p, s);
				if (x.find(v) != x.end()) {
					continue;
				}
				if (y[Make(j, p, 0)] == K) continue;
				if (y[Make(j, 0, s)] == K) continue;
				if (y[Make(0, p, s)] == K) continue;
				x[Make(j, p, s)] = 1;
				y[Make(j, p, 0)] ++;
				y[Make(j, 0, s)] ++;
				y[Make(0, p, s)] ++;
				a.push_back(Make(j, p, s));
			}
		}
	}
	cout << a.size() << endl;
	FOR(i, 0, a.size()) {
		FOR(j, 0, 3) cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
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
		cin >> J >> P >> S >> K;
		s64 ans = Naive();
	}

	return 0;
}
