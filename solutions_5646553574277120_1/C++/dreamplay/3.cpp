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

freopen("3s.txt","r",stdin); freopen("3so.txt","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(0);


ll t , c , d ,v , ans ;


cin >> t ;
ll tt = 0 ;
ll cur = 0 ;
ll in[150] , i , ind=0;

while(t--)
{
    tt++;ans=0;

cin >> c >> d >> v ;

for(i=0;i<d;i++) cin >> in[i] ; in[d]=10000000001;
sort(in,in+d);

cout<<"Case #"<<tt<<": ";

cur=ind=0 ;


while(1)
{
	
    if(cur>=v) break ;
	
		if(in[ind]<=cur+1) 
		{
			cur = cur + c*in[ind] ;
			ind++;
        }
	
	   else 
	   {
	   	ans++;
	   	cur += (cur+1)*c;
	   }
	
}




cout<<ans<<endl;

}




return 0 ;


}

