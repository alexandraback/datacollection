#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <string>
using namespace std;

#define forsn(i,s, n) for(int i=(int)s; i<(int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define fore(i,n) forn(i,n.size())
#define fori(i, n) for(typeof n.begin() i=n.begin(); i!=n.end();i++)
#define RAYA cout<<"-----------------"<<endl;
#define dbg(x) cout<<#x<<":"<<(x)<<endl;

typedef long long int tint;
typedef long double ldouble;
typedef  pair <tint,tint> pii;
typedef  pair <string,string> pss;
typedef  pair <tint,pii> piii;
typedef  pair <piii,pss> piiiss;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(n) n.begin(),n.end()

const tint INF=2000000000;

string s[20][2];
bool v[20][2];

int count(int n){
	int res=0;
	while(n>0){
		res+=n%2;
		n/=2;
	}
	return res;
}


int main(){
	int T;
	cin>>T;
	int n;
	forn(caso,T){
		cin>>n;
		forn(i,n)cin>>s[i][0]>>s[i][1];
		int res=0;
		forn(mask,(1<<n)){
			forn(i,n)forn(j,2)v[i][j]=false;
			forn(i,n){
				if((1<<i) & mask){
					forn(k,n)forn(j,2){
						if(s[k][j]==s[i][j]) v[k][j]=true;
					}
				}
			}
			bool flag=true;
			forn(i,n)forn(j,2)if(!v[i][j])flag=false;
			if(flag)
				res=max(res,n-count(mask));
		}
		cout<<"Case #"<<caso+1<<": "<<res<<endl;
	}
    return 0;
}
