#include <cstdio>
int a,b,k;
int T,Ti;
int cnt;
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<T+1;Ti++) {
		cnt=0;
		scanf("%d%d%d",&a,&b,&k);
		int i,j;
		for(i=0;i<a;i++) {
			for(j=0;j<b;j++){
				if((i&j)<k) cnt++;
			}
		}
		printf("Case #%d: %d\n",Ti,cnt);
	}
	return 0;
}