// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset(x,0,(n)*sizeof(*x))
#define MS1(x,n) memset(x,-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}
int x,r,c;

bool solve(){
	if(r>c) swap(r,c);
	if(x>=7) return true;
	if(r*c%x) return true;
	if(x==1) return false;
	if(x==2) return false;
	if(x==3) return r==1;
	if(x==4) return r<=2;
	if(x==5){
		if(r<=2) return true;
		if(r==3) return c==5;
		return false;
	}
	if(x==6){
		if(r<=2) return true;
		if(r==3) return c==4;
		return false;
	}	
}

int main() {
	int zn;
	RI(zn);
	REP(zi,zn){
		RIII(x,r,c);
		printf("Case #%d: %s\n",zi+1,solve()?"RICHARD":"GABRIEL");
	}
    return 0;
}

