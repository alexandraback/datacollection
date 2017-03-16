#include<cstdio>
#include<cstdlib>
typedef long long unsigned int lint;
lint pow(lint a,lint b){
	lint rsl=1;
	for(lint i=0;i<b;i++)rsl*=a;
	return rsl;
}
int main(){
	freopen("inputD","r",stdin);
	freopen("outputD.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		lint k,c,s;
		scanf("%llu%llu%llu",&k,&c,&s);
		printf("Case #%d:",t);
		lint n=(k+(c-1))/c;
		if(s<n)printf(" IMPOSSIBLE");
		else{
			for(lint i=0;i<k;i+=c){
				lint ans=0;
				for(lint j=0;j<c&&i+j<k;j++)
					ans+=(i+j)*pow(k,c-j-1);
				printf(" %llu",ans+1);
			}
		}
		puts("");
	}
}
