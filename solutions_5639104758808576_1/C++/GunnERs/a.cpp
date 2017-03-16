#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int task, t, n;
char a[2000];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("aa.out", "w", stdout);

	scanf("%d", &t);
	for (task=1; task<=t; task++){
		scanf("%d%s", &n, a);
		int num = 0, ans = 0;
		for (int i=0; i<n+1; i++){
			int add = max(i-num, 0);
			ans += add;
			num += a[i]-'0' + add;
		}

		printf("Case #%d: %d\n", task, ans);
	}
	return 0;
}
