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
#include <assert.h>

LL n;

LL rev(LL x){
	LL y = 0;
	while(x){
		y = y*10 + x%10;
		x /= 10;
	}
	return y;
}


int dig(LL x){
	int d=0;
	while(x){ x/=10; d++; }
	return d;
}

LL p10[16];

LL solve(){
	if(n<=11) return n;
	p10[0] = 1;
	for(int i=1; i<16; i++) p10[i] = p10[i-1]*10;
	int d = dig(n);
	LL D = p10[(d+1)/2];
	LL head = rev(n/D), tail = n%D;
	LL myans = head + tail - 2;
	if(head!=1) myans++;
	if(tail==0){
		n--;
		LL ans = solve();
		n++;
		return ans+1;
	}

	//for(int i=0; i<d; i++) printf("+%lld\n", p10[i/2] + p10[(i+1)/2] - 1);
	for(int i=0; i<d; i++) myans += p10[i/2] + p10[(i+1)/2] - 1; 
	//cout << n << ':' << myans << ',' << ans[n] << endl;
	return myans;
}

int main() {
	//pre();
	int zn;
	RI(zn);
	REP(zi,zn){
		cin >> n;
		LL myans = solve();
		printf("Case #%d: %lld\n", zi+1, myans);
	}
    return 0;
}

