#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++ i) 
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

vector<int> keys;
int required_to_open[20];
vector<int> get_when_opened[20];
int K, N;

int cache[1 << 20];

bool f(int state) {
	if(state == (1<<N)-1)
		return true;

	int &ret = cache[state];
	if(ret!=-1) return ret;

	// compute current keys;
	vector<int> nowkey = keys;
	for(int i = 0; i < N; ++ i) if( state & (1<<i) ) {
		nowkey[ required_to_open[i] ] --;
		for(int got : get_when_opened[i]) {
			nowkey[got] ++;
		}
	}

	// try next treasure
	for(int i = 0; i < N; ++ i) if( !(state&(1<<i)) ) {
		if(nowkey[ required_to_open[i] ] > 0) {
			bool ref = f(state | (1<<i));
			if(ref) {
				return (ret = true);
			}
		}
	}
	return ret = false;
}
deque<int> out(int state) {
	if(state == (1<<N)-1) return deque<int> ();

	// compute current keys;
	vector<int> nowkey = keys;
	for(int i = 0; i < N; ++ i) if( state & (1<<i) ) {
		nowkey[ required_to_open[i] ] --;
		for(int got : get_when_opened[i]) {
			nowkey[got] ++;
		}
	}

	// try next treasure
	for(int i = 0; i < N; ++ i) if( !(state&(1<<i)) ) {
		if(nowkey[ required_to_open[i] ] > 0) {
			if( f(state | (1<<i)) ) {
				deque<int> res = out(state | (1<<i));
				res.push_front(i);
				return res;
			}
		}
	}
	throw 1;
}

bool go() {
	memset(cache,-1, sizeof(cache));
	if( f(0) ) {
		deque<int> g = out(0);
		for(int i : g) {
			cout << (i+1) << ' ';
		}
		return true;
	}
	return false;
}

int main() {
	int T;
	freopen("D-small.in","r",stdin);
	freopen("D-small.out","w",stdout);
	cin >> T;
	for(int tt=1;tt<=T;++tt) {
		fprintf(stderr, "%d\n", tt);
		keys.clear();
		keys.resize(200);
		cin >> K >> N;
		for(int i=0; i<K; ++i) {
			int k; cin >> k;
			keys[k] ++;
		}
		for(int i=0; i<N; ++i) {
			cin >> required_to_open[i];
			int cnt, v;
			cin >> cnt;
			get_when_opened[i].clear();
			for(int j=0; j<cnt; ++j) {
				cin >> v;
				get_when_opened[i].push_back(v);
			}
		}
		cout << "Case #" << tt << ": ";
		if(! go()) {
			cout << "IMPOSSIBLE" ;
		}
		cout << endl;
	}
	return 0;
}
