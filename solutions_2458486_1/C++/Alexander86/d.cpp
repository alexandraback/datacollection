
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

int cur[256];
int treasureDone[256];
int treasureVis[256];
vi keyToTreasure[256];
bool callowed[256];
vi treasureToKey[256];
int neededKey[256];
bool active[256];
int N, K;
bool change;
int dfs(int id, int dep, int lastAv){
//	cerr << "dfs start " << id << " " << dep << " " << lastAv << endl;
	if(treasureDone[id])return dep;
	if(treasureVis[id])return dep;
	treasureVis[id] = dep;
	active[id] = 1;
	if(callowed[neededKey[id]]){
		lastAv = id;
//		cerr << "ch lastAv\n";
	}
	FORIT(key, treasureToKey[id]){
		//cerr << id << " has key " << *key << endl;
		FORIT(tid, keyToTreasure[*key]){
			//cerr << id << " goes to " << *tid << endl;
			if(active[*tid]){
				if(treasureVis[lastAv] >= treasureVis[*tid]){
					cur[neededKey[id]]--;
					FORIT(it,treasureToKey[id])cur[*it]++;
					FORIT(it,treasureToKey[id])callowed[*it] = 1;
					active[id] = 0;
					change = true;
					treasureDone[id] = 2;
//					cerr << treasureVis[lastAv] << " " << treasureVis[*tid] << " " << *tid << " :: ";
//					cerr << id <<" suc\n";
					return treasureVis[*tid];
				}
			} else {
				int hi = dfs(*tid, dep + 1, lastAv);
				if(hi <= dep){
					cur[neededKey[id]]--;
					FORIT(it,treasureToKey[id])cur[*it]++;
					FORIT(it,treasureToKey[id])callowed[*it] = 1;
					active[id] = 0;
					treasureDone[id] = 2;
					return hi;
				}
			}
		}
	}
	active[id] = 0;
	return dep;
}

bool tryFinish(){
	memset(callowed, 0, sizeof(callowed));
	FOR(i,0,201)if(cur[i])callowed[i] = 1;
	change = true;
	while(change){
		while(change){
			change = false;
			memset(treasureVis,0,sizeof(treasureVis));
			FOR(i,1,N+1)if(treasureDone[i] == 0)if(callowed[neededKey[i]]){
				dfs(i, 1, i); 
			}
		}
		change = 0;
//		cerr <<"#";
//		FOR(i,1,N+1)cout << treasureDone[i] << " ";
//		cout << endl;
//		FOR(i,2,7)cout << "k" << cur[i];
//		cout << endl;
		FOR(i,1,N+1)if(treasureDone[i] == 0)if(cur[neededKey[i]]){
			--cur[neededKey[i]];
			treasureDone[i]=2;
			FORIT(it,treasureToKey[i])cur[*it]++;
			FORIT(it,treasureToKey[i])callowed[*it] = 1;
			change = true;
			break;
		}
//		cerr <<"##";
//		FOR(i,1,N+1)cout << treasureDone[i] << " ";
//		cout << endl;
//		FOR(i,2,7)cout << "k" << cur[i];
//		cout << endl;
	}
	bool ok = 1;
//	cerr << "[";
	FOR(i,1,N+1){
//		cerr << treasureDone[i] << " ";
		if(treasureDone[i] == 0)ok = 0;
		if(treasureDone[i] == 2){
			cur[neededKey[i]]++;
			FORIT(it,treasureToKey[i])cur[*it]--;
			treasureDone[i] = 0;
		}
	}
//	cerr << "]";
	return ok;
}


int main() {
	memset(active,0,sizeof(active));
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cout << "Case #" << tcc <<":";
		memset(cur,0,sizeof(cur));
		memset(treasureDone,0,sizeof(treasureDone));
		cin >> K >> N;
		FOR(i,0,256)keyToTreasure[i].clear();
		FOR(i,0,256)treasureToKey[i].clear();
		while(K--){
			int key;
			cin >> key;
			cur[key]++;
		}
		FOR(i,1,N+1){
			int key;
			cin >> neededKey[i] >> K;
			keyToTreasure[neededKey[i]].pb(i);
			while(K--){
				cin >> key;
				treasureToKey[i].pb(key);
			}
		}
		if(tryFinish()){
			FOR(runvar,0,N){
				FOR(i,1,N+1)if(treasureDone[i] == 0)if(cur[neededKey[i]]){
					treasureDone[i] = 1;
					FORIT(it,treasureToKey[i])cur[*it]++;
					cur[neededKey[i]]--;
					if(tryFinish()){
						cout << " " << i;
						break;
					} else {
						//cout << "trbf(" << i << ")";
						treasureDone[i] = 0;
						FORIT(it,treasureToKey[i])cur[*it]--;
						cur[neededKey[i]]++;
					}
				}
			}
			cout << endl;
		} else {
			cout << " IMPOSSIBLE\n";
		}
	}
	return 0;
}
