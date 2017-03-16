#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = ll(b)-1; i >= (a); i--)
#define MAPIT(i,c,k) for (auto i = (c).equal_range((k)).first; i!= (c).equal_range((k)).second; i++)

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end() 
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c, i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

pair<int, pair<string, string>> calcBetter(pair<int, pair<string, string>> old, string C, string J){
	ll Cs = stol(C);
	ll Js = stol(J);
	ll Xs = stol(old.yy.xx);
	ll Ys = stol(old.yy.yy);
	ll olddiff = abs(Xs - Ys);
	ll diff = abs(Cs - Js);

	if(diff < olddiff ||
	   (diff == olddiff && Cs < Xs) ||
	   (diff == olddiff && Cs == Xs && Js < Ys)){
		return {diff, {C, J}};
	} else {
		return old;
	}	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); 

	int n;
	cin >> n;


	FOR(t, 0, n){

		string C, J;
		cin >> C >> J;

		pair<int, pair<string, string>> erg = {10000, {"000", "999"}};

		FOR(a1, 0, 10){
			FOR(a2, 0, 10){
				FOR(a3, 0, 10){
					FOR(a4, 0, 10){
						FOR(a5, 0, 10){
							FOR(a6, 0, 10){
								string Cs = C, Js = J;
								if(C[0] == '?') Cs[0] = char(a1+'0');
								if(C[1] == '?') Cs[1] = char(a2+'0');
								if(C[2] == '?') Cs[2] = char(a3+'0');

								if(J[0] == '?') Js[0] = char(a4+'0');
								if(J[1] == '?') Js[1] = char(a5+'0');
								if(J[2] == '?') Js[2] = char(a6+'0');

								erg = calcBetter(erg, Cs, Js);
							}
						}
					}
				}
			}
		}

		cout << "Case #" << t+1 << ": " << erg.yy.xx << " " << erg.yy.yy << endl;

	}

	return 0;
}
