//hi
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long int
int n;
int cnt[2600];
int main(void){
    int t,hh;
    scanf("%d",&t);
    for(hh=1;hh<=t;hh++){
		scanf("%d",&n);
		int i,j;
		for(i=1;i<=2500;i++) cnt[i]=0;
		for(i=0;i<2*n-1;i++)
			for(j=0;j<n;j++){
				int d;
				scanf("%d",&d);
				cnt[d]++;
			}
		int ans[60],x=0;
		for(i=1;i<=2500;i++)
			if(cnt[i]%2==1) ans[x++]=i;
		sort(ans,ans+n);
		printf("Case #%d:",hh);
		for(i=0;i<n;i++)
			printf(" %d",ans[i]);
		printf("\n");
		
	}
    return 0;
}
