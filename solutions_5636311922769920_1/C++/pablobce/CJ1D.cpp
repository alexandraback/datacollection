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
#define all(n) n.begin(),n.end()



int main(){
	int T; cin>>T;
	tint K,C,S;
	forn(caso,T){
		cin>>K>>C>>S;
		if(C*S<K)cout<<"Case #"<<caso+1<<": IMPOSSIBLE"<<endl;
		else{
			cout<<"Case #"<<caso+1<<":";
			tint dig=K;
			forn(i,S){
				if(dig==0)break;
				tint n=0;
				forn(j,C){
					dig--;
					dig=max(dig,0ll);
					n*=K;
					n+=dig;
		
				}
				cout<<" "<<1+n;
			}
			cout<<endl;
		}
	}
    return 0;
}
