#include<cstdio>
int main(){
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small-attempt0.out","wt",stdout);
	int t;
	scanf("%d",&t);
	for(int _=1;_<=t;_++){
		int cnt=0;
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				if((i&j)<k) cnt++;
				//printf("%d&%d:%d %d\n",i,j,i&j,k);
			}
		}
		printf("Case #%d: %d\n",_,cnt);
	}	
}