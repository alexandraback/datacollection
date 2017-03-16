#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using namespace std;

using ll = long long;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

int main(){
	int t=read();
	bool see[10];
	REP(caseNumber,t){
		ll n=read();
		if(n==0){
			printf("Case #%d: INSOMNIA\n",caseNumber+1);
			continue;
		}
		fill(see,see+10,false);
		int count=0;
		ll j=0;
		while(count<10){
			ll s=n*++j;
			while(s>0){
				int p=s%10;
				if(!see[p]){
					see[p]=true;
					count++;
				}
				s/=10;
			}
		}
		printf("Case #%d: %lld\n",caseNumber+1,n*j);
	}
}