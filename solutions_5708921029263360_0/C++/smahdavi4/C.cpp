// IN THE NAME OF ALLAH
#include<bits/stdc++.h>
#define pb push_back
#define F(i,a,b) for(ll i=(a) ; i<=(b) ; i++)
#define PI 3.1415926535897932384626433832795
#define eps 0.000001
using namespace std;
typedef long long ll;
typedef float ld;
const ll M=11;

ll p1[M][M],p2[M][M],p3[M][M],X,Y,Z,k,n,mx,bui=-1;
struct tpl{ ll x,y,z;}tp;
vector <tpl> v;


void in(){
	cin>>X>>Y>>Z>>k;
}

void clr(){
	mx=0;
	bui=-1;
	memset(p1,0,sizeof p1);
	memset(p1,0,sizeof p2);
	memset(p1,0,sizeof p3);
	v.clear();
}

inline bool make(ll x){
	ll ct=0;
	memset(p1,0,sizeof p1);
	memset(p2,0,sizeof p2);
	memset(p3,0,sizeof p3);
	while(ct<n){
		if(x%2==1){
			p1[v[ct].x][v[ct].y]++;
			p2[v[ct].x][v[ct].z]++;
			p3[v[ct].y][v[ct].z]++;
			if(p1[v[ct].x][v[ct].y]>k || p2[v[ct].x][v[ct].z]>k || p3[v[ct].y][v[ct].z]>k) return false;
		}
		x/=2;
		ct++;
	}	
	return true;
}


void solve(){
	F(i,1,X) F(j,1,Y) F(t,1,Z){
		tp.x=i;
		tp.y=j;
		tp.z=t;
		v.pb(tp);
	} 
    n=v.size();
    for(ll i=1 ; i<(1<<n) ; i+=2){
    	if(__builtin_popcount(i)>bui){
    		if(make(i)) bui=__builtin_popcount(i),mx=i;
		}
	}
	cout<<bui<<endl;
	for(ll ct=0 ; ct<n ; ct++){
		if(mx%2==1){
			cout<<v[ct].x<<" "<<v[ct].y<<" "<<v[ct].z<<endl;
		}
		mx/=2;
	}
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
}





return 0;   
}
