#include <cstdio>

int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){

		int a,b,k,ans=0;
		scanf("%d %d %d",&a,&b,&k);
		for(int j=0;j<a;j++){
			for(int t=0;t<b;t++){
				if((j&t)<k) ans++;
			}
		}
		printf("Case #%d: ",i);
		printf("%d\n",ans);
	}
}
