#include <stdio.h>
#include <algorithm>

using namespace std;

int t,c,d,v;
int D[200];

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		printf("Case #%d: ",tt);
		scanf("%d%d%d",&c,&d,&v);
		for(int i=0;i<d;++i){
			scanf("%d",D+i);
		}
		sort(D,D+d);
		int res=0;
		long long need=1;
		for(int i=0;i<d;){
			if (need>v) break;
			if (D[i]<=need){
				need+=D[i]*c;
				++i;
			} else{
				need+=need*c;
				++res;
			}
		}
		while(need<=v){
			need+=need*c;
			++res;
		}
		printf("%d\n",res);
	}
	return 0;
}
