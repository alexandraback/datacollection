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
	int aa, n;
	ifs >> aa >> n;
	VI b(n, 0);
	REP(i, n)
		ifs >> b[i];

	sort(ALL(b));

	ll a = aa;

	int res = b.sz;
	int i = 0;
	int cnt = 0;
	while (true) {
		res = min(res, (int)(cnt + (b.sz - i)));
		if (i >= b.sz) {
			break;
		}
		if (a > b[i]) {
			a += b[i];
			i++;
		} else {
			if (a == 1) {
				break;
			}
			a += a-1;
			cnt++;
		}
	}

	ofs << "Case #" << tst+1 << ": " << res << endl;
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
