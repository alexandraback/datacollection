#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, j;

int odds[32];
int evens[32];

void read() {
	scanf("%d %d", &n, &j);
}

void solve() {
	printf("\n");
	int its = 0;
	int rem = (n-1)/2;

	for (int i = rem/2; i < rem; i++) odds[i] = 1;
	do {
		for (int i = rem/2; i < rem; i++) evens[i] = 1;
		do {
			printf("1");
			REP(i, rem) {
				printf("%d%d", evens[i], odds[i]);
			}
			printf("1 3 4 5 6 7 8 9 10 11\n");
		} while (++its < j && next_permutation(evens, evens+rem));
	} while (its < j && next_permutation(odds, odds+rem));
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