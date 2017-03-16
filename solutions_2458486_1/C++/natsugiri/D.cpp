#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

typedef long long LL;

int K, N, key[222], lock[222];
int ans[222];
vector<int>in[222];
bool use[222];

void init() {
    scanf("%d%d", &K, &N);
    memset(key, 0, sizeof key);
    
    for (int i=0; i<K; i++) {
	int d; scanf("%d", &d);
	key[d]++;
    }
    for (int i=0; i<N; i++) {
	in[i].clear();
	int d;
	scanf("%d%d", lock+i, &d);
	
	for (int j=0; j<d; j++) {
	    int e; scanf("%d", &e);
	    in[i].push_back(e);
	}
    }
}

bool key_count() {
    int chest[222]={}, key_all[222]={};
    for (int i=0; i<N; i++) {
	chest[lock[i]]++;
	for (int j=0; j<int(in[i].size()); j++) {
	    key_all[in[i][j]]++;
	}
    }
    for (int i=0; i<N; i++) {
	int l=lock[i];
	if (chest[l]>key_all[l]+key[l]) return false;
    }
    return true;
}

bool check() {
    bool visit[222]={};
    stack<int>st;
    for (int i=0; i<222; i++) if (key[i]) st.push(i);

    for (;!st.empty();) {
	int k=st.top(); st.pop();
	if (!visit[k]) {
	    visit[k]=true;
	    for (int i=0; i<N; i++) {
		if (lock[i]==k && !use[i]) {
		    for (int j=0; j<int(in[i].size()); j++)
			st.push(in[i][j]);
		}
	    }
	}
    }
    for (int i=0; i<N; i++) {
	if (!use[i] && !visit[lock[i]]) return false;
    }
    return true;
}

bool rec(int op) {
    if (op==N) return true;
    if (!check()) return false;

    for (int i=0; i<N; i++) {
	if (use[i]) continue;

	if (key[lock[i]]) {
	    use[i]=true;
	    key[lock[i]]--;
	    for (int j=0; j<int(in[i].size()); j++) key[in[i][j]]++;

	    ans[op]=i;
	    if (rec(op+1)) return true;

	    use[i]=false;
	    key[lock[i]]++;
	    for (int j=0; j<int(in[i].size()); j++) key[in[i][j]]--;
	}
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
	init();

	memset(use, 0, sizeof use);
	
	printf("Case #%d:", tc);

	if (key_count() && rec(0)) {
	    for (int i=0; i<N; i++) printf(" %d", ans[i]+1);
	    puts("");
	} else {
	    puts(" IMPOSSIBLE");
	}
    }

    return 0;
}
