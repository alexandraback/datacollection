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
	double d;
	int n, m;
	ifs >> d >> n >> m;

	VD t(n, 0), x(n, 0), v(n, 0);
	REP(i, n) {
		ifs >> t[i] >> x[i];
		if (i)
			v[i] = (x[i] - x[i-1]) / (t[i] - t[i-1]);
		else
			v[i] = 1E+100;
	}

	ofs << "Case #" << tst+1 << ": " << endl;

	VD b(n, 0);
	REP(kt, m) {
		double a;
		ifs >> a;

		double l = 0;
		double r = 1E+8;

		while (r - l > 1E-8) {
			double m = (r+l) / 2;
			bool ok = true;
			REP(i, n)
				if (x[i] > d - 1E-10) {
					if (i > 0) {
						double nt = (d - x[i-1]) / v[i] + t[i-1];
						if (nt > m) {
							double nx = a * (nt - m) * (nt - m) / 2;
							if (nx > d + 1E-9) {
								ok = false;
								break;
							}
						}
					}
				} else {
					if (t[i] > m) {
						double nx = a * (t[i] - m) * (t[i] - m) / 2;
						if (nx > x[i] + 1E-9) {
							ok = false;
							break;
						}
					}
				}
			if (ok)
				r = m;
			else
				l = m;
		}

		double m = (r+l)/2;

		char buf[100];
		sprintf(buf, "%.8f", sqrt(2*d/a) + m);
		ofs << buf << endl; 
	}
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
