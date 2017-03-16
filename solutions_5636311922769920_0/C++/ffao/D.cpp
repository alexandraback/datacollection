#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int k,c,s;

void read() {
	scanf("%d %d %d", &k, &c, &s);
}

void solve() {
	if (c * 1ll * s < k) {
		printf("IMPOSSIBLE\n");
		return;
	}

	int checking = 0;
	bool done = false;
	while (!done) {
		long long pot = 1;
		REP(i, c-1) pot *= k;
		long long cur = 1;

		REP(i, c) {
			cur += pot * checking;
			if (checking < k-1) checking++;
			else done = true;
			pot /= k; 
		}

		printf("%lld", cur);
		if (done) printf("\n");
		else printf(" ");
	}

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