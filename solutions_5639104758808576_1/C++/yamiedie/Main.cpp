#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 1020
#define M 200020
#define LL long long
#define inf 0x3f3f3f3f


char s[N];
int n;

int main() {
	//freopen("tt.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cas, kk = 0;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%s", &n, s);
		int cnt = s[0] - '0', ans = 0;
		for(int i = 1; s[i]; ++i) {
			if(cnt < i) {
				ans += i - cnt;
				cnt += i - cnt;
			}
			cnt += s[i] - '0';
		}
		printf("Case #%d: %d\n", ++kk, ans);
	}
	return 0;
}

