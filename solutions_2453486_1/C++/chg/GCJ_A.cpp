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

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl


const int N = 10;
char tab[N][N];

bool check(char who) {
	int xpos[10][4];
	int ypos[10][4];
	int cnt = 0;
	forn (i, 4) {
		forn (j, 4) {
			xpos[cnt][j] = i;
			ypos[cnt][j] = j;
		}
		cnt++;

		forn (j, 4) {
			xpos[cnt][j] = j;
			ypos[cnt][j] = i;
		}
		cnt++;
	}

	forn (i, 4) {
		xpos[cnt][i] = i;
		ypos[cnt][i] = i;
	}
	cnt++;
	forn (i, 4) {
		xpos[cnt][i] = i;
		ypos[cnt][i] = 3 - i;
	}
	cnt++;

	forn (i, cnt) {
		bool flag = true;
		forn (j, 4) {
			int x = xpos[i][j];
			int y = ypos[i][j];
			if (tab[x][y] != who && tab[x][y] != 'T') {
				flag = false;
				break;
			}
		}
		if (flag) {
			return true;
		}
	}

	return false;
}

void solve() {
	forn (i, 4) scanf("%s", tab[i]);
	if (check('X')) {
		puts("X won");
		return;
	}
	if (check('O')) {
		puts("O won");
		return;
	}
	forn (i, 4) forn (j, 4)
		if (tab[i][j] == '.') {
			puts("Game has not completed");
			return;
		}
	puts("Draw");
}

int main() {
//	freopen("in.txt","r",stdin);
//	freopen("D:\\in.txt","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
