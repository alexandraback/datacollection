
#include <stdio.h>
#include <time.h>

#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <numeric>
#include <complex>

using namespace std;


typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;
#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a, n) memset(a, n, sizeof(a))
#define PB(n) push_back(n)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()

#define NUM 10005

LL T, N, E, R;
LL v[NUM];
LL n[NUM];

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "B"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\Round1A\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
//	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
//	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
	ifstream in(FOLDER(TASK_NAME("-large.in")));
	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	FORI(ncase, T) {
		in >> E >> R >> N;
		FORI(i, N)
			in >> v[i];

		CLEAR(n, -1);

		FORI(i, N) {
			FORIS(j, i+1, N) {
				if(v[j] >= v[i]) {
					n[i] = j-i;
					break;
				}
			}
		}

		LL res = 0;
		LL en = E;
		FORI(i, N) {
			if(n[i] == -1) {
				res += en * v[i];
				en = 0;
			} else {
				LL mx = en + R*n[i];
				if(mx > E) {
					LL s = min(mx - E, en);
					res += s * v[i];
					en -= s;
				}
			}
			en += R;
			if(en > E) en = E;
		}

		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
