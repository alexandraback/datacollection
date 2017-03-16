// IN THE NAME OF ALLAH
#include<bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define F(i,a,b) for(ll i=(a) ; i<=(b) ; i++)
#define PI 3.1415926535897932384626433832795
#define eps 0.000001
using namespace std;
typedef long long ll;
typedef float ld;
const ll M=1e5+100;

vector<pair<string,string> > v,v1,v2;
ll n,mx;

inline bool che(pair<string,string> x1,pair<string,string> x2,pair<string,string> x3){
	if((x3.X==x1.X && x3.Y==x2.Y) || (x3.X==x2.X && x3.Y==x1.Y)) return false;
	return true;
}

inline bool ch(ll x){
	ll s=x;
	v1.clear();
	v2.clear();
	for(ll i=0 ; i<n ; i++){
		if(x%2==1){
			v1.pb(v[i]);
		}
		else v2.pb(v[i]);
		x/=2;
	}
	if(!v1.empty() && v1.size()>=3){
		F(i,0,v1.size()-1){
			F(j,i+1,v1.size()-1){
				F(k,j+1,v1.size()-1){
					if(!che(v1[i],v1[j],v1[k]) || !che(v1[i],v1[k],v1[j]) || !che(v1[k],v1[j],v1[i])) return false;
				}
			}
		}
	}
	if(!v2.empty()){
		F(i,0,v2.size()-1){
			bool mark=false;
			if(!v1.empty() && v1.size()>1){
				F(j,0,v1.size()-1){
					F(k,j+1,v1.size()-1){
						if(!che(v1[j],v1[k],v2[i])) mark=true;
					}
				}
			}
			if(!mark) return false;
		}
	}
	//cout<<s<<"   sss"<<endl;
	return true;
}

void in(){
	string xx,x;
	cin>>n;
	F(i,0,n-1) cin>>x>>xx,v.pb({x,xx});
}

void clr(){
	v.clear();
	mx=0;
}

void solve(){
	F(i,1,(1<<n)-1){
		if(ch(i)){
			mx=max(mx,n-__builtin_popcount(i));
		}
	}
	cout<<mx;



}







int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//cout << setprecision(22) << fixed;
ios::sync_with_stdio(false);


ll tst; cin>>tst;
F(ii,1,tst){
	clr();
	in();
	cout<<"Case #"<<ii<<": ";
	solve();
	cout<<endl;
}





return 0;   
}
