#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
#include <stack>
#include <list>
#include <cstring>
#include <fstream>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define REP(i,e) for (int i = 0; i < int(e); ++i)
#define MAX(a,b) ((a) > (b) ? (a):(b))
#define MIN(a,b) ((a) < (b) ? (a):(b))
#define SQR(a) ((a)*(a))

const char probname = 'C';
const bool largeset = true;
const char* suffix = "";

typedef unsigned long long t_ull;

int main() {
	char buffer[1234];
	sprintf(buffer, "%c-%s%s.in", probname, largeset ? "large" : "small", suffix);
	ifstream fin(buffer);
	sprintf(buffer, "%c-%s%s.out", probname, largeset ? "large" : "small", suffix);
	ofstream fout(buffer);

	int testCases;
	fin >> testCases;

	int a, b;
	bool* mem = new bool[2000001];

	REP(testCase, testCases) {
		memset(mem, 0, sizeof(bool)*2000001);
		fin >> a >> b;

		int dg = 0; t_ull pw = 1; int tmp = a;
		while (tmp) {tmp /= 10; pw *= 10; dg++;};

		t_ull res = 0;
		FOR(k, a, b) {
			if (k >= pw) {dg++; pw *= 10;};

			if (!mem[k]) {
				set <t_ull> nm;
				t_ull t = k;
				nm.insert(t);
				mem[k] = true;

				t = t*pw + t;
				t_ull dv = 10;

				for (int shift = 1; shift < dg; ++shift) {
					t_ull s_nm = (t / dv) % pw;
					dv *= 10;
					if (pw/10 <= s_nm && a <= s_nm && s_nm <= b) {
						nm.insert(s_nm);
						mem[s_nm] = true;
					}
				}
				res += (nm.size() - 1)*nm.size()/2;
			}
		}

		fout << "Case #" << testCase + 1 << ": " << res << endl;
	}

	fin.close();
	fout.close();
}
