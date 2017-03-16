#include<bits/stdc++.h>
using namespace std;
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define mp make_pair // useful for working with pairs
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define present(c,x) ((c).find(x) != (c).end())
#define ll long long
#define fastscan ios_base::sync_with_stdio(0);cin.tie(NULL); 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

ll po(ll a,ll b){
	if(b==0) return 1;
	if(b==1) return a;
	ll x=po(a,b/2);
	if(b%2==0) return (x*x);
	return (x*x*a) ;
}

int main(){
	fastscan	
	ll t;
	cin>>t;
	for(ll p=1;p<=t;p++){
		cout<<"Case #"<<p<<": ";
		ll k,c,s;
		cin>>k>>c>>s;
		if((k+c-1)/c<=s){
			for(int i=0;i<k;){
				int j;
				ll ans=0;
				for(j=i;j<i+c&&j<k;j++){
					ans+=j*po(k,c-1-j+i);
				}
				i=j;
				cout<<ans+1<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<"IMPOSSIBLE"<<"\n";
		}
	}
	return 0;
}