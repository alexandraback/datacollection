#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;

int t,T;
int R,S,M;

int Z[5][5], N[5][5];
bool ST[5][5];

queue<pair<int,int> > Q;
int revealed;

void neighbour(int rx, int sx, int nr, int ns) {
    if (nr < 0 || nr >= R || ns < 0 || ns >= S)
        return;
    if (Z[nr][ns])
        return;
    if (ST[nr][ns])
        return;
    revealed++;
    ST[nr][ns] = true;
    if (N[nr][ns] == 0)
        Q.push(make_pair(nr, ns));
}

bool tryit() {
    FOR(r,R) FOR(s, S) {
        N[r][s] = 0;
        if (r > 0 && s > 0)
            N[r][s] += Z[r-1][s-1];
        if (r > 0)
            N[r][s] += Z[r-1][s];
        if (s > 0)
            N[r][s] += Z[r][s-1];
        if (s < S-1 && r < R-1)
            N[r][s] += Z[r+1][s+1];
        if (s < S-1)
            N[r][s] += Z[r][s+1];
        if (r < R-1)
            N[r][s] += Z[r+1][s];
        if (r > 0 && s < S-1)
            N[r][s] += Z[r-1][s+1];
        if (r < R-1 && s > 0)
            N[r][s] += Z[r+1][s-1];
    }

    FOR(rs,R) FOR(ss, S) {
        if (!Z[rs][ss]) {
            FOR(r,R) FOR(s, S) ST[r][s] = false;
            ST[rs][ss] = true;
            revealed = 1;
            if (N[rs][ss] == 0)
                Q.push(make_pair(rs,ss));

            while (!Q.empty()) {
                int rx = Q.front().first;
                int sx = Q.front().second;
                Q.pop();
                neighbour(rx, sx, rx+1, sx);
                neighbour(rx, sx, rx+1, sx+1);
                neighbour(rx, sx, rx+1, sx-1);
                neighbour(rx, sx, rx-1, sx);
                neighbour(rx, sx, rx-1, sx+1);
                neighbour(rx, sx, rx-1, sx-1);
                neighbour(rx, sx, rx, sx);
                neighbour(rx, sx, rx, sx+1);
                neighbour(rx, sx, rx, sx-1);
			}

			if (M + revealed == R*S) {
				FOR(r,R) {
					FOR(s,S) {
						char c = '.';
						if (r == rs && s == ss)
							c = 'c';
						if (Z[r][s])
							c = '*';
						putchar(c);
					}
					putchar('\n');
				}
				return true;
			}
		}
	}
	return false;
}

void solve() {
	printf("Case #%d:\n", t);
	FOR(r,R) FOR(s,S) Z[r][s] = 0;

	int popcount = 0, carry = 0;
	while (!carry) {
		if (popcount == M)
			if (tryit()) return;
		Z[0][0]++;
		popcount = 0;
		FOR(r,R) FOR(s,S) {
			Z[r][s] += carry;
			if (Z[r][s] == 2)
				Z[r][s] = 0, carry = 1;
			else
				carry = 0;
			popcount += Z[r][s];
		}
	}

	printf("Impossible\n");

}

int main() {
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d%d%d", &R, &S, &M);
		solve();
	}
	return 0;
}
