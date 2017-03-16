#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define inf 1000000000
#define maxn 10000000

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define sin scanint
#define bitcount(x) __builtin_popcount(x)
#define fill(s, p) memset(s, p, sizeof(s));
#define gc getchar

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

ll modpow(ll a, ll b)
{
	ll x=1ll, y=a;
	while(b){
		if(b%2)
			x=(x*y)%MOD;
		y=(y*y)%MOD;
		b/=2;
	}
	return x;
}

ll gcd(ll a, ll b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b, a%b);
}

ll dp[maxn];

int rev(int n)
{
	int reverse=0;
	for( ; n!= 0; ){
      	reverse = reverse * 10;
      	reverse = reverse + n%10;
      	n = n/10;
   	}
   	return reverse;	
}
/*
ll solve(int n)
{
	cout << n << endl;
	if(n<=11)
		return n;
	if(dp[n]!=-1)
		return dp[n];
	ll a, b;
	int revers = rev(n);
	a = solve(n-1);
	if(n%10!=0)
		b = 1+solve(revers);
	else
		b = inf;
	return dp[n] = min(a, b);
}
*/
int ans[maxn];

int main()
{
	//fill(dp, -1);
	#ifndef ONLINE_JUDJE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int i, t, n, a, b, c, r, case_num=1;
	for(i=1; i<10000000; i++)
		ans[i] = i;
	for(i=1; i<=1000000; i++){
		if(i<=11){
			ans[i] = i;
			continue;
		}
		if(i%10!=0){
			r = rev(i);
			a = ans[r]+1;
		}
		else
			a = inf;
		ans[i] = min(min(ans[i], a), ans[i-1]+1);
		//cout << a << " " << ans[i] << " " << ans[i-1] << endl;
		//cout << i << " " << ans[i] << endl;
	}
	sin(t);
	while(t--){
		sin(n);
		printf("Case #%d: %d\n", case_num++, ans[n]);
	}
	return 0;
}