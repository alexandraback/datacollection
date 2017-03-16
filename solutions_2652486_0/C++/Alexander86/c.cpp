
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)


vi best;
ll score;
int N, M, R, K;
ll res[20];
const int RUNS = 100000;

void rek(vi cur){
	if(N > sz(cur)){
		int lo = 2;
		if(sz(cur))lo = cur[sz(cur)-1];
		cur.pb(lo);
		while(cur[sz(cur)-1] <= M){
			rek(cur);
			cur[sz(cur)-1]++;
		}
	} else {
		unordered_map<ll, int> mm;
		FOR(ii,0,RUNS){
			int next = rand();
			ll n = 1;
			FOR(i,0,N){
				if((next>>i)&1){
					n*=cur[i];
				}
			}
			mm[n] += 1;
		}
		ll cscore = 0;
		FOR(i,0,K){
			if(mm[res[i]] == 0)cscore -= oo;
			else cscore += mm[res[i]];
		}
		if(cscore >= score){
			best = cur;
			score = cscore;
		}
	}
}


int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cout << "Case #" << tcc <<":\n";
		cin >> R >> N >> M >> K;
		FOR(r,0,R){
			FOR(k,0,K)cin >> res[k];
			score = -oo;
			score *= K;
			rek(vi());
			FOR(k,0,N)cout << best[k];
			cout << endl;
		}
	}
	return 0;
}
