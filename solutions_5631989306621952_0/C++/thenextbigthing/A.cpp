#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define upperlimit 1000100
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
int arr[upperlimit+1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("A-small-attempt0.in","r",stdin);
	freopen("outsmallA.txt","w",stdout);

    int t,k,i,j,mx;
    string s,answer;
    cin>>t;
    for(int k1=1;k1<=t;k1++){
        cin>>s;
        mx=-1;
        k=s.size();
        answer="";
        for(i=0;i<k;i++)arr[i]=s[i]-'A';
        for(i=0;i<k;i++){
            if(arr[i]>=mx){
                mx=arr[i];
                answer=s[i]+answer;
            }
            else answer=answer+s[i];
        }
        cout<<"Case #"<<k1<<": "<<answer<<endl;
    }

	return 0;
}
