#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>


int main(){
	int t=0,T,k,i,n,c,s;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("pDout.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		t++;
		scanf("%d%d%d",&n,&c,&s);
		printf("Case #%d: ",t);
		for(k=1;k<=n;k++) printf("%d ",k);
		puts("");
	}
}
