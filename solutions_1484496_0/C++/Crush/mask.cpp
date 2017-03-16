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

int s[3000000];

void testcase(int tst)
{
	int n;
	ifs >> n;
	VI a(n, 0);
	REP(i, n)
		ifs >> a[i];

	memset(s, -1, sizeof(s));

	ofs << "Case #" << tst+1 << ": " << endl;
	REP(m, 1 << n) {
		int c = 0;
		REP(i, n)
			if ((m & (1<<i)) > 0)
				c += a[i];
		if (s[c] != -1) {
			int first = true;
			REP(i, n)
				if ((m & (1<<i)) > 0) {
					if (!first)
						ofs << ' ';
					first = false;
					ofs << a[i];
				}
			ofs << endl;
			first = true;
			REP(i, n)
				if ((s[c] & (1<<i)) > 0) {
					if (!first)
						ofs << ' ';
					first = false;
					ofs << a[i];
				}
			ofs << endl;
			return;
		} else
			s[c] = m;
	}
	ofs << "Impossible" << endl;

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
