#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, j;

int bff[2001];
int seen[2001];
int cyc_repr[2001];
int pr[2001];

void read() {
	scanf("%d", &n);
	REP(i,n) {
		scanf("%d", &bff[i]);
		bff[i]--;
	}
}

void solve() {
	memset(cyc_repr,0,sizeof(cyc_repr));
	int ans = 0;
	REP(i,n) {
		int cur = i;
		int d = 1;
		memset(seen,0,sizeof(seen));
		while (!seen[cur]) {
			seen[cur] = d;
			cur = bff[cur];
			d++;
		}

		int cyc_len = d-seen[cur];

		//printf("cyclen %d\n", cyc_len);
		//printf("cycrepr %d %d (from %d)\n", cur, d-1, i);
		if (cyc_len > 2) ans = max(ans, cyc_len);
		else if (cyc_len == 2) {
			cyc_repr[cur] = max(cyc_repr[cur], d-1);
			pr[cur] = bff[cur];
		}
	}

	int ot = 0;
	REP(i,n) {
		ot += cyc_repr[i];
		if (cyc_repr[i] && pr[i] > i) ot -= 2;
	}

	printf("%d\n", max(ans,ot));
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}