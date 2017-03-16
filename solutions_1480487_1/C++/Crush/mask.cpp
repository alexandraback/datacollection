#pragma warning(disable:4786)

#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <sstream>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
typedef pair<int,int> PII;
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz size()

ifstream ifs;
ofstream ofs;

typedef long long ll;

void testcase(int tst)
{
	int n;
	ifs >> n;
	
	VI a(n, 0);
	int x = 0;
	REP(i, n) {
		ifs >> a[i];
		x += a[i];
	}

	ofs << "Case #" << tst+1 << ": ";

	REP(i, n) {

		double l = 0;
		double r = 1;

		while (r - l > 1E-9) {
			double m = (r + l) / 2;

			bool can = true;
			double c = a[i] + x * m;
			double s = 0;
			REP(j, n) {
				double z = (c - a[j])/x;
				if (z < 0) z = 0;
				if (z > 1) {
					can = false;
					break;
				}
				s += z;
			}

			if (can) {
				if (s < 1+1E-10)
					can = true;
				else
					can = false;
			}

			if (!can)
				r = m;
			else
				l = m;
		}
		if (i) ofs << ' ';
		char buf[100];
		sprintf(buf, "%.6f", (r+l)/2*100);
		ofs << buf;
	}

	ofs << endl;

}

int main()
{
	ifs.open("input.txt");
	ofs.open("output.txt");
	
	int t;
	ifs >> t;
	REP(tn, t)
	{
		testcase(tn);
	}

	return 0;
} 
