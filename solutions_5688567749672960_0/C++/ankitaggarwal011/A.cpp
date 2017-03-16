#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

ll memo[10000000];
ll reverse(ll num){
    ll ans = 0;
	while(num!=0){
		ans = ans*10 + num%10;
		num /= 10;
	}
	return ans;
}

ll solve(){
	ll i, tmp;
	memo[0] = 0;
	for(i=1;i<=10;i++)
		memo[i] = memo[i-1]+1;
	for(i=11;i<=1000000;i++){
			tmp = reverse(i);
			if(tmp!=i && i%10!=0 && memo[tmp]!=-1) memo[i] = min(memo[i-1] + 1, memo[tmp]+1);
			else memo[i] = memo[i-1] + 1;
	}
}

int main(){ _
	ll N;
	memset(memo, -1, 10000000);
	int T, i;
	solve();
	scanf("%d", &T);
	for(i=1;i<=T;i++){
	   scanf("%lld", &N);
	   printf("Case #%d: %lld\n", i, memo[N]);
	}
	return 0;
}
