#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

long long cnt[2000020];

int normalize(int i){
	int d,p;
	for(d=0,p=1;p<=i;d++,p*=10);
	p/=10;
	int tmp=i;
	int ret=101010101;
	for(int k=0;k<d;k++){
		tmp=(tmp/10)+(tmp%10)*p;
		if(tmp>=p)ret=min(ret,tmp);
	}
	return ret;
}

main(){
	int cases;
	scanf("%d ",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		printf("Case #%d: ",casenum);
		int a,b;
		scanf("%d%d",&a,&b);
		memset(cnt,0,sizeof(cnt));
		for(int i=a;i<=b;i++){
			cnt[normalize(i)]++;
		}
		long long ans=0;
		for(int i=0;i<=b;i++){
			//if(cnt[i]>=2)printf("%d: %lld\n",i,cnt[i]);
			ans+=cnt[i]*(cnt[i]-1)/2;
		}
		printf("%lld\n",ans);
	}
}