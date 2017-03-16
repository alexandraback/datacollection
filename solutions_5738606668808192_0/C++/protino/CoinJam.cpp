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

ll n,c,cnt;
set<string> m;

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
	for(int p=1;p<=t;p++){
		cout<<"Case #"<<p<<": "<<"\n";
		m.clear();
		cnt=0;
		cin>>n>>c;
		n--;										// to match the maths of x^(n-1s)
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<n-8;j++){
				for(ll k=n-8;k<n;k++){
					
					if(cnt<c){
						// cout<<i<<" "<<j<<" "<<k<<"\n";
						string a="";
						bool b[n+1];
						for(int p=0;p<=n;p++){
							a+="0";
							b[p]=false;
						}
						a[n-0]='1';if(b[n]) continue;
						b[n]=true;
						a[k]='1';if(b[k]) continue;
						b[k]=true;
						a[n-i]='1';if(b[n-i]) continue;
						b[n-i]=true;
						a[k-i]='1';if(b[k-i]) continue;
						b[k-i]=true;
						a[n-j]='1';if(b[n-j]) continue;
						b[n-j]=true;
						a[k-j]='1';if(b[k-j]) continue;
						b[k-j]=true;
						a[n-k]='1';if(b[n-k]) continue;
						b[n-k]=true;
						a[0]='1';if(b[0]) continue;
						b[0]=true;
						if(m.find(a)==m.end()){
							cnt++;
							m.insert(a);
							cout<<a;
							for(ll i=2;i<=10;i++) cout<<" "<<(ll)(1LL+(ll)pow(i,n-k));
							cout<<"\n";
						}
					}
				}
			}
		}
	}
	return 0;
}