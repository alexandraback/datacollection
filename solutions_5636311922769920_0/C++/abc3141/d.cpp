#include<iostream>
#include<cstdio>
using namespace std;
typedef long long int ll;
int T;
ll K,C,S;
ll ans;
ll P[100];
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%lld%lld%lld",&K,&C,&S);
		printf("Case #%d: ",cas+1);
		P[0]=1;
		for(int i=1;i<100;i++){
			if(P[i-1]*C<=3*(ll)1e18)P[i]=P[i-1]*K;
			else break;
		}
		if(S*C<K){
			printf("IMPOSSIBLE\n");
			continue;
		}
		ans=1;
		ll cou=0;
		for(int i=0;i<(int)C;i++){
			ans+=(cou%K)*P[i];
			cou++;
		}
		printf("%lld",ans);
		while(cou<K){
			ans=1;
			for(int i=0;i<(int)C;i++){
				ans+=(cou%K)*P[i];
				cou++;
			}
			printf(" %lld",ans);
		}
		printf("\n");
	}
	return 0;
}
