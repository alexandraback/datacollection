#include<bits/stdc++.h>
using namespace std;
//#pragma comment (linker, "/STACK:256000000")
typedef long long ll ;
typedef vector<ll> VI ;
typedef pair<ll,ll>  PP;
typedef vector<PP>  VPP ;
#define  mp make_pair
#define pb push_back
#define fi first
#define se second

ll mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

// Things are quite easy..just hold on

int a[1000005];
int r =  0 ;
int solve(int x )
{


	if(x<=20) a[x] = x ;
   if(a[x]!=0) return a[x] ;


	int arr[8] , i = 0 , j = x , x1=0;
	while(j!=0)
	{
		arr[i++] = j%10 ;
		j = j/10 ;
	}
	while(j<i)
	{
		x1 = x1*10 + arr[j] ;
		j++;
	}

if(x1<x&&arr[0]!=0) a[x] = 1 + min(solve(x-1),solve(x1) ) ;

else a[x] = 1 + solve(x-1) ;

	return a[x] ;
}

int main()
{

int i ;

freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(0);

for(i=0;i<=1000000;i++) a[i] = a[i] = 0 ;

for(i=1;i<=100000;i++) a[i] = solve(i) ;

int t ,tt=0, n ;
cin >> t ;
while(t--)
{
	tt++;
	cin >> n ;
	cout<<"Case #"<<tt<<": "<<solve(n)<<endl;
}



return 0 ;


}

