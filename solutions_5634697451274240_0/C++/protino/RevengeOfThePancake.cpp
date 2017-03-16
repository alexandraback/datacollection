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
	for(int p=1;p<=t;p++){
		ll ans=0;
		string a;
		cin>>a;
		ll i=a.size()-1;
		while(i>=0&&a[i]=='+') i--;
		while(i>=0){
			ans++;
			char c=a[i];
			while(i>=0 && a[i]==c) i--;
		}
		cout<<"Case #"<<p<<": "<<ans<<"\n";
	}
	return 0;
}