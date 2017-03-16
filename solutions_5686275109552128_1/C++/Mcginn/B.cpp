#include<cstdio>
#include<cstring>
#define N 1007
int n;
int a[N];
int main(){
	freopen("B.out","w",stdout);
	int T,tt=0;
	int i,j,max,cnt,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;++i) scanf("%d",&a[i]);

		max=a[0];
		for(i=1;i<n;++i)
		if(max<a[i]) max=a[i];
		ans=max;
		for(j=1;j<=max;++j){
			cnt=j;
			for(i=0;i<n;++i){
				cnt+=(a[i]-1)/j;
			}
			if(cnt<ans) ans=cnt;
		}
		printf("Case #%d: %d\n",++tt,ans);
	}
	return 0;
}
