#include<stdio.h>
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		long long n=T;
		scanf("%lld",&n);
		if(!n){
			printf("Case #%d: INSOMNIA\n",T);
			continue;
		}
		int cnt[10]={0};
		long long m;
		for(m=n;;m+=n){
			char s[101];
			sprintf(s,"%lld",m);
			for(int i=0;s[i];i++){
				cnt[s[i]-'0']++;
			}
			bool f=false;
			for(int i=0;i<10;i++){
				if(!cnt[i]) f=true;
			}
			if(!f) break;
		}
		printf("Case #%d: %lld\n",T,m);
	}
}
