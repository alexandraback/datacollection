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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); 

	int n;
	cin >> n;


	FOR(j, 0, n){
		string s;
		cin >> s;
		vector<int> erg;
		map<char, int> y;
		for(auto x : s){
			y[x]++;
		}

		//0
		erg.insert(erg.begin(), y['Z'], 0);
		y['E'] -= y['Z'];
		y['R'] -= y['Z'];
		y['O'] -= y['Z'];
		y['Z'] = 0;

		//6
		erg.insert(erg.begin(), y['X'], 6);
		y['S'] -= y['X'];
		y['I'] -= y['X'];
		y['X'] = 0;
		
		//7
		erg.insert(erg.begin(), y['S'], 7);
		y['E'] -= y['S'];
		y['V'] -= y['S'];
		y['E'] -= y['S'];
		y['N'] -= y['S'];
		y['S'] = 0;
		

		//5
		erg.insert(erg.begin(), y['V'], 5);
		y['F'] -= y['V'];
		y['I'] -= y['V'];
		y['E'] -= y['V'];
		y['V'] = 0;
		

		//4
		erg.insert(erg.begin(), y['F'], 4);
		y['O'] -= y['F'];
		y['U'] -= y['F'];
		y['R'] -= y['F'];
		y['F'] = 0;
		

		erg.insert(erg.begin(), y['W'], 2);
		y['O'] -= y['W'];
		y['T'] -= y['W'];
		y['W'] = 0;
		

		erg.insert(erg.begin(), y['O'], 1);
		y['N'] -= y['O'];
		y['E'] -= y['O'];
		y['O'] = 0;
		

		erg.insert(erg.begin(), y['N']/2, 9);
		y['I'] -= y['N'] / 2;
		y['E'] -= y['N'] / 2;
		y['N'] = 0;
		

		erg.insert(erg.begin(), y['G'], 8);
		y['E'] -= y['G'];
		y['I'] -= y['G'];
		y['H'] -= y['G'];
		y['T'] -= y['G'];
		y['G'] = 0;
		

		erg.insert(erg.begin(), y['R'], 3);
		y['T'] -= y['R'];
		y['H'] -= y['R'];
		y['E'] -= y['R'];
		y['E'] -= y['R'];
		y['R'] = 0;
		

		sort(all(erg));

		for(auto a : y){
			if(a.second != 0){
				cerr << s << endl;
				cerr << a.first << endl;
			}
		}

		cout << "Case #" << j+1 << ": ";
		for(auto a : erg){
			cout << a;
		}
		cout << endl;

	}

	return 0;
}
