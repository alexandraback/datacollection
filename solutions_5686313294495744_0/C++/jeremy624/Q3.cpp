#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <string>

using namespace std;

const int INF = 1e9;
int n,i,j,k,t,dp[1 << 17];
pair <int, int> a[1005];
map <string, int> b;
vector <int> edge[1005],edge1[1005];

int main(){
	scanf("%d", &t);
	int testcase = 0;
	while(++testcase <= t){
		b.clear();
		int nxt = 0;
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			edge[i].clear();
			edge1[i].clear();
		}
		memset(dp, 0, sizeof(dp));
		for(i = 0; i < n; i++){
			string temp, temp1;
			cin >> temp >> temp1;
			if(b[temp] == 0)
			b[temp] = ++nxt;
			if(b[temp1] == 0)
			b[temp1] = ++nxt;
			a[i].first = b[temp];
			a[i].second = b[temp1];
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(i == j) continue;
				if(a[i].first == a[j].first){
					edge[i].push_back(j);
				}
				if(a[i].second == a[j].second){
					edge1[i].push_back(j);
				}
			}
		}
		dp[0] = 0;
		for(i = 1; i <= (1 << n) - 1; i++){
			for(j = 0; j < n; j++){
				if((i | (1 << j)) != i) continue;
				int mask = i - (1 << j);
				bool flag = 0;
				bool flag1 = 0;
				for(int k = 0; k < edge[j].size(); k++){
					if((mask | (1 << edge[j][k])) == mask)
					flag = 1;
				}
				for(int k = 0; k < edge1[j].size(); k++){
					if((mask | (1 << edge1[j][k])) == mask)
					flag1 = 1;
				}
				dp[i] = max(dp[i], dp[mask] + (flag && flag1));
			}
		}
		printf("Case #%d: %d\n", testcase, dp[(1 << n) - 1]);
	}
}

