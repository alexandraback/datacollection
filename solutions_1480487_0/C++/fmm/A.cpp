#include <bits/stdc++.h>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;

#define eps 1e-10
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL

#define fr(x,y,z) for(int(x)=(y);(x)<(z);(x)++)
#define rep(x,n) fr(x,0,n)
#define cast(x,t) *({stringstream ss;static t __ret;ss<<x,ss>>__ret;&__ret;})

#define dbg(x) cout << #x << " == " << x << endl
#define print(x) cout << x << endl
#define _ << " , " <<

double func(double f, vector<int> s, int bad, int X) {
	double res = 0;
	rep(i,s.size()) if(i != bad) {
		res += max(0.0, (f-s[i])/X);
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++) {
		int N;
		cin >> N;
		vector<int> s(N);
		double X = 0;
		rep(i,N) cin >> s[i], X += s[i];
		printf("Case #%d:", caso);
		rep(i,N) {
			double res = 1.0, take = res;
			rep(k,1000) {
				double nres = res - take;
				if(nres >= 0.0 && func(s[i] + X * nres, s, i, X) >= (1-nres))
					res = nres;
				else
					take /= 2;
			}
			printf(" %.6lf",res*100);
		}
		puts("");
	}
	return 0;
}


