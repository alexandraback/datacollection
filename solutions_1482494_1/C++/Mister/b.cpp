#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
int L[1005], va[1005], vb[1005];
pair<int,int> B[1005];
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		int N, stars = 0, ans;
		bool imp = 0;
		scanf("%d",&N);
		ans = N;
		for(int i=1;i<=N;++i) {
			scanf("%d%d",&va[i],&B[i].first);
			vb[i] = B[i].first;
			B[i].second = i;
			L[i] = 0;
		}
		sort(B+1,B+N+1);
		for(int i=1;i<=N;++i) {
			// do doable 'level 1's with the highest b first
			while(stars < B[i].first) {
				int take = -1;
				for(int j=1;j<=N;++j) {
					if(L[j]) continue;
					if(va[j] <= stars) {
						if(take == -1 || vb[j] > vb[take]) take = j;
					}
				}
				if(take == -1) break;
				++stars;
				++ans;
				L[take] = 1;
			}
			if(stars < B[i].first) {
				imp = 1;
				break;
			}
			stars += (2 - L[B[i].second]);
			L[B[i].second] = 2;
		}
		printf("Case #%d: ",cn);
		if(imp) printf("Too Bad\n");
		else printf("%d\n",ans);
	}
}
