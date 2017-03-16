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



int main(){
	freopen("CJ2.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		ldouble C,F,X;
		cin>>C>>F>>X;
		ldouble total=0;
		ldouble prod=2;
		while(X/prod>C/prod+X/(prod+F)){
			total+=C/prod;
			prod+=F;
		}
		total+=X/prod;
		printf("Case #%d: %.7f\n",caso+1,(double)total);
	}	
    return 0;
}
