/*******************
    D Rupinder
***********************/


#include<bits/stdc++.h>

#define lld long long int
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz size()
#define pii pair<int, int>
#define pll pair <lld ,lld>
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define scan(v,n) vector<int> v(n);rep(i,n)cin>>v[i];
#define vi vector<int>
#define MOD 1e9 + 7

using namespace std;
lld modpow(lld a,lld n,lld temp){lld res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int rev (int x) {
	int a[10];
	int cur = 0;
	while (x > 0) {
		a[cur++] = x%10;
		x/=10;
	}x=0;
	int mult = 1;
	while (cur > 0) {
		x += a[--cur]*mult;
		mult *= 10;
	}
	return x;
}
const int N = 1e6 + 1;
int dp[N] = {0};
int main()
{
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (rev(i) < i && i%10 != 0) dp[i] = min (dp[i], dp[rev(i)] + 1);
	}
	int t;
	cin>>t;
	int T = t;
	while (t--) {
		int n;
		cin>>n;
		cout<<"Case #"<<T-t<<": "<<dp[n]<<"\n";
	}
	return 0;
}
