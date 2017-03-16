#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
char s[1100];

void read() {
	scanf("%s", s);
}


void solve() {
	int n = strlen(s);
	string ansp;
	string anss;

	int st = n;

	for (char c = 'Z'; c >= 'A'; c--) {
		int la = st;
		for (int i = 0; i < st; i++) {
			if (s[i] == c) {
				la = i;
				break;
			}
		}
		for (int i = st-1; i >= la; i--) {
			if (s[i] == c) ansp = ansp + c;
			else anss = s[i] + anss;
		}
		st = la;
	}

	ansp = ansp + anss;
	printf("%s\n", ansp.c_str());
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