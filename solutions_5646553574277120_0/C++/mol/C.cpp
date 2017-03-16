#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0; t<T; t++){
		int C,D,V;
		scanf("%d%d%d",&C,&D,&V);
		int m[D];
		for(int i=0; i<D; i++)
			scanf("%d",m+i);
		// C=1
		int dp[V+1];
		for(int j=0; j<=V; j++)
			dp[j] = 0;
		dp[0] = 1;
		for(int i=0; i<D; i++)
			for(int j=V; j>=0; j--)
				if(dp[j] && j+m[i]<=V)
					dp[j+m[i]] = 1;
		int cnt = 0;
		for(int j=0; j<=V; j++)
			if(dp[j] == 0){
				cnt++;
				for(int jj=V; jj>=0; jj--)
					if(dp[jj] && jj+j<=V)
						dp[jj+j] = 1;
			}
		printf("Case #%d: %d\n",t+1,cnt);
	}
	return 0;
}
