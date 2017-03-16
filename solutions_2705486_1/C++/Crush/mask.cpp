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

int v;
map<string,vector<string> > a[11];

int n;
string s;

int was[5000][6];

int go(int i, int c) {
	if (i >= s.sz)
		return 0;

	int& res = was[i][c];
	if (res >- 1)
		return res;

	res = 10000;


	for (int l = 1; l < 11; l++) {
		if (i + l <= s.sz) {
			int k = min(l, 5);
			REP(j, k) {
				string sn = s.substr(i, k);
//				if (c + j >= 5)
					for (char ch = 'a'; ch <= 'z'; ch++) {
						sn[j] = ch;
						if (a[l].find(sn) != a[l].end()) {
							VS t = a[l][sn];
							REP(o, t.sz) {
								string st = t[o];
								VI inds;
								REP(r, l) {
									if (s[i+r] != st[r]) {
										inds.pb(r);
									}
								}
								bool ok = true;
								if (inds.sz > 0) {
									REP(r, inds.sz - 1) {
										if (inds[r+1] - inds[r] < 5) {
											ok = false;
											break;
										}
									}
								}
								if (!ok) continue;

								int cn;
								if (inds.sz == 0) {
									cn = c + l;
								} else {
									cn = l - inds[inds.sz - 1];
								}
								cn = min(cn, 5);
								if (inds.sz == 0 || inds[0] + c >= 5) {
									res = min(res, go(i + l, cn) + (int)inds.sz);
								}
							}
						}

					}
			}
		}
	}
	return res;
}

void testcase(int tst)
{
	ifs >> s;
	n = s.sz;

	memset(was, -1, sizeof(was));

	ofs << "Case #" << tst+1 << ": " << go(0, 5) << endl;
}

int main()
{
	ifs.open("input.txt");
	ofs.open("output.txt");
	
	ifs >> v;
	REP(i, v) {
		string s;
		ifs >> s;
		
		if (s.length() > 5) {
			string sl = s.substr(0, 5);
			a[s.length()][s.substr(0, 5)].pb(s);
		} else {
			a[s.length()][s].pb(s);
		}
	}

	int t;
	ifs >> t;
	REP(tn, t)
	{
		testcase(tn);
	}

	return 0;
} 
