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

const int MAX=100;

bool criba[MAX];
vector<int> p;


int f(tint mask,tint base){
	double num=0;
	double expo=1;
	for(tint i=0; pow(2,i)<=mask;i++){
		if(tint(pow(2,i)) & mask) num+=expo;
		expo*=base;
	}
	for(int j=0;j<p.size() && p[j]<num;j++){
		tint primo=p[j];
		tint n=0;
		tint exp=1;
		for(tint i=0; pow(2,i)<=mask;i++){
			if(tint(pow(2,i)) & mask){
				n+=exp;
				n%=primo;
			}
			exp*=base;
			exp%=primo;
		}
		if(n==0) return primo;
	}
	return -1;
}

int main(){
	cout<<"Case #1:"<<endl;
	forn(i,MAX)criba[i]=true;
	forsn(i,2,MAX)if(criba[i]){
		p.pb(i);
		for(int aux=2*i;aux<MAX;aux+=i)criba[aux]=false;
	}
	int T; cin>>T;
	int N; cin>>N;
	int J; cin>>J;
	int res[11];
	for(tint aux=0; aux<pow(2,N-2) && J>0; aux++){
		tint mask=pow(2,N-1)+2*aux+1;
		bool flag=false;
		forsn(base,2,11){
			int r=f(mask,base);
			if(r==-1){flag=true;break;}
			res[base]=r;
		}
		if(flag) continue;
		for(tint i=N-1;i>=0;i--)cout<<bool(mask & tint(pow(2,i)));
		forsn(base,2,11) cout<<" "<<res[base];
		cout<<endl;
		J--;
	}
    return 0;
}
