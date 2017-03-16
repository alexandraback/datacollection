
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

int T, N, S, P, t;

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "B"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2012\\QualificationRound\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
//	ifstream in(FOLDER(TASK_NAME("-large.in")));
//	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	FORI(ncase, T) {
		in >> N >> S >> P;
		int n1 = 0;
		int n2 = 0;
		int p1 = P+(P-1)+(P-1);
		if(P == 0) p1 = 0;
		int p2 = P+(P-2)+(P-2);
		if(P == 0) p2 = 0;
		if(P == 1) p2 = 1;
		FORI(i, N) {
			in >> t;
			if(t >= p1)
				n1++;
			else if(t >= p2)
				n2++;
		}
		int res = n1;
		if(S >= n2)
			res += n2;
		else 
			res += S;
		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
