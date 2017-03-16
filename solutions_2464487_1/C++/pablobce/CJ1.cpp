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

typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

const tint INF=2000000000;
tint r;

tint f(tint n){
	return 2*r*n+2*n*n-n;
}


int main(){
	freopen("CJ1.out","w",stdout);
	int T;
	cin>>T;
	tint t;
	forn(caso,T){
		cin>>r>>t;
		tint mn=1;
		tint mx=min(INF,INF*INF/r);
		while(mx-mn>1){
			tint aux=(mn+mx)/2;
			if(f(aux)>t)mx=aux;
			else mn=aux;
		}
	cout<<"Case #"<<1+caso<<": "<<mn<<endl;
	}	
    return 0;
}
