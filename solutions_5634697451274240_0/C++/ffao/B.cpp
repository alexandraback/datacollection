#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
int sc;
int seen[11];
char s[1100];

void read() {
	scanf("%s", s);
}

void solve() {
	int l = strlen(s);
	int wt_happy = 1;
	int ans = 0;

	for (int i = l-1; i >= 0; i--) {
		int is_happy = (s[i]=='+');
		if (wt_happy ^ is_happy) {
			wt_happy = 1-wt_happy;
			ans++;
		} 
	}

	printf("%d\n", ans);
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