#include <bits/stdc++.h>

using namespace std;
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	int test;
	scanf("%d",&test);
	int cnt = 1;
	while(test--) {
		int a[15][15];
		int b[15][15];
		int c[15][15];
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		
		vector<pair<int, pair<int,int> > > anss;
		int tot=0;
		int J,P,S,K;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		for(int i=1;i<=J;i++) {
			for(int j=1;j<=P;j++) {
				for(int k=1;k<=S;k++) {
					if(a[i][j]>=K) continue;
					if(b[j][k]>=K) continue;
					if(c[i][k]>=K) continue;
					a[i][j]++;
					b[j][k]++;
					c[i][k]++;
					anss.push_back(make_pair(i,make_pair(j,k)));
					tot++;
				}
			}
		}
		printf("Case #%d: %d\n", cnt++, tot);
		int sz = anss.size();
		for(int i=0;i<sz;i++) {
			printf("%d %d %d\n",anss[i].first,anss[i].second.first,anss[i].second.second);
		}
	}
	
	return 0;
}
