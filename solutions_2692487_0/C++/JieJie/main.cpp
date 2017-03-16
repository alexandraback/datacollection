#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>
#include <iomanip>
#include <map>      // std::pair

#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SIZE(v) ((int)(v).size())
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
typedef long long ll;
typedef std::pair<ll,ll> PII;
//typedef vector<PII> VPII;
using namespace std;

ll v[10001];
/*
void solve(){
	ll E,R,N,maxv=0,sum=0;
	CLR(v,0);
	cin>>E>>R>>N;
	FOR(i,0,N){
		cin>>v[i];
		sum+=v[i];
		if (maxv<v[i])
			maxv=v[i];
	}
	if (R>=E)	cout<<sum*R<<endl;
	else{
		cout<<sum*R+maxv*(E-R)<<endl;
	}
}*/

ll E,R,N,maxres;
void go(int s,int ec,int sum){
	if (s>0){
		ec+=R;
		if (ec>E)	ec=E;
	}
	if (s==N-1){
		sum+=ec*v[s];
		if (maxres<sum)
			maxres=sum;
		return;
	}
	ll p=ec;
	for (ll i=0;i<=p;i++){
		//sum+=i*v[s];
		//ec-=i;
		go(s+1,ec-i,sum+i*v[s]);
		//ec+=i;
		//sum-=i*v[s];
	}
}

void solve(){
	int a,n,t[101];
	cin>> a >> n;
	FOR(i,0,n)	cin>>t[i];
	sort(t,t+n);
	int sum=a,res=0;
	int minres=n;
	if (sum==1){
		cout<<n<<endl;
		return;
	}
		
	FOR(i,0,n){
		if (sum>t[i]){
			sum+=t[i];
		}
		else{
			if (res+n-i<minres)	minres=res+n-i;
			do{
			
				res++;
				sum=2*sum-1;
			}while (sum<=t[i]);
			if (sum>t[i])	{
				sum+=t[i];
			}
		}
	}
	if (res<minres)	minres=res;
	cout<<minres<<endl;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int t;
	cin>>t;
	FOE(i,1,t){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;

}	