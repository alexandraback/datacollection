#include <bits/stdc++.h>

#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Ford(i,a,b) for (int i = (a); i >= (b); i--)
#define Rep(i,a) for (int i = 0; i < (a); i++)
#define Repd(i,a) for (int i = (int)(a) - 1; i >=0; i--)
#define PI (acos(0.0) * 2)
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define PII pair<int, int>
#define PIII pair<PII, int>
#define VI vector<int>
#define sz(a) ((int)a.size())
#define oo 1000000000
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(a,u,v) {cout << #a << " = "; For(_,u,v) cout << a[_] << ' '; cout << endl;}
#define MAXN 1000111
#define LL long long
#define Two(n) (1<<(n))
#define RESET(a,c) memset(a, c, sizeof(a))
using namespace std;
#define eps 1e-7

vector<PII> V;

int solve2() {
	if (sz(V) < 2) return 0;
	PII a = V[0], b = V[1];
	double a1 = 1.0*a.Y/360*(360-a.X), a2 = a1 + a.Y;
	double b1 = 1.0*b.Y/360*(360-b.X), b2 = b1 + b.Y;
	if (b1 + eps >= a2 ) return 1;
	if (a1 + eps >= b2) return 1;	
	return 0;
}

LL calc(PII a, double t, int by) {
	LL res = 0;
	double a1 = 1.0*a.Y/360*(360-a.X);

	if (abs(t-a1) < eps) return 0;	
	if (a1 > t + eps) {
		return 1;
	}
	t -= a1;
	LL d = t/a.Y;
	if (d*a.Y + eps < t) {
		res += d;
	} else if (a.Y < by) {
		res += d;
	} else {
		res += d-1;
	}
	return res;
}

LL solve() {
	int z = -1;
	if (sz(V) <= 2) z = solve2();
	LL res = sz(V);

	Rep(i,sz(V)) {
		LL rr = 0;
		PII a = V[i];
		double a1 = 1.0*a.Y/360*(360-a.X);
		Rep(j, sz(V)) {
			PII b = V[j];
			rr += calc(b, a1, a.Y);
		}
		res = min(res, rr);
	}
	return res;
}
int main() {
	int ntest;
	cin >> ntest;
	For(test,1,ntest) {
		int n;
		cin >> n;
		V.clear();
		For(i,1,n) {
			int d, len, m;
			cin >> d >> len >> m;
			Rep(i,len) {
				V.PB(MP(d, m+i));
			}
		}
		LL result = solve();
		cout << "Case #" << test << ": " << result << endl;
	}
}