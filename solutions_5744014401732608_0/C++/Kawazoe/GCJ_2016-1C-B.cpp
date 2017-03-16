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

s32 B, M;

string answer[10][30];
s64 Smart()
{
	if (answer[B][M] == "") {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << "POSSIBLE" << endl;
		cout << answer[B][M];
	}
	return 0;
}

bool Loop(vector<vector<s32>> &m) {
	vector<vector<s32>> p = m;
	for (s32 t = 0; t < 100000; t++) {
		vector<vector<s32>> q;
		FOR(i, 0, B) {
			vector<s32> l;
			FOR(j, 0, B) l.push_back(0);
			q.push_back(l);
		}
		FOR(i, 0, B) FOR(j, 0, B) {
			FOR(k, 0, B) q[i][j] += p[i][k] * m[k][j];
		}
		bool ok = true;
		FOR(i, 0, B) FOR(j, 0, B) {
			if (q[i][j] != 0) ok = false;
		}
		if (ok) return true;
		p = q;
	}
	return false;
}

void Init() {
	ifstream ans;
	ans.open("answer.txt");
	if (ans.fail()) {
		return;
	}
	s32 tmp1, tmp2, ok;
	FOR(b, 2, 7) FOR(m,1,21) {
		ans >> tmp1 >> tmp2 >> ok;
		string t;
		if (ok) {
			string s;
			FOR(i, 0, b) {
				ans >> s;
				t += s + "\n";
			}
		}
		answer[b][m] = t;
	}
	ans.close();
}

s64 Naive()
{
	cout << B << " " << M << endl;
	vector<vector<s32>> m;
	for (s32 t = 0; t < 10000; t++) {
		m.clear();
		FOR(i, 0, B) {
			vector<s32> l;
			if (i == B - 1) {
				FOR(j, 0, B) l.push_back(0);
			}
			else {
				l.push_back(0);
				FOR(j, 1, B) {
					if (i == j) l.push_back(0);
					else l.push_back(rand() % 2);
				}
			}
			m.push_back(l);
		}
		if (!Loop(m)) continue;

		vector<s32> v(B), v_new(B);
		v[0] = 1;
		s32 a = 0;
		while (true) {
			v_new.assign(B, 0);
			FOR(i, 0, B) {
				FOR(j, 0, B) {
					v_new[i] += m[j][i] * v[j];
				}
			}
			a += v_new[B - 1];
			v_new[B - 1] = 0;
			bool end = true;
			FOR(i, 0, B) {
				if (v_new[i] > 0) end = false;
			}
			if (end) break;
			if (a > M) break;
			v.swap(v_new);
		}
		if (a == M) {
			cout << 1 << endl;
			FOR(i, 0, B) {
				FOR(j, 0, B) cout << m[i][j];
				cout << endl;
			}
			return 0;
		}
	}
	cout << 0 << endl;

	return 0;
}

void Pre() {
	B = 6;
	M = 15;
	Naive();
	return;
	for (B = 2; B <= 6; B++) {
		for (M = 1; M <= 20; M++) {
			Naive();
		}
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

	//Pre();
	//return 0;
	Init();

	s32 num_of_trial;
	cin >> num_of_trial;
	FOR (tt,0,num_of_trial) {
		cout << "Case #" << tt+1 << ": ";
		cin >> B >> M;
		s64 ans = Smart();
	}

	return 0;
}
