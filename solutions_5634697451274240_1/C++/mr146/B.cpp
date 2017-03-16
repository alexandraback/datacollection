#include <vector>
#include <cstdio>
#include <cstring>
#include <string>


using namespace std;


char s[146];


void solve(int tc) {
	memset(s, 0, sizeof(s));
	scanf("%s", s);
	int n = strlen(s);
	int segments = 1;
	for(int i = 1; i < n; i++) {
		if(s[i] != s[i - 1]) {
			segments++;
		}
	}
	int ans = s[n - 1] == '+' ? segments - 1 : segments;
	printf("Case #%d: %d\n", tc, ans);
}


int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		solve(i + 1);
	}
	return 0;
}