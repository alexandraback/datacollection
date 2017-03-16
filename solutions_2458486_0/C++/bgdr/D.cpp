#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define pb push_back

int T, N, K;
vector<int> keys[200];
int key_for[200];
vector<int> start_keys;
map<int,int> cache;

int solve1(int state){
	int count[200] = {0, };
	for(int i = 0; i < start_keys.size(); ++i) { 
		count[start_keys[i]]++;
	}
	if(cache.find(state) != cache.end())
		return cache[state];
	if(state == ((1 << N) - 1))
		return 0;
	for(int i = 0; i < N; ++i)
		if(state & (1<<i)){
			for(int j = 0; j < keys[i].size();++j)
				count[keys[i][j]]++;
			count[key_for[i]]--;
		}
	for(int i = 0; i < N; ++i)
		if(!(state & (1<<i))){
			if(count[key_for[i]] > 0){
				int ans = solve1(state | (1<<i));
				if(ans != -1){
					cache[state] = i;
					return i;
				}
			}
		}
	cache[state] = -1;
	return -1;
}

int main(){
	cin >> T;
	for(int c = 1; c <= T; ++c){
		cin >> K >> N;
		start_keys.clear();
		cache.clear();
		for(int i = 0; i < N; ++i)
			keys[i].clear();
		for(int i = 0; i < K; ++i){
			int v; cin >> v; start_keys.pb(v-1);
		}
		for(int i = 0; i < N; ++i) {
			cin >> key_for[i];
			key_for[i]--;
			int t; cin >> t;
			for(int j = 0; j < t; ++j){
				int v; cin >> v; v--;
				keys[i].pb(v);
			}
		}
		int sol = solve1(0);
		cout << "Case #" << c << ": ";
		if(sol == -1) cout << "IMPOSSIBLE" << endl; else {
			int state = 0;
			while(state != ((1 << N) - 1)) {
				int ans = solve1(state);
				cout << (ans + 1) << " ";
				state |= (1 << ans);
			}
			cout << endl;
		}
	}
}
