#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define MAXK 205
#define MAXN 205
int t, k, n;
int ks[MAXK];
int tt[MAXN], ck[MAXN];
vector<int> cont[MAXN];
vector<int> order;
int memo[1<<25];
bool dp(int bm) {
    if (bm == (1<<(n+1))-2)
	return true;
    if (memo[bm] != -1) {
	return memo[bm] == 1;
    }
    int& res = memo[bm];
    for (int i=1; i<=n; i++) {
	if ((bm & (1<<i)) == 0 && ks[tt[i]]) {
	    ks[tt[i]]--;
	    for (int j=0; j<ck[i]; j++) {
		ks[cont[i][j]]++;
	    }
	    order.push_back(i);
	    bool ans = dp(bm|(1<<i));
	    if (ans) {
		res = 1;
		return true;
	    }
	    res = 0;
	    order.pop_back();
	    for (int j=0; j<ck[i]; j++) {
		ks[cont[i][j]]--;
	    }
	    ks[tt[i]]++;
	}
    }
    res = 0;
    return false;
}

int main() {
    scanf("%d", &t);
    for (int T=1; T<=t; T++) {
	order.clear();
	memset(ks, 0, sizeof ks);
	memset(memo, -1, sizeof memo);
	scanf("%d%d", &k, &n);
	int v;
	for (int i=0; i<k; i++) {
	    scanf("%d",&v);
	    ks[v]++;
	}
	for (int i=1; i<=n; i++) {
	    scanf("%d%d", &tt[i], &ck[i]);
	    cont[i].clear();
	    for (int j=0; j<ck[i]; j++) {
		scanf("%d", &v);
		cont[i].push_back(v);
	    }
	}
	bool ans  = dp(0);
	printf("Case #%d: ", T);
	if (ans) {
	    for (int i=0; i<n; i++) printf("%d ", order[i]);
	    printf("\n");
	}
	else printf("IMPOSSIBLE\n");
    }
}

// struct state {
//     vector<bool> st;
//     vector<int> ks;
//     vector<int> order;
//     state() {}
//     bool is_goal() {
// 	for (int i=1; i<st.size(); i++) if (!st[i]) return false;
// 	return true;
//     }
//     bool operator<(const state& rhs) const {
// 	return order < rhs.order;
//     }
// };

// int t, k, n, a,b;
// int tt[210];
// vector<int> ko[210];
// state initial;
// int main() {
//     scanf("%d", &t);
//     for (int T=1; T<=t; T++) {
// 	scanf("%d%d", &k, &n);
// 	initial.st.clear(); initial.ks.clear();
// 	initial.st.resize(n+1);
// 	initial.ks.resize(401);
// 	initial.order.clear();
// 	for (int i=0; i<k; i++) {
// 	    scanf("%d", &a);
// 	    initial.ks[a]++;
// 	}
// 	for (int i=1; i<=n; i++) {
// 	    scanf("%d%d", &tt[i], &b);
// 	    ko[i].resize(b);
// 	    for(int j=0; j<b; j++) {
// 		scanf("%d", &ko[i][j]);
// 	    }
// 	}
// 	set<state> visit;
// 	queue<state> q;
// 	q.push(initial);
// 	bool found = false;
// 	state ans;
// 	while(!q.empty()) {
// 	    state cur = q.front();
// 	    q.pop();
// 	    if (cur.is_goal()) { found = true; ans = cur; break; }
// 	    if (visit.count(cur)) continue;
// 	    visit.insert(cur);
// 	    for (int i=1; i<=n; i++) {
// 		if (!cur.st[i]) {
// 		    if (cur.ks[tt[i]]) {
// 			cur.ks[tt[i]]--;
// 			for (int j=0; j<ko[i].size(); j++) {
// 			    cur.ks[ko[i][j]]++;
// 			}
// 			cur.st[i] = true;
// 			cur.order.push_back(i);
// 			if (!visit.count(cur))
// 			    q.push(cur);
// 			cur.ks[tt[i]]++;
// 			for (int j=0; j<ko[i].size(); j++) {
// 			    cur.ks[ko[i][j]]--;
// 			}
// 			cur.st[i] = false;
// 			cur.order.pop_back();
// 		    }
// 		}
// 	    }
// 	}
// 	if (found) {
// 	    printf("Case #%d: ", T);
// 	    for (int i=0; i<ans.order.size(); i++) printf("%d ", ans.order[i]);
// 	    printf("\n");
// 	}
// 	else printf("Case #%d: IMPOSSIBLE\n", T);
//     }
//     return 0;
// }
