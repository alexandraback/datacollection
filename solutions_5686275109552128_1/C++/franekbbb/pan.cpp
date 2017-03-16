#include<bits/stdc++.h>
using namespace std;
const int MAXN=1111;
int dp[MAXN];
main(){
	int test;scanf("%d",&test);
	for(int tsn=1;tsn<=test;tsn++){
		int d;scanf("%d",&d);
		//printf("%d %d\n",tsn,d);
		for(int i=1;i<=d;i++){
			int a;scanf("%d",&a);
			for(int j=1;j<MAXN;j++){
				dp[j]+=((a+j-1)/j)-1;
			}
		}
		//puts("B");
		int wyn=1000*MAXN;
		for(int i=1;i<MAXN;i++) {
			wyn=min(wyn,i+dp[i]);
			dp[i]=0;
		}
		printf("Case #%d: %d\n",tsn,wyn);
	}
}
		
