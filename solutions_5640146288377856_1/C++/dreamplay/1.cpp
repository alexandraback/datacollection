#include<bits/stdc++.h>
using namespace std;
//#pragma comment (linker, "/STACK:256000000")
typedef long long ll ;
typedef vector<ll> VI ;
typedef pair<ll,ll>  PP;
typedef vector<PP>  VPP ;
#define  MP make_pair
#define PB push_back
#define F first
#define S second

ll mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}


int main()
{

freopen("1s.txt","r",stdin); freopen("1lo.txt","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(0);


ll  i , j , k , l  , n;

int t  , r , w , c ;
cin >> t ;
int tt = 0 ;int ans ;
while(t--)
{
tt++;

cin >> r >> c >>w      ; 





if(c==w||w==1) ans = c ;

else {
	
	if(c%w==0)  ans = 0 ;
	else ans = 1 ;
	ans += c/w + w - 1 ;
	
}

ans = ans + c/w*(r-1) ;

cout<<"Case #"<<tt<<": "<<ans<<endl;

}


return 0 ;


}

