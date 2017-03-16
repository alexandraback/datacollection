
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

int T, N;
LL mul10[20] = {1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL, 100000000000LL, 1000000000000LL, 10000000000000LL, 100000000000000LL, 1000000000000000LL, 10000000000000000LL, 100000000000000000LL, 1000000000000000000LL, 10000000000000000000LL};
int d[20];

VL fair;

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "C"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\QualificationRound\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
//	ifstream in(FOLDER(TASK_NAME("-large.in")));
//	ofstream out(FOLDER(TASK_NAME("-large.out")));


		for(LL a = 1; ; a++) {
			int n;
			for(n = 0; n < 20; n++) {
				if(mul10[n] <= a)
					d[n] = (int)((a / mul10[n])%10LL);
				else
					break;
			}
			LL x1 = 0, x2 = 0;
			FORI(i, n) {
				x1 += mul10[n-i-1] * d[i];
				if(i > 0)
					x1 += mul10[n+i-1] * d[i];

				x2 += mul10[n-i-1] * d[i] + mul10[n+i] * d[i];
			}

			x1 = x1*x1;
			x2 = x2*x2;

			for(n = 0; n < 20; n++) {
				if(mul10[n] <= x1)
					d[n] = (int)((x1 / mul10[n])%10LL);
				else
					break;
			}
			int p = 1;
			FORI(i, n)
				if(d[i] != d[n-i-1])
					p = 0;

			if(p) {
				fair.PB(x1);
			}

			for(n = 0; n < 20; n++) {
				if(mul10[n] <= x2)
					d[n] = (int)((x2 / mul10[n])%10LL);
				else
					break;
			}
			p = 1;
			FORI(i, n)
				if(d[i] != d[n-i-1])
					p = 0;

			if(p) {
				fair.PB(x2);
			}

			if(x1 > 100000000000000LL)
				break;
		}

	LL A, B;
	in >> T;
	FORI(ncase, T) {
		in >> A >> B;
		
		LL res = 0;
		FORE(it, fair, VL) {
			if(*it >= A && *it <= B)
				res++;
		}

		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
