#include<cstdio>
#include<cstdlib>
int main(){
	freopen("inputD","r",stdin);
	freopen("outputD.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",t);
		for(int i=1;i<=s;i++)printf(" %d",i);
		puts("");
	}
}
