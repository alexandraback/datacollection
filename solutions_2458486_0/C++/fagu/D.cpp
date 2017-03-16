#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (int)(n); i++)

int T;

int S, C;

int N;
VI adj[2000];
VI radj[2000];
VI *cadj;
VI order;
int comp[2000]; // \verb|comp[i]| ist hinterher die Komponente, in der i liegt
int compnr; // Anzahl der Komponenten
int compsize[2000];
bool vis[2000];

void dfs(int i) {
	if(vis[i])
		return;
	vis[i] = true;
	comp[i] = compnr;
	compsize[compnr]++;
	FOREACH(k,cadj[i])
		dfs(*k);
	order.push_back(i);
}

void solve() {
	for (int i = 0; i < N; i++)
		radj[i].clear();
	for (int i = 0; i < N; i++)
		FOREACH(k,adj[i])
			radj[*k].push_back(i);
	fill(vis, vis+N, false);
	order.clear();
	cadj = adj;
	for (int i = 0; i < N; i++)
		dfs(i);
	fill(vis, vis+N, false);
	compnr = 0;
	cadj = radj;
	for (int i = N-1; i >= 0; i--)
		if (!vis[order[i]]) {
			compsize[compnr] = 0;
			dfs(order[i]);
			compnr++;
		}
}

int want[200];
int st1[200];
bool done1[200];
bool done[200];
int upto[200];

bool geht() {
	queue<int> qu;
	REP(i,200)
		REP(j,st1[i])
			qu.push(i);
	REP(i,C)
		done[i] = done1[i];
	REP(i,200)
		upto[i] = 0;
	while(!qu.empty()) {
		int k = qu.front();
		qu.pop();
		while(upto[C+k] < (int)adj[C+k].size() && done[adj[C+k][upto[C+k]]])
			upto[C+k]++;
		if (upto[C+k] < (int)adj[C+k].size()) {
			int i = adj[C+k][upto[C+k]];
			done[i] = true;
			FOREACH(it,adj[i])
				qu.push(*it-C);
		}
	}
	REP(i,C)
		if (!done[i])
			return false;
	return true;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d:", test+1);
		scanf("%d%d", &S, &C);
		N = C+200;
		REP(i,200)
			st1[i] = 0;
		REP(i,N) {
			adj[i].clear();
			done1[i] = false;
		}
		REP(i,S) {
			int a;
			scanf("%d", &a);
			a--;
			st1[a]++;
		}
		REP(i,C) {
			int t, n;
			scanf("%d%d", &t, &n);
			t--;
			want[i] = t;
			adj[C+t].push_back(i);
			REP(j,n) {
				int a;
				scanf("%d", &a);
				a--;
				adj[i].push_back(C+a);
			}
		}
		solve();
		REP(i,N) {
			int l = 0;
			REP(j,adj[i].size()) {
				if (compsize[comp[adj[i][j]]] > 1) {
					swap(adj[i][l],adj[i][j]);
					l++;
				}
			}
		}
		if (geht()) {
			for (int t = 0; t < C; t++) {
				for (int i = 0; i < C; i++) {
					if (!done1[i] && st1[want[i]] > 0) {
						st1[want[i]]--;
						FOREACH(it,adj[i])
							st1[*it-C]++;
						done1[i] = true;
						if (geht()) {
							printf(" %d", i+1);
							break;
						}
						st1[want[i]]++;
						FOREACH(it,adj[i])
							st1[*it-C]--;
						done1[i] = false;
					}
				}
// 				printf(" [");
// 				REP(i,10)
// 					printf("%d,", st1[i]);
// 				printf("] ");
			}
			printf("\n");
		} else {
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}
