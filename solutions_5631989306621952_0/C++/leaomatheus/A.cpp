#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii, ii>
#define vvi vector<vi>
#define MAXN 105
#define MAXE 10005
#define FOR(x,n) for(int x = 0; x < n; x++)
#define FOR1e(x,n) for(int x = 1; x <= n; x++)
#define MOD 1000000007

char p[10005];

int main() {
	int n, t;
	scanf("%d", &t);
	FOR1e(caso, t) {
		string answer = "", a, b;
		scanf(" %s", p);
		n = strlen(p);
		for(int i = 0; i < n; i++) {
			if(i == 0) answer = answer + p[i];
			else {
				a = answer + p[i];
				b = p[i] + answer;
				if(a > b) answer = a;
				else answer = b;
			}
		}
		printf("Case #%d: %s\n", caso, answer.c_str());
	}
	return 0;
}