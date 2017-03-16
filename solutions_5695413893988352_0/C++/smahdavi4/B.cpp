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


string t1,t2;
vector<ll> v1,v2;

bool fi(ll x,string s){
	for(ll i=s.length()-1 ; i>=0 ; i--){
		if(s[i]!='?'){
			if((x%10)!=(s[i]-'0')) return false;
		}
		x/=10;
	}
	if(x) return false;
	return true;
}

void in(){
	cin>>t1>>t2;
}

void clr(){
	v1.clear();
	v2.clear();
}

void solve(){
	F(i,0,999){
		if(fi(i,t1)) v1.pb(i);
	}
	F(i,0,999){
		if(fi(i,t2)) v2.pb(i);
	}	
	ll mx1=1e10,mx2=1e12,e=1e10;
	F(i,0,v1.size()-1){
		F(j,0,v2.size()-1){
			if(abs(v1[i]-v2[j])<e){
				mx1=v1[i];
				mx2=v2[j];
				e=abs(v1[i]-v2[j]);
			}
			else if(abs(v1[i]-v2[j])==e){
				if((v1[i]+v2[j])<(mx1+mx2) || mx2>v2[j]){
			    	mx1=v1[i];
				    mx2=v2[j];
				    e=abs(v1[i]-v2[j]);					
				}
			}
		}
	}
	string y1="",y2="";
	for(ll i=t1.length()-1 ; i>=0 ; i--){
		y1+=((mx1%10)+'0');
		mx1/=10;
	}
	reverse(y1.begin(),y1.end() );
	cout<<y1;
	cout<<" ";
	for(ll i=t2.length()-1 ; i>=0 ; i--){
		y2+=((mx2%10)+'0');
		mx2/=10;
	}
	reverse(y2.begin(),y2.end() );
	cout<<y2;
	//cout<<mx1<<" "<<mx2;
	
	
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
	//printf("Case #%lld: ",ii);
	solve();
	cout<<endl;
}





return 0;   
}
