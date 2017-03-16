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

const char probname = 'B';
const bool largeset = false;
const char* suffix = "-attempt1";
//const char* suffix = "";

int main() {
	char buffer[1234];
	sprintf(buffer, "%c-%s%s.in", probname, largeset ? "large" : "small", suffix);
	ifstream fin(buffer);
	sprintf(buffer, "%c-%s%s.out", probname, largeset ? "large" : "small", suffix);
	ofstream fout(buffer);

	int testCases;
	fin >> testCases;

	int n, s, p;
	REP(testCase, testCases) {
		fin >> n >> s >> p;
		int k;
		int cnt = 0;
		REP(i, n) {
			fin >> k;
			bool found = false;
			int a = k/3;

			//3a -     a,   a, a
			//       a-1,   a, a+1
			//3a + 1   a,   a, a+1
			//       a-1, a+1, a+1
			//3a + 2   a, a+1, a+1
			//         a,   a, a+2

			if (k % 3 == 0) found = a >= p;
			else found = (a + 1) >= p;
			if (found) cnt++;

			if (!found) {
				if ((((k % 3 == 2) && (a + 2) >= p && a <= 8) ||
					((k % 3 == 0) && (a + 1) >= p && a >= 1 && a <= 9)) && s > 0) {
					s--; cnt++;
				}
			}
		}
		fout << "Case #" << testCase + 1 << ": " << cnt << endl;
	}

	fin.close();
	fout.close();
}
