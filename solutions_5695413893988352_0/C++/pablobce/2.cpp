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

string C,J;



piiiss f(int pos){
	if(pos==C.size()){
		return mp(mp(abs(stoll(C)-stoll(J)),mp(stoll(C),stoll(J))),mp(C,J));
	}
	if(C[pos]=='?' && J[pos]=='?'){
		C[pos]='0';
		J[pos]='0';
		piiiss res= f(pos);
		C[pos]='1';
		res=min(res,f(pos));
		C[pos]='0';
		J[pos]='1';
		res=min(res,f(pos));
		J[pos]='?';
		C[pos]='?';
		return res;
	}
	if(C[pos]!='?' && J[pos]=='?'){
		J[pos]=C[pos];
		piiiss res= f(pos);
		if(C[pos]!='0'){
			J[pos]=char(C[pos]-1);
			res=min(res,f(pos));
		}
		if(C[pos]!='9'){
			J[pos]=char(C[pos]+1);
			res=min(res,f(pos));
		}
		J[pos]='?';
		return res;
	}
	if(C[pos]=='?' && J[pos]!='?'){
		C[pos]=J[pos];
		piiiss res= f(pos);
		if(J[pos]!='0'){
			C[pos]=char(J[pos]-1);
			res=min(res,f(pos));
		}
		if(J[pos]!='9'){
			C[pos]=char(J[pos]+1);
			res=min(res,f(pos));
		}
		C[pos]='?';
		return res;
	}
	if(C[pos]!='?' && J[pos]!='?'){
		if (C[pos]==J[pos]){
			return f(pos+1);
		}else{
			string CC=C;
			string JJ=J;
			if(C[pos]>J[pos]){
				fore(i,CC)if(CC[i]=='?')CC[i]='0';
				fore(i,JJ)if(JJ[i]=='?')JJ[i]='9';
			}
			if(J[pos]>C[pos]){
				fore(i,CC)if(CC[i]=='?')CC[i]='9';
				fore(i,JJ)if(JJ[i]=='?')JJ[i]='0';
			}
			return mp(mp(abs(stoll(CC)-stoll(JJ)),mp(stoll(CC),stoll(JJ))),mp(CC,JJ));
		}
	}
}

int main(){
	int T;
	cin>>T;
	forn(caso,T){
		cin>>C>>J;
		piiiss res=f(0);
		cout<<"Case #"<<caso+1<<": "<<res.s.f<<" "<<res.s.s<<endl;
	}
    return 0;
}
