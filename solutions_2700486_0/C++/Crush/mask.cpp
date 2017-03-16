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
	int n, x, y;
	ifs >> n;
	ifs >> x;
	ifs >> y;

	if (x < 0)
		x = -x;

	double res = 0.0;

	int c = 0;
	int d = 1;
	REP(i, n) {
		int j = i * 2;
		if (x + y == j) {
			int k = n - c;
			if (k >= d) {
				res = 1.0;
				break;
			}
			vector<VD> p(j+1, VD(j+1, 0));
			p[0][0] = 1.0;
			REP(l, j+1)
				REP(r, j+1) {
					if (l + r > k) break;
					if (l > 0) {
						if (r == j)
							p[l][r] += p[l-1][r];
						else
							p[l][r] += p[l-1][r] * 0.5;
					}
					if (r > 0) {
						if (l == j)
							p[l][r] += p[l][r-1];
						else
							p[l][r] += p[l][r-1] * 0.5;
					}

					if (r >= y+1 && l+r == k)
						res += p[l][r];
				}
		}
		c += d;
		d += 4;
		if (n <= c)
			break;
	}

	char buf[50];
	sprintf(buf, "%.9f", res);
	ofs << "Case #" << tst+1 << ": " << buf << endl;
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
