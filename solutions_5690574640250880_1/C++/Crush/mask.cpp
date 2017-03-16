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
	int r, c, m;
	ifs >> r >> c >> m;

	if (c == 1 || r == 1) {
		if (c == 1) {
			ofs << "Case #" << tst+1 << ": " << endl;
			ofs << "c" << endl;
			REP(i, r - m - 1) ofs << "." << endl;
			REP(i, m) ofs << "*" << endl;
		} else {
			ofs << "Case #" << tst+1 << ": " << endl;
			ofs << "c";
			REP(i, c - m - 1) ofs << ".";
			REP(i, m) ofs << "*";
			ofs << endl;
		}
	} else {
		if (m == r*c - 1) {
			ofs << "Case #" << tst+1 << ": " << endl;
			REP(j, r) {
				REP(i, c) if (j == 0 && i == 0) ofs << 'c'; else ofs << '*';
				ofs << endl;
			}
		} else {
			int left = r*c - m;
			for (int y = 2; y <= r; y++)
				for (int x = 2; x <= c; x++) {
					int mn = x * 2 + y * 2 - 4;
					int mx = x*y;
					if (left >= mn && left <= mx) {
						ofs << "Case #" << tst+1 << ": " << endl;
						VVI a(r, VI(c, 0));
						REP(i, x) {
							a[0][i] = 1;
							a[1][i] = 1;
						}
						REP(j, y) {
							a[j][0] = 1;
							a[j][1] = 1;
						}
						left -= mn;
						for (int j = 2; j < y; j++) {
							if (left == 0) break;
							for (int i = 2; i < x; i++) {
								a[j][i] = 1;
								left--;
								if (left == 0) break;
							}
						}

						REP(j, r) {
							REP(i, c) {
								if (j == 0 && i == 0) 
									ofs << 'c'; 
								else if (a[j][i] == 1) ofs << '.'; else ofs << '*';
							}
							ofs << endl;
						}
						return;
					}
				}
			ofs << "Case #" << tst+1 << ": " << endl << "Impossible" << endl;
		}
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
