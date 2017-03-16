#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-9;
const int INF = (1<<30)-1;

struct car{
	double s;
	double p;
	car(double s = 0, double p = 0){
		this->s = s; this->p = p;
	}
};

int tc, n;

void copyV (const vector<car>& f, vector<car>& s){
	s.clear();
	REP(i,SI(f)) s.PB(f[i]);
}

void getMinCollT (const vector<car>& c, int& i1, int& j1, double& t, double currT){
	t = 1e30;
	double res = 1e30;
	REP(i,SI(c))
		REP(j,SI(c)) if (c[j].s - c[i].s > EPS){
			double tt = (c[i].p - c[j].p - 5) / (c[j].s - c[i].s);
			if (tt - currT >= -EPS && tt < t){
				t = tt;
				i1 =i;
				j1 = j;
			}
	}
}

bool canput (const car& c, const vector<car>& vc, const double time){
	REP(i,SI(vc)){
		if (abs (c.p+time*c.s - (vc[i].p+time*vc[i].s)) < 5.-EPS) return false;
	}
	return true;
}

double recit (vector<car> l, vector<car> r, double time, int thesame){
	int i1, j1, i2, j2;
	double t1, t2;
	getMinCollT (l, i1, j1, t1, time);
	getMinCollT (r, i2, j2, t2, time);
	if (t1 > 1e20 && t2 > 1e20) return 1e20;
	if (t1 > t2){
		swap (l, r);
		swap (i1, i2);
		swap (j1, j2);
		swap (t1, t2);
	}

	int nts;

	double bestans = t1;
	if (bestans - time < EPS) nts = thesame+1;
	else nts = 0;

	if (nts > 10) return bestans;

	vector<car> ll, rr;

	copyV (l, ll); copyV (r, rr);
	if (canput (ll[i1], rr, t1)){
		rr.PB(ll[i1]);
		ll.erase(ll.begin()+i1);
		bestans = MAX(bestans, recit (ll, rr, t1, nts));
	}

	copyV (l, ll); copyV (r, rr);
	if (canput (ll[j1], rr, t1)){
		rr.PB(ll[j1]);
		ll.erase(ll.begin()+j1);
		bestans = MAX(bestans, recit (ll, rr, t1, nts));
	}

	return bestans;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> tc;
	REP(ic,tc){
		vector<car> l, r;
		cin >> n;
		REP(i,n){
			string lane;
			double s, p;
			cin >> lane >> s >> p;
			if (lane=="L") l.PB(car(s,p));
			else r.PB(car(s,p));
		}
		double res = recit (l, r, 0, 0);
		cout << "Case #" << ic+1 << ": ";
		if (res > 1e19) cout << "Possible" << endl;
		else printf ("%.10lf\n", res);
	}
	return 0;
};