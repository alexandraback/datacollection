#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define REP(i, N) for(int i = 0; i < (N); i++)

using namespace std;

int visited[11][12];
vector<int> nxt[11];
string PST[11];
int n,m;
int Q;
string ans;
string cans;
int starting;
stack<int> S;
void brute(int v, bool ret = false) {
	visited[v][ret] = true;
	if(!ret) {
		S.push(v);
		Q++;
		if(Q == n && cans < ans) {
			ans = cans;
		}
	}
	for(int i = 0; i < nxt[v].size(); i++) {
		int nv = nxt[v][i];
		if(visited[nv][0]) continue;
		string tmp = cans;
		cans += PST[nv];
		brute(nv);
		cans = tmp;
	}
	if(S.size() >= 2) {
		int F = S.top();
		S.pop();
		int pre = S.top();
		brute(pre, true);
		S.push(F);
	}
	if(!ret) {
		S.pop();	
		Q--;
	}
	visited[v][ret] = false;
}

int main() {
	int T, testcase=1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		REP(i, 11) nxt[i].clear();
		ans = "";
		REP(i, n) ans += "99999";
		REP(i, n) {
			char buff[11];
			scanf("%s", buff);
			PST[i] = string(buff);
		}
		REP(i, m) {
			int a,b;
			scanf("%d%d", &a, &b);
			nxt[a-1].pb(b-1);
			nxt[b-1].pb(a-1);
		}

		for(int start = 0; start < n; start++) {
			REP(i, n) REP(j, 11) visited[i][j] = false;
			visited[start][0] = true;
			cans = PST[start];
			brute(start, false);
		}


		printf("Case #%d: ", testcase++);
		printf("%s", ans.c_str());
		printf("\n");
	}
	
	return 0;
}
