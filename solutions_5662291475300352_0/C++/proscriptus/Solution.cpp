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
#define eps 1e-9
#define MOD 1000000023
#define PRIME 312427

using namespace std;

bool cmp(const pii& a, const pii& b) {
	if (a.X==b.X) return a.Y>b.Y;
	else return a.X<b.X;
}

void solve_test() {
	vector<pii> hikers;
	int n;
	scanf("%d",&n);
	rept(i,n) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		rept(i,b) {
			hikers.pb(mp(a,c+i));
		}
	}

	sort(all(hikers),cmp);
	int ans(INF);
	if (sz(hikers)<=1 || hikers[0].Y==hikers[1].Y) {
		// cout<<"CASE 1"<<endl;
		puts("0");
	} else {
		// cout<<"CASE 2"<<endl;
		if (hikers[0].Y>hikers[1].Y) {
			// cout<<"CASE 21"<<endl;
			double tm(360-hikers[0].X);
			tm*=hikers[0].Y;
			tm/=360;
			// cout<<tm<<endl;

			double hm(tm/hikers[1].Y*360);
			double delta(-hikers[1].X+hikers[0].X+360+360-hikers[0].X);
			if (delta==0) delta=360;
			if (hm+eps>delta) {
				puts("1");
			} else {
				puts("0");
			}
		} else {
			// cout<<"CASE 22"<<endl;
			double diff_sp(1./hikers[0].Y-1./hikers[1].Y);
			double dist(hikers[1].X-hikers[0].X);
			double tm(dist/360/diff_sp);

			double new_pos(hikers[0].X+tm/hikers[0].Y*360);
			if (new_pos-eps>360) {
				puts("0");
			} else {
				double tm(360-new_pos);
				tm*=hikers[1].Y;
				tm/=360;

				double hm(tm/hikers[0].Y*360);
				double delta(360+360-new_pos);
				if (hm+eps>delta) {
					puts("1");
				} else {
					puts("0");
				}
			}
		}
	}
}

void solve() {
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