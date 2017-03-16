#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

template<typename T>
class heap : public priority_queue<T,vector<T>,greater<T> > {};



int main(void) {
	
	
	
	
	
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt) {
		long long b,n;
		scanf("%lld%lld",&b,&n);
		printf("Case #%d: ",tt);
		
		if(n > (1ll<<(b-2))) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			int ans[100][100];
			FOR(i,100) FOR(j,100) ans[i][j] = 0;
			
			for(int i=b-1;i>0;--i) {
				if((1ll<<(i-1))&n) {
					FOR(j,i) {
						for(int k=0;k<i;++k) {
							if(j<k) ans[j][k] = 1;
						}
					}
					FOR(j,i) ans[j][i] = 1;
					ans[i][b-1]  = 1;
				}
			}
			FOR(i,b) ans[b-1][i]= 0;
			FOR(i,b) {
				FOR(j,b) printf("%d",ans[i][j]);
				printf("\n");
			}
		}
			
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
}