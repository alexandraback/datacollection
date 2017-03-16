#include <stdio.h>
#include <algorithm>
using namespace std;
int v[128];
int main()
{
	freopen("src.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n;
	long long op,a;
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		op=0;
		scanf("%lld%d",&a,&n);
		for(int i=0;i<n;++i)
			scanf("%d",&v[i]);
		if(a==1){
			printf("Case #%d: %d\n",k,n);
			continue;
		}
		sort(v,v+n);
		for(int i=0;i<n;++i){
			long long cost=0;
			while(a<=v[i]){
				a+=a-1;
				++cost;
				if(cost+op>=n){
					cost=n;
					break;
				}
			}
			if(cost<n-i){
				op+=cost;
				a+=v[i];
			}else{
				op+=n-i;
				break;
			}
		}
		if(op>n)
			op=n;
		printf("Case #%d: %lld\n",k,op);
	}
	return 0;
}