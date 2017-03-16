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

s64 L = 1000000;
s64 N;
map<s64, s64> m;

void Smart()
{
}

s64 Reverse(s64 k) {
	s64 r = 0;
	while (k > 0) {
		r = 10 * r + k % 10;
		k /= 10;
	}
	return r;
}

void Put(s64 k, s64 c, vector<s64> &v_new) {
	if (k > L) return;
	map<s64, s64>::iterator j = m.find(k);
	if (j == m.end()) {
		m[k] = c;
		v_new.push_back(k);
	}
}

void Prepare()
{
	m[1] = 1;
	vector<s64> v, v_new;
	v.push_back(1);
	s32 c = 2;
	while (!v.empty()) {
		for (s32 i = 0; i < v.size(); i++) {
			Put(v[i] + 1, c, v_new);
			Put(Reverse(v[i]), c, v_new);
		}
		c++;
		v.swap(v_new);
		v_new.clear();
	}
}

void Naive()
{
	s64 a = m[N];
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

	Prepare();

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cout << "Case #" << tt+1 << ": ";
		cin >> N;
		Naive();
		cout << endl;
	}

	return 0;
}
