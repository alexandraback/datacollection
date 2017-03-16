
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

#define NUM 101

int T, N, M;
int field[120][120];
int mx[120], my[120];

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "B"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\QualificationRound\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
//	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
//	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
	ifstream in(FOLDER(TASK_NAME("-large.in")));
	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	FORI(ncase, T) {
		in >> N >> M;
		FORI(i, N) FORI(j, M) in >> field[i][j];

		CLEAR(mx, 0);
		CLEAR(my, 0);

		FORI(i, N) FORI(j, M) {
			mx[i] = max(mx[i], field[i][j]);
			my[j] = max(my[j], field[i][j]);
		}

		string res = "YES";
		FORI(i, N) FORI(j, M) {
			if(field[i][j] < mx[i] && field[i][j] < my[j])
				res = "NO";
		}

		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
