#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int E,R,n;

int d[20][20];

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++){
		vector<int> data;
		scanf("%d%d%d",&E,&R,&n);
		for(int i = 0; i < n; i++) {
			int v;
			scanf("%d",&v);
			data.emplace_back(v);
		}
		long long ans = 0;
		memset(d,-1,sizeof(d));
		d[0][E] = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= E; j++) {
				if (d[i][j] == -1) continue;
				for(int k = 0; k <= j; k++) {
					int newv = d[i][j] + k*data[i];
					int newleft = min(E, R+j-k);
					d[i+1][newleft] = max(d[i+1][newleft], newv);
				}
			}
		}
		ans = *max_element(d[n],d[n]+E+1);
		printf("Case #%d: %lld\n", testcase, ans);
	}
	return 0;
}
