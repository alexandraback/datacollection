#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int n,s,T,Ti;
int a[110],b[110];
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		memset(b,0,sizeof(b));
		scanf("%d%d",&s,&n);
		int i;
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		if(s==1) {
			printf("Case #%d: %d\n",Ti,n);
			continue;
		}
		sort(a,a+n);
		int cur_size=s;
		for(i=0;i<n;i++) {
			if(i!=0) b[i]=b[i-1];
			if(a[i]<cur_size) {
				cur_size+=a[i];
				continue;
			}
			while(1) {
				cur_size*=2;
				cur_size--;
				b[i]++;
				if(cur_size>a[i]) {
					cur_size+=a[i];
					break;
				}
			}
		}
		int ans=n;		
		for(i=0;i<n;i++) {
			if(ans>b[i]+n-i-1) ans=b[i]+n-i-1;
		}
		printf("Case #%d: %d\n",Ti,ans);
	}
	return 0;
}