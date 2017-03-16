#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n;
int a[2510];
int main() {
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		memset(a, 0, sizeof a);
		scanf("%d", &n);
		for(int i = 0; i < 2 * n - 1; ++i) {
			for(int j = 0; j < n; ++j) {
				int x;
				scanf("%d", &x);
				a[x]++;
			}
		}
		vector<int> ans;
		for(int i = 1; i <= 2500; ++i) {
			if(a[i] & 1) {
				ans.push_back(i);
			}
		}
		printf("Case #%d: ", cas);
		for(int i = 0; i < ans.size(); ++i) 
			printf("%d ",ans[i]);
		puts("");
	}

}