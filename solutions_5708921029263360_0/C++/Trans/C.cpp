//This is getting accepted!
#include<bits/stdc++.h>

using namespace std;

#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}

int a, b, c, s1[4][4], s2[4][4], s[4][4], s3[4][4][4], ans,T, tc, k;
vector<pair<pii, int> > day;

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("inp.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//#endif

	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> k;
//		cout << "here " << k << endl;
		day.clear();
		ans = 0;
		for (int i=1; i<=a; i++) {
			for (int j=1; j<=b; j++) {
				s[i][j] = 0;
				for (int m=1; m<=c; m++) {
					s1[i][m] = 0;
					s2[j][m] = 0;
					s3[i][j][m] = 0;
				}
			}
		}
		for (int i=1; i<=a; i++) {
			for (int j=1; j<=b; j++) if (s[i][j] < k) {
				for (int m=1; m<=c; m++) if (s[i][j] < k && s1[i][m] < k && s2[j][m] < k && !s3[i][j][m]) {
					ans++;
					day.pb(mp(mp(i, j), m));
					s3[i][j][m] = 1;
					s[i][j]++;
					s1[i][m]++;
					s2[j][m]++;
				}
			}
		}
		
		cout << "Case #" << ++tc << ": " << ans << endl;
		for (int i=0; i<sz(day); i++) {
			cout << day[i].FI.FI << " " << day[i].FI.SE << " " << day[i].SE << endl;
		}
	}


}

