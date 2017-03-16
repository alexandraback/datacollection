
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


typedef unsigned long long LL;
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

LL T, r, t;

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "A"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\Round1A\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
//	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
//	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
	ifstream in(FOLDER(TASK_NAME("-large.in")));
	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	FORI(ncase, T) {
		in >> r >> t;

		double rr = r, tt = t;

		double l = 1, h = 1e10;

		while (fabs(l-h) > 1e-2) {
			double m = (h+l)/2.;
			
			double k = (2*rr + 2*m -1)*m;
			if(k > t)
				h = m;
			else
				l = m;
		}

		LL res = (LL)((h+l)/2.);
		while(true) {
			LL d = (2*r + 2*res - 1)*res;
			LL d2 = (2*r + 2*(res+1) - 1)*(res+1);
			if(d > t)
				res--;
			else if(d2 > t)
				break;
			else 
				res++;
		}

		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
