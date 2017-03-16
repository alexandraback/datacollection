#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> ii;
const int MAXN = 10010, MAXL = 1000010;

char s[MAXN], ans[MAXN];
int n;

void moveAns(char * ans, int j);

int main() {
	//freopen("A-large.in", "r", stdin);
	//freopen("output-large.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int test=1; test<=t; test++) {
		scanf("%s", s);
		n = (int)strlen(s);

		ans[0] = s[0];
		for(int i=1; i<n; i++) {
			bool before = true;
			for(int j=0; j<i; j++) {
				if(s[i] == ans[j]) continue;
				if(s[i] > ans[j]) {
					before = true;
				} else {
					before = false;
				}
				break;
			}

			if(before) {
				moveAns(ans, i);
				ans[0] = s[i];
			} else {
				ans[i] = s[i];
			}
		}
		ans[n] = 0;

		printf("Case #%d: %s\n", test, ans);
	}
}

void moveAns(char * ans, int j) {
	for(int i=j; i>0; i--) {
		ans[i] = ans[i-1];
	}
}
