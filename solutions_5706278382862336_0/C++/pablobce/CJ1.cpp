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
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define f first
#define s second

const tint INF=2000000000;

tint gcd(tint q, tint w){
	if(q>w)swap(q,w);
	if(q==0) return w;
	return gcd(w%q,q);	
}


int main(){
	freopen("CJ1.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		tint p,q;
		char c;
		cin>>p>>c>>q;
		tint g=gcd(p,q);
		p/=g;
		q/=g;
		tint n=q;
		while(n%2==0)n/=2;
		cout<<"Case #"<<1+caso<<": ";
		if(n!=1)cout<<"impossible"<<endl;
		else{
			tint res=0;
			while(p<q){
				res++;
				p*=2;
			}
			cout<<res<<endl;			
		}
	}	
    return 0;
}
