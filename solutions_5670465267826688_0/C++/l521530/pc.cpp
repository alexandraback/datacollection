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
#define N 40010
int a[4][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1},
};
inline int sg(int i){return i>0?1:-1;}
inline int abs(int i){return i>0?i:-i;}
inline int multi(int i, int j){
	return sg(i)*sg(j)*a[abs(i)-1][abs(j)-1];
}
int n;
LL x;
char c[N];
void input(){
	cin >> n >> x;
	scanf("%s", c);
}

bool goodAll(){
	int r=1;
	for(int i=0; i<n; i++) r = multi(r, c[i]-'i'+2);
	int k=1;
	for(int i=0; i<x%4; i++) k = multi(k,r);
	//printf("k=%d\n", k);
	return k==-1;
}

bool solve(){
	REP(i,n) c[i+n+n+n] = c[i+n+n] = c[i+n] = c[i];
	if(!goodAll()) return false;
	int mnl=-1, r=1;
	for(int i=0; i<4*n; i++){
		r = multi(r, c[i]-'i'+2);
		if(r==2){mnl = i+1; break;}
	}
	int mnr=-1;
	r=1;
	for(int i=0; i<4*n; i++){
		r = multi(c[4*n-i-1]-'i'+2, r);
		//printf("r=%d\n", r);
		if(r==4){mnr = i+1; break;}
	}
	//printf("%d %d \n",mnl,mnr);
	return (mnl>0 && mnr>0 && mnl+mnr<=n*x);
}

int main() {
	int zn;
	RI(zn);
	REP(zi,zn){
		input();
		printf("Case #%d: %s\n", zi+1, solve()?"YES":"NO");
	}
    return 0;
}

