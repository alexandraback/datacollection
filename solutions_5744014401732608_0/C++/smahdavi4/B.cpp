// IN THE NAME OF ALLAH
#include<bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define F(i,a,b) for(ll i=(a) ; i<=(b) ; i++)
#define PI 3.1415926535897932384626433832795
#define eps 0.000001
using namespace std;
typedef unsigned long long ll;
typedef float ld;
const ll M=1e5+100;

ll pw[60],n,k,a[60][60];
vector<ll> v[60];

void in(){
	cin>>n>>k;
}

void clr(){
	F(i,0,59) F(j,0,59) a[i][j]=0;
	//memset(a,0,sizeof a);
	F(i,0,59) v[i].clear();
}

void comp(ll x){
	F(i,x+1,n){
		v[x].pb(i);
	}
}

void make(){
	F(i,1,n){
		if(!v[i].empty()){
			F(j,0,v[i].size()-1){
				a[i][v[i][j]]=1;
			}
		}
	}
}

void solve(){
	if(k>pw[n-2]){
		cout<<"IMPOSSIBLE"<<endl;
		return ;
	}
	cout<<"POSSIBLE"<<endl;
	F(i,2,n-1){
		comp(i);
	}
	if(k==pw[n-2]) comp(1);
	else{
		for(ll i=0,j=n-1 ; j>=2 ; i++,j--){
			if(k&(pw[i])){
				v[1].pb(j);
			}
		}
	}
	make();
	F(i,1,n){
		F(j,1,n) cout<<a[i][j];
		cout<<endl;
	}
}



int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//cout << setprecision(22) << fixed;
ios::sync_with_stdio(false);

pw[0]=1; F(i,1,59) pw[i]=2*pw[i-1];

ll tst; cin>>tst;
F(ii,1,tst){
	clr();
	in();
	cout<<"Case #"<<ii<<": ";
	solve();
}





return 0;   
}
