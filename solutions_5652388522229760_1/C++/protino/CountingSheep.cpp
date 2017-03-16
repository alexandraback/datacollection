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

int main(){
	fastscan	
	ll t;
	cin>>t;
	for(ll p=1;p<=t;p++){
		ll n;
		cin>>n;
		if(n==0) cout<<"Case #"<<p<<": "<<"INSOMNIA"<<"\n";
		else{
			bool b[10];
			for(ll i=0;i<10;i++) b[i]=false;
			for(ll i=1;;i++){
				ll x=n*i;
				while(x!=0){
					b[x%10]=true;
					x/=10;
				} 
				bool t=true;
				for(int j=0;j<10;j++){
					if(!b[j]) t=false;
				}
				if(t){
					cout<<"Case #"<<p<<": "<<n*i<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}