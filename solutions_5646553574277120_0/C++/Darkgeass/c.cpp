#include <iostream>
#include <vector>
#include <set>
#define INF 1e9

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef set<ll> sl;

int c,d;
ll v;

int main(){
	int t; cin >> t;
	for(int cass = 1; cass <= t; ++cass){
		cin >> c >> d >> v;
		vi co(d);
		sl coin;
		for(int i = 0; i < d; ++i) cin >> co[i];
		for(int i = 0; i < d; ++i) coin.insert(co[i]);
		int k = 0;
		sl::iterator it = coin.begin();
		sl coin2;
		int cont = 0;
		while(k < v){
			if(it != coin.end() and *it <= k+1){
				ll x = *it;
				coin2.insert(x);
				++it;
				k += x*c;
				continue;
			}
			else{
				coin2.insert(k+1);
				k += c*(k+1);
				++cont;
			}
		}
		cout << "Case #" << cass << ": " << cont << endl;
	}
}