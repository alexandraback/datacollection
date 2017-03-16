#include<cstdio>
#include<algorithm>
#include<cstring>
int a[60][60],que[3600],s[60];
int main(){
    freopen("B-small-attempt0.bin","r",stdin);
    freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	int cnt,n,i,j,sc;
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);cnt=0;
		for(i=1;i<2*n;i++)for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			que[cnt++]=a[i][j];
		}
		std::sort(que,que+cnt);
		sc=0;
		for(i=0;i<cnt;i=j){
			j=i+1;
			while(j<cnt&&que[j]==que[i])j++;
			if((j-i)&1)s[sc++]=que[i];
		}
		std::sort(s,s+sc);
		printf("Case #%d:",cas);
		for(i=0;i<sc;i++)printf(" %d",s[i]);
		printf("\n");	
	}
}
