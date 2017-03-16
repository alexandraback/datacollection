#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

#define SET(v,i) memset(v,i,sizeof(v));
#define FOR(i,n,k) for(int i=n;i<k;++i)
#define WHILE(i,n) while(i<n)
#define RI(i) scanf("%d",&i);
#define RS(i) scanf("%s",i);
#define RF(i) scanf("%lf",&i);
#define RL(i) scanf("%lld",&i);
#define OPEN(s) freopen(s,"r",stdin);
#define CLOSE(s) freopen(s,"w",stdout);

const int INF=0x3F3F3F3F;
const int MAXN=100001;
typedef long long int i64;
typedef pair<int,int> pii;
typedef pair<string,int> psi;

i64 r,t;

bool check(i64 n){
	i64 test=(n*(2*r+1))+(2*n*(n-1));
	return test <= t;
}

int main(){
	#ifdef DM1_MACHINE
		OPEN("FILE.in");
		CLOSE("FILE.out");
	#endif
	int T; RI(T);
	FOR(ic,1,T+1){
		RL(r); RL(t);
		i64 inf=1,sup=1e9;
		//(n+1)(2r+1)+2*n*(n-1)
		while(sup-inf>1){
			i64 n=(inf+sup)>>1;	
			if(check(n))
				inf=n;
			else
				sup=n;
		}
		printf("Case #%d: %lld\n",ic,check(sup)?sup:inf);
	}
	return 0;
}


////////////////////////////////////////////
/////////////Code by David Moran////////////
/////////////////////////////P=NP///////////
