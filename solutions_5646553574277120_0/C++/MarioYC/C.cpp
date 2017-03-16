#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T,C,D,V;
	int a[100];

	scanf("%d",&T);

	for(int tc = 1;tc <= T;++tc){
		scanf("%d %d %d",&C,&D,&V);

		for(int i = 0;i < D;++i)
			scanf("%d",&a[i]);

		long long cur = 0;
		int ans = 0,pos = 0;

		while(cur < V){
			while(cur < V && pos < D && a[pos] - 1 <= cur){
				cur += (long long)a[pos] * C;
				++pos;
			}

			if(cur < V){
				cur += (long long)(cur + 1) * C;
				++ans;
			}
		}

		printf("Case #%d: %d\n",tc,ans);
	}

	return 0;
}