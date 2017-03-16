#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<queue>
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
int s[1005];
int app[1005],app2[1005];
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		int i,j;
		scanf("%d",&n);
		for(i=0;i<=1000;i++)
		  app[i]=0;
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			app[s[i]]++;
		}
		int ans=10000;
		for(i=1000;i>=1;i--){
			int d=0;
			for(j=0;j<=1000;j++)
			   app2[j]=app[j];
			for(j=1000;j>i;j--){
				if(!app2[j]) continue;
				d+=app2[j]*((j-1)/i);
			}
		//	printf("%d %d\n",i,d);
			if(d+i<ans) ans=d+i;
		}
		printf("Case #%d: %d\n",hh,ans);
	}
	return 0;
}

