#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define pr(a) printf("%d",a)
#define prn(a) printf("%d\n",a)
#define scll(a) scanf("%lld",&a)
#define prll(a) printf("%lld",a)
#define prlln(a) printf("%lld\n",a)
typedef long long LL;

pair<string,string> p[25];
bool tr[25];
bool isvalid(int n) {
	set<string> s1;
	set<string> s2;
	for(int i=0;i<n;++i) {
		if(tr[i]) {s1.insert(p[i].F);s2.insert(p[i].S);}
	}
	for(int i=0;i<n;++i) {
		if(!tr[i]) {
			if(!s1.count(p[i].F) || !s2.count(p[i].S)) return false;
		}
	}
	return true;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int tt=1;tt<=t;++tt) {
		cout<<"Case #"<<tt<<": ";
		int n;
		cin>>n;
		int maxx = 0;
		repi(i,0,n)
		{
			string s1, s2;
			cin>>p[i].F>>p[i].S;
		}
		for(int i=0;i<(1<<n);++i) {
			for(int k=0;k<n;++k) tr[k] = (i&(1<<k));
			if(isvalid(n)) {
				int nu=0;
				repi(k,0,n) nu+=tr[k]; 
				maxx = max(maxx,n-nu);
			}
		}
		cout<<maxx<<endl;
	}
	return 0;
}