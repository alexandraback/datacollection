
//Author : Ujjawal Dixit  , ABV-IIITM
//Task : test

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 1e9
#define MIN -1e9
using namespace std;
typedef double ld;
typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define FOR(i,n,m) for(int i=0;i<n;i+=m)
#define For(i,n,m) for(int i=1;i<=n;i+=m)
#define max(a,b)    (a>=b?a:b)
#define min(a,b)    (a<b?a:b)
#define countbits(num)   __builtin_popcount(num)
#define countbitsll(num)   __builtin_popcountll(num)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define p(a) printf("%d",a)
#define pll(a) printf("%lld",a)
#define pln()  printf("\n")
#define getstr(in) getline(cin,in)
#define getc() getchar()
#define uj() int t; scanf("%d",&t); while(t--)
ll mpow(ll a, ll n) 
{ll ret=1;ll b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
    return (ll)ret;}
template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}
int main()
{
    int t, r, c, w;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int res = 0;
		cin >> r >> c >> w;


		res = c / w *r;

		res += w - 1;
		if (c%w != 0)
			res++;
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
    
 return 0;
}