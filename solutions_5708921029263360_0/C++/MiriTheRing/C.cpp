#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<ll, ll> pll;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define DB(X) { if(1) cerr << "DB: " << (#X) << " = " << (X) << endl; }

ll JS[11][11], JP[11][11], PS[11][11];
ll J, S, P,K;
stack<pair<ll,pll>> solution;
bool invalid(ll j, ll p, ll s){
	if(JS[j][s] >=	K || JP[j][p] >= K || PS[p][s] >= K)
		return true;
	return false;
}

bool brute_force(ll j, ll p, ll s, ll todo){
	if(!todo) return true;

	while(j <= J){
		s++;
		if(s > S){
			s = 1;
			p++;
			if(p > P){
				p = 1;
				j++;
			}
		}
		if(j <= J && !invalid(j, p, s)){
			solution.push(mp(j,mp(p,s)));
			JS[j][s]++; JP[j][p]++; PS[p][s]++;
			if(brute_force(j,p,s,todo-1)) return true;
			solution.pop();
			JS[j][s]--; JP[j][p]--; PS[p][s]--;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll TC;
	cin >> TC;
	FOR(tc,0,TC){
		cin >> J >> P >> S >> K;
		solution = stack<pair<ll,pll>>();
		ll md = min({J*P*S, J*P*K, P*S*K, J*S*K});
		cout << "Case #" << tc+1 << ": ";
		cout << md << endl;
		FOR(i,0,11) FOR(j,0,11){
			JS[i][j] = JP[i][j] = PS[i][j] = 0;
		}
		brute_force(1,1,0,md);
		ll c = sz(solution);
		FOR(i,0,c){
			pair<ll, pll> s = solution.top(); solution.pop();
			cout << s.xx << " " << s.yy.xx << " " << s.yy.yy << endl;
		}
	}
}
