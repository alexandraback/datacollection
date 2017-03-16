#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

int g[1005][1005];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, N;
	cin >> T;
	for(int cas = 1; cas <= T; ++cas){
		cin >> N;
		memset(g, 0, sizeof(g));
		for(int i = 0; i < N; ++i){
			int m;
			cin >> m;
			for(int j = 1; j <= m; ++j){
				int k;
				cin >> k;
				g[i][k - 1] = 1;
			}
		}
		int maxCount = 0;
		for(int k = 0; k < N; ++k){
			for(int i = 0; i < N; ++i){
				for(int j = 0; j < N; ++j){
					if(g[i][k] && g[k][j]){
						g[i][j]++;
//						cout << i << " -> " << k << " -> " << j << endl;
						maxCount = max(maxCount, g[i][j]);
					}
				}
			}
		}
//		cout << "count=" << maxCount << endl;
		if(maxCount >= 2){
			printf("Case #%d: Yes\n", cas);
		}
		else{
			printf("Case #%d: No\n", cas);
		}
	}

	return 0;
}
