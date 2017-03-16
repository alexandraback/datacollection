#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define uint unsigned int
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define reads(_s) getline(cin,_s)
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(_i,a,b) for (int _i(a),_l(b); _i<=_l; ++_i)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1050000000
#define INFL INF*1ll*INF
#define PI 3.141592653589
#define eps 1e-10
#define MOD 1000000023
#define PRIME 312427

using namespace std;

const int LIMIT=20000000;

bool used[20000005];
int dyn[20000005];
int prv[20000005];

char buf[20];

void solve_test() {
	int n;
	scanf("%d",&n);
	printf("%d\n",dyn[n]);
}

void precalc() {
	fill(dyn,dyn+1000005,INF);
	dyn[1]=1;
	prv[1]=-1;
	used[1]=true;
	queue<pii> Q;
	Q.push(mp(1,1));
	while (!Q.empty()) {
		pii now(Q.front());
		Q.pop();
		int step(now.Y);
		int to(now.X+1);
		if (to<LIMIT && dyn[to]>step+1) {
			dyn[to]=step+1;
			prv[to]=now.X;
			if (!used[to]) {
				// cout<<to<<" "<<step+1<<endl;
				used[to]=true;
				Q.push(mp(to,step+1));
			}
		}
		to=now.X;
		while (to%10==0) to/=10;
		string q(to_string(to));
		reverse(all(q));
		int c(atoi(q.c_str()));
		to=c;
		if (to<LIMIT && dyn[to]>step+1) {
			dyn[to]=step+1;
			prv[to]=now.X;
			if (!used[to]) {
				// cout<<to<<" "<<step+1<<endl;
				used[to]=true;
				Q.push(mp(to,step+1));
			}
		}
	}
}

void solve() {
	precalc();
	int tst;
	scanf("%d\n",&tst);
	FOR(i,1,tst) {
		printf("Case #%d: ",i);
		solve_test();
	}
}

int main() {
#ifdef yeti
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#endif

#ifdef yeti
    clock_t tm = clock();
    cerr<<setprecision(10);
#endif
    solve();
#ifdef yeti
    cerr<<setprecision(3)<<(clock()-tm+0.)/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}