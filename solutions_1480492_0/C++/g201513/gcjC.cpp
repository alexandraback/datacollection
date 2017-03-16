#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

const double eps = 1e-6;
const int maxn = 55;

struct EVENT {
	double time;
	int t;
	int a, b;
} E[maxn * maxn * 2];

bool cmp(const EVENT &a, const EVENT &b) {
	if(fabs(a.time - b.time) < eps) return a.t < b.t;
	return a.time < b.time;
}

struct CAR {
	int side;
	double speed;
	double position;
} C[maxn];

bool G[maxn][maxn];
bool P[maxn][maxn];
int ntest;
int N, cnt;
char s[100];

void add(double time, int t, int a, int b) {
	E[cnt].time = time;
	E[cnt].t = t;
	E[cnt].a = a;
	E[cnt].b = b;
	cnt++;
}

void release() {
	for(int i=1; i<=N; i++) {
		bool ok = true;
		for(int j=1; j<=N; j++) if(G[i][j]) {
			ok = false;
		}
		if(ok) {
			C[i].side = 2;
			for(int j=1; j<=N; j++) P[i][j] = P[j][i] = false;
		}
	}
}

int u[maxn];

bool dfs(int x, int p, bool force) {
	if(u[x] != 2) {
		if(force) C[x].side = p;
		return u[x] == p;
	}

	u[x] = p;

	for(int i=1; i<=N; i++) if(P[i][x]) {
		if(!dfs(i, p^1, force)) return false;
	}

	return true;
}

bool check() {
	memset(u, 0, sizeof(u));

	for(int i=1; i<=N; i++) u[i] = 2;

	for(int i=1; i<=N; i++) if(u[i] == 2 && C[i].side != 2) {
		if(!dfs(i, C[i].side, true)) return false;
	}

	for(int i=1; i<=N; i++) if(u[i] == 2) {
		if(!dfs(i, 0, false)) return false;
	}

	return true;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &N);
		for(int i=1; i<=N; i++) {
			scanf("%s%lf%lf", &s, &C[i].speed, &C[i].position);
			if(*s == 'L') C[i].side = 0;
			else C[i].side = 1;
		}

		cnt = 0;
		memset(G, 0, sizeof(G));
		memset(P, 0, sizeof(P));
		for(int i=1; i<=N; i++) {
			for(int j=i+1; j<=N; j++) {
				if(fabs(C[i].position - C[j].position) < 5 - eps) {
					G[i][j] = G[j][i] = true;
					P[i][j] = P[j][i] = true;
				}

				if(fabs(C[i].speed - C[j].speed) < eps) continue;

				double ds = C[i].speed - C[j].speed;
				double dp = C[j].position - C[i].position;

				double t1 = (dp - 5) / ds;
				double t2 = (dp + 5) / ds;

				if(t1 > t2) swap(t1, t2);

				if(t1 > -eps) {
					add(t1, 1, i, j);
				}
				if(t2 > -eps) {
					add(t2, 0, i, j);
				}
			}
		}

		release();
		sort(E, E+cnt, cmp);

		double ans = 1e100;
		for(int i=0; i<cnt; ) {
			int next = i;
			while(next < cnt && fabs(E[i].time - E[next].time) < eps) next++;

			for(int j=i; j<next; j++) if(E[j].t == 0) G[E[j].a][E[j].b] = G[E[j].b][E[j].a] = 0;

			release();

			for(int j=i; j<next; j++) if(E[j].t == 1) {
				G[E[j].a][E[j].b] = G[E[j].b][E[j].a] = 1;
				P[E[j].a][E[j].b] = P[E[j].b][E[j].a] = 1;
			}

			if(!check()) {
				ans = E[i].time;
				break;
			}

			i = next;
		}

		if(ans > 1e50) printf("Case #%d: Possible\n", test);
		else printf("Case #%d: %.10lf\n", test, ans);
	}
	return 0;
}
