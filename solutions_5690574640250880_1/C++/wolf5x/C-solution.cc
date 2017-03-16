#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int T;
int R, C, M;

char g[50][51];

int main() {
	cin >> T;
	REP(_, T) {
		cin >> R >> C >> M;
		bool can = false;
		CLR(g);
		REP(i, R) REP(j, C) g[i][j] = '*';
		if (R*C-M == 1) {
			g[0][0] = 'c';
			can = true;
		} else if (R == 1) {
			REP(i, R*C-M)
				g[0][i] = '.';
			g[0][0] = 'c';
			can = true;
		} else if (C == 1) {
			REP(i, R*C-M)
				g[i][0] = '.';
			g[0][0] = 'c';
			can = true;
		} else {
			FOR(i, 2, R+1) {
				FOR(j, 2, C+1) {
					if (R*C-M <= i*j && R*C-M >= i*2+j*2-4) {
						can = true;
						REP(r, i) REP(c, j)
							g[r][c] = '.';
						g[0][0] = 'c';
						for(int has = i*j+M-R*C, x = i-1; has > 0; x--) {
							for (int y = j-1; has > 0 && y >= 2; y--) {
								g[x][y] = '*';
								has--;
							}
						}
					}
					if(can) break;
				}
				if(can) break;
			}
		}
		cout << "Case #" << _+1 << ":" << endl;
		if (can) {
			REP(i, R)
				cout << g[i] << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}



