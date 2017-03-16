#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <set>
#include <limits>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;


string C, J, aC, aJ, tC, tJ;
ll adif;

ll toLL(string x){
	ll r=0;
	FOR(i,0,x.length()){
		r*=10;
		r+=x[i]-'0';
	}
	return r;
}


void solve(int pos, int state){
	if(pos==C.length()){
		ll c = toLL(tC);
		ll j = toLL(tJ);
		if(abs(c-j)<adif){
			adif = abs(c-j);
			aC = tC;
			aJ = tJ;	
		}
	}else{
		if(state == 1){
			if(C[pos]=='?')
				tC[pos] = '9';
			if(J[pos]=='?')
				tJ[pos] = '0';
			solve(pos+1, 1);
			if(C[pos]=='?')
				tC[pos] = '?';
			if(J[pos]=='?')
				tJ[pos] = '?';
		}
		if(state == 2){
			if(C[pos]=='?')
				tC[pos] = '0';
			if(J[pos]=='?')
				tJ[pos] = '9';
			solve(pos+1, 2);
			if(C[pos]=='?')
				tC[pos] = '?';
			if(J[pos]=='?')
				tJ[pos] = '?';
		}
		if(state == 0){
			if(C[pos] != '?' && J[pos]!='?'){
				if(C[pos]==J[pos]) solve(pos+1, 0);
				if(C[pos]<J[pos]) solve(pos+1, 1);
				if(C[pos]>J[pos]) solve(pos+1, 2);
			}else if(C[pos] == '?' && J[pos] == '?'){
				tC[pos]=tJ[pos]='0';
				solve(pos+1,0);
				tJ[pos]='1';
				solve(pos+1,1);
				tJ[pos] = '0';
				tC[pos] = '1';
				solve(pos+1,2);
				tC[pos] = tJ[pos] = '?';
			}else if(C[pos]=='?'){
				if(J[pos]>='1'){
					tC[pos] = J[pos]-1;
					solve(pos+1,1);
				}
				tC[pos] = J[pos];
				solve(pos+1,0);
				if(J[pos]<='8'){
					tC[pos] = J[pos]+1;
					solve(pos+1,2);
				}
			}else{
				if(C[pos]>='1'){
					tJ[pos] = C[pos]-1;
					solve(pos+1,2);
				}
				tJ[pos] = C[pos];
				solve(pos+1,0);
				if(C[pos]<='8'){
					tJ[pos] = C[pos]+1;
					solve(pos+1,1);
				}
			}
		}
	}
}

int main(){
	int TC; cin>>TC;
	FOR(tc,1,TC+1){
		cin>>C>>J;
		tC = aC = C;
		tJ = aJ = J;
		adif = LONG_MAX;
		solve(0,0);	
		cout<<"Case #"<<tc<<": "<<aC<<" "<<aJ<<endl;
	}
}

