#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
#define REP(a,b) for(int a=0;a<(b);++a)
#define FOR(a,c,b) for(int a=c;a<(b);++a) 

int s[300];
int sum, n;

bool check(int id, double val)
{
	double mypoints = s[id] + val*sum;
	double left = 1-val;

	REP(i,n) if (i != id) {
		if (s[i] < mypoints) {
			double req = (mypoints-s[i])/sum;
			if (req-1e-12 > left) return true;
			else left -= req;
		}
	}

	return false;
}

int main() 
{
	ifstream fin("A-large.in");
	//ifstream fin("A.in");
	ofstream fout("a.out");

	int tc;

	fin >> tc;

	REP(tcase,tc) {
		fin >> n;

		sum = 0;
		REP(i,n) {
			fin >> s[i];
			sum += s[i];
		}

		fout << "Case #" << tcase+1 << ":";

		fout.precision(14);
		REP(i,n) {
			double res, lo = 0, hi = 1, mid;

			while (hi-lo > 1e-14) {
				mid = (hi+lo)/2;
				if (check(i, mid)) hi = mid;
				else lo = mid;
			}

			res = mid*100;

			fout << " " << res;
		}

		fout << endl;
	}

	fout.close();

	return 0;
}