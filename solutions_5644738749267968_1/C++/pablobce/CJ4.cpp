#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

#define forsn(i,s, n) for(int i=(int)s; i<(int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define fore(i,n) forn(i,n.size())
#define fori(i, n) for(typeof n.begin() i=n.begin(); i!=n.end();i++)
#define RAYA cout<<"-----------------"<<endl;
#define dbg(x) cout<<#x<<":"<<(x)<<endl;

typedef long long int tint;
typedef long double ldouble;
#define pdi pair <double,int>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(n) n.begin(),n.end()

const tint INF=2000000000;




int main(){
	freopen("CJ4.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int n; cin>>n;
		vector <double> a(n);
		vector <double> b(n);
		forn(i,n) cin>>a[i];
		forn(i,n) cin>>b[i];
		//sort(all(a));
		//sort(all(b));
		//int cont=0;
		//while(cont<n && a[cont]<b[n-1-cont]) cont++;
		vector <pdi> v;
		forn(i,n) v.pb(mp(a[i],-1));
		forn(i,n) v.pb(mp(b[i],1));
		int mx=0;
		int mn=0;
		int cant=0;
		sort(all(v));
		forn(i,2*n){
			cant+=v[i].s;
			mn=min(mn,cant);
			mx=max(mx,cant);
		}
		cout<<"Case #"<<caso+1<<": "<<n+mn<<" "<<mx<<endl;
	}	
    return 0;
}
