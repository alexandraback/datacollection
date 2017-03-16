#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
int a, mp[2550];
int main() {
	int T;
	cin >> T;
	int cas = 1;
	while (T--) {
		int n;
		memset(mp, 0, sizeof(mp));
		printf("Case #%d: ", cas++);
		cin>>n;
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a;
				mp[a]++;
			}
		}
		int flag = 1;
		for (int i = 0; i <= 2500; i++) {
			if (mp[i]%2==1) {
				if (flag) {
					flag = 0;
					printf("%d", i);
				} else
					printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
