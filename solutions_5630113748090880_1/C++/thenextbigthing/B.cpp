#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 3000
#define INF 1e18
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define F first
#define S second

using namespace std;

ll gcd(ll n1,ll n2){
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
int cnt[upperlimit+1];
vector <int> temp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("B-large.in","r",stdin);
	freopen("outlargeB.txt","w",stdout);

    int t,i,j,n,a;
    cin>>t;
    for(int k1=1;k1<=t;k1++){
        for(i=0;i<=upperlimit;i++)cnt[i]=0;
        cin>>n;
        temp.clear();
        for(i=0;i<n;i++)for(j=1;j<2*n;j++){
        	cin>>a;
        	cnt[a]++;
        }
        for(i=0;i<=upperlimit;i++)if(cnt[i]%2==1){
        	temp.pb(i);
        }
        cout<<"Case #"<<k1<<":";
        for(i=0;i<n-1;i++)cout<<" "<<temp[i];
        cout<<" "<<temp[n-1]<<endl;
    }

	return 0;
}
