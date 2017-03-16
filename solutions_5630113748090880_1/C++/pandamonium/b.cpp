#include <bits/stdc++.h>
using namespace std;
int t,n,k,cnt[2505];
int main(){
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int x=0;x<2*n-1;x++){
			for(int y=0;y<n;y++){
				scanf("%d",&k);
				cnt[k]++;
			}
		}
		printf("Case #%d:",c);
		for(int x=1;x<=2500;x++){
			if(cnt[x]&1) printf(" %d",x);
		}
		printf("\n");
	}
	return 0;
}
