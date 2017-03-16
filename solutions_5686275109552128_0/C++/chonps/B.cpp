#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>

using namespace std;

typedef long long LL;

const int maxn = 2333;

int tot[maxn];

int main(){
	int T;
	scanf("%d", &T);
	for (int TI = 1; TI <= T; ++TI){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= 1000; ++i) tot[i] = 0;
		for (int i = 1; i <= n; ++i){
			int u;
			scanf("%d", &u);
			++tot[u];
		}
		int ans = 987654321;
		for (int i = 1; i <= 1000; ++i){
			int cnt = 0;
			for (int j = i + 1; j <= 1000; ++j)
				cnt += tot[j] * ((j - 1) / i);
			ans = min(ans, cnt + i);
		}
		printf("Case #%d: %d\n", TI, ans);
	}
	return 0;
}
