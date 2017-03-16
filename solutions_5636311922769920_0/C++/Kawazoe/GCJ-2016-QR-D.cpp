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

s64 K, C, S;

void Smart()
{
}

void Naive()
{
	if (C * S < K) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vector<s64> s;
	FOR(i, 0, K) {
		s.push_back(i);
	}
	while (s.size() < K*C) s.push_back(0);
	for (s32 i = 0; i < K; i+=C) {
		s64 a = 0;
		FOR (j,i,i+C) a = K*a + s[j];
		cout << a + 1 << " ";
	}
	cout << endl;
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
	K = 92, C = 5, S = 92;	Naive();

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cin >> K >> C >> S;
		cout << "Case #" << tt+1 << ": ";
		Naive();
	}

	return 0;
}
