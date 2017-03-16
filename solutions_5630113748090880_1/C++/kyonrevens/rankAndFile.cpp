#include <bits/stdc++.h>
using namespace std;

int T, TC = 1, N, arr[105][55], cnt[2505];
int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		memset((cnt), 0, sizeof(cnt));
		for(int i = 0; i < 2*N-1; i++)
			for(int j = 0; j < N; j++) scanf("%d", &arr[i][j]), cnt[arr[i][j]]++;
		vector<int> ans;
		for(int i = 0; i < 2505; i++)
			if(cnt[i]%2 != 0) ans.push_back(i);
		sort(ans.begin(), ans.end());
		printf("Case #%d:", TC++);
		for(int i = 0; i < (int)ans.size(); i++) printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}
