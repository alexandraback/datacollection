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
s32 K, L, S;
string k, l;

void Smart()
{
	map<char, s32> e;
	FOR(i, 0, K) e[k[i]] ++;

	FOR(i, 0, L) {
		if (e.find(l[i]) == e.end()) {
			cout << "0";
			return;
		}
	}

	double d = 1;
	FOR(i, 0, L) d *= (double)e[l[i]] / K;
	d *= S - L + 1;

	s32 q = L;
	FOR(i, 1, L) {
		string s1 = l.substr(0, i);
		string s2 = l.substr(L-i);
		if (s1 == s2) q = L - i;
	}
	double f = (S - L + q) / q;
	cout << f - d;
}

s64 t, t0_max;
void Next(s32 i, string &s) {
	if (i == S) {
		s64 t0 = 0;
		string::size_type j = 0;
		while (true) {
			j = s.find(l, j);
			if (j == string::npos) {
				break;
			}
			t0++;
			j++;
		}
		if (t0 > t0_max) t0_max = t0;
		t += t0;
	}
	else {
		FOR(j, 0, K) {
			s += k[j];
			Next(i + 1, s);
			s = s.substr(0, s.size() - 1);
		}
	}
}

s64 Pow(s64 a, s64 b) {
	s64 r = 1;
	FOR(i, 0, b) r *= a;
	return r;
}

void Naive()
{
	t = t0_max = 0;
	string s;
	Next(0, s);
	s64 p = Pow(K, S);
	double a = t0_max - (double)t / p;
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
		cin >> K >> L >> S >> k >> l;
		Smart();
		//cout << " ";
		//Naive();
		cout << endl;
	}

	return 0;
}
