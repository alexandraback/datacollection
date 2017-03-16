#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define ms(a,x) memset(a,x,sizeof a)
#define ones(x) __builtin_popcount(x)
#define rep(i,n) for (int i = 0; i < n; i++)
#define forit(i,a) for (typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 201;
const int M = 100;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
const char dc[4] = {'E','W','N','S'};

char ch[M];
bool w[N][N][M];
int x[N*N*M], y[N*N*M], d[N*N*M], p[N*N*M], q[N*N*M];

inline bool ok(int x, int y, int d) {
	if ((abs(x) <= 100 && abs(y) <= 100 && d < M && !w[x+100][y+100][d])) {
		w[x+100][y+100][d] = 1;
		return 1;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	int tests;
	scanf("%d\n", &tests);

	for (int test = 1; test <= tests; test++) {
		int X, Y;
		scanf("%d%d", &X, &Y);
		
		x[0] = y[0] = d[0] = 0; q[0] = -1;

		ms(w, 0);
		w[100][100][0] = 1;

		int sz = 1;
		for (int i = 0; i < sz; i++) {
			int cx = x[i];
			int cy = y[i];
			int cd = d[i];
			if (cx == X && cy == Y) {
				//puts("Yes");
				int cur = i;
				int len = 0;
				while (q[cur] != -1) {
					int k = p[cur];
					ch[len++] = dc[k];
					cur = q[cur];
				}
				reverse(ch,ch+len); ch[len]=0;
				printf("Case #%d: %s\n", test, ch);
				break;
			}
			for (int k = 0; k < 4; k++) {
				//puts("Entered..");
				int nd = cd + 1;
				int nx = cx + nd * dx[k];
				int ny = cy + nd * dy[k];
				if (ok(nx,ny,nd)) {
					//puts("Added..");
					x[sz] = nx;
					y[sz] = ny;
					d[sz] = nd;
					p[sz] = k;
					q[sz] = i;
					sz++;
				}
			}
		}
	}

	return 0;
}
