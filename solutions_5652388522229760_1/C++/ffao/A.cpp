#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
int sc;
int seen[11];

void read() {
	scanf("%d", &n);
}

void mark(int c) {
	while (c) {
		int d = c % 10;
		if (!seen[d]) {
			sc++;
			seen[d]=1;
		}
		c /= 10;
	}
}

void solve() {
	sc = 0;
	memset(seen,0,sizeof(seen));
	
	int c = n;
	for (int i = 0; i < 10000; i++) {
		mark(c);
		if (sc == 10) break;
		c += n;
	}

	if (sc != 10) printf("INSOMNIA\n");
	else printf("%d\n", c);
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