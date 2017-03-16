///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

double r,t;

bool can(tint mid){
	///puedo con mid arcos negros?
//cout<<"pintura: "<<t<<endl;
//cout<<"r: "<<r<<endl;
//cout<<"mid: "<<mid<<endl;
//cout<<"cantidad necesaria para mid anillos :"<<(PI * r * r * mid * (2 * mid + 1))<<endl;
//cout<<endl;
	return ((1.0 * mid + 1.0 * 2 * mid * r + 1.0 * 2 * mid * (mid - 1)) <= t);
}

int main(){
freopen("AsmallInput.txt","r",stdin);
freopen("AsmallOutput.txt","w",stdout);
	int TC;cin>>TC;
	formn(tc,1,TC+1){
		/// r = radio de los aros.
		/// t = cantidad de pintura.
		tint rr,tt; cin>>rr>>tt;
		r = (double) rr; t = (double) tt;
		tint lo = 1;
		tint hi = 1000000000000000000LL;
		while(lo < hi - 1){
			/// lo puedo, hi es mucho.
			tint mid = (lo + hi)/2;
			if(can(mid)) lo = mid;
			else hi = mid;
		}
		cout<<"Case #"<<tc<<": "<<lo<<endl;
	}
    return 0;
}
