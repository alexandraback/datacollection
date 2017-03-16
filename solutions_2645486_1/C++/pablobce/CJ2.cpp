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
#define RAYA cout<<"-----------------"<<endl;
#define DBG(x) cout<<#x<<":"<<(x)<<endl;
#define all(v) v.begin(),v.end()


typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

const int MAXN=10240;

int num[MAXN];



int main(){
	freopen("CJ2.out","w",stdout);
	int T;
	cin>>T;
	tint t;
	int e,r,n;
	forn(caso,T){
		cin>>e>>r>>n;
		vector <pii> v;
		set <int> us;
		forn(i,n){
			cin>>num[i];
			v.pb(mp(-num[i],i));
		}
		tint res=0;
		sort(all(v));
		fore(i,v){
			set<int>::iterator sig=us.upper_bound (v[i].y);   
			int tengoqguardar=0;
			if(sig!=us.end())tengoqguardar=max(0,e-r*(*sig-v[i].y));
		
			
			int tengoalosumo=e;
			if(sig!=us.begin()){
				set<int>::iterator ant=--sig;
				tengoalosumo=min(e,r*(v[i].y-*ant));

			}
			
			if(tengoalosumo>tengoqguardar)res+= (tengoalosumo-tengoqguardar)*(tint)(-v[i].x);
			us.insert(v[i].y);
		}
		
		
		cout<<"Case #"<<1+caso<<": "<<res<<endl;
	}	
    return 0;
}
