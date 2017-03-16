
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

vi treasureToKey[256];
int cur[256];
int neededKey[256];
int N, K;
int dif[1<<20][20];
bool canFin[1<<20];

bool canFinish(){
	int alle = (1<<N)-1;
	FOR(i,0,N)if(dif[alle][i] < 0)return false;
	canFin[alle] = 1;
	FOR(mr,1,1<<N){
		int m = alle ^ mr;
		canFin[m] = 1;
		FOR(i,0,N)if(dif[m][i] < 0)canFin[m] = 0;
		if(canFin[m]){
			canFin[m] = 0;
			FOR(i,0,N)if((m|(1<<i)) != m){
				if(canFin[m|(1<<i)]){
					if(dif[m][neededKey[i]])canFin[m] = 1;
				}
			}
		}
	}
	return canFin[0];
}
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cout << "Case #" << tcc <<":";
		memset(cur,0,sizeof(cur));
		cin >> K >> N;
		FOR(i,0,256)treasureToKey[i].clear();
		while(K--){
			int key;
			cin >> key;
			cur[key]++;
		}
		FOR(i,0,N){
			int key;
			cin >> neededKey[i] >> K;
			while(K--){
				cin >> key;
				treasureToKey[i].pb(key);
			}
		}
		map<int,int> mm;
		FOR(i,0,N)mm[neededKey[i]] = i;
		memset(dif,0,sizeof(dif));
		FORIT(it,mm)dif[0][it->second] = cur[it->first];
		FOR(i,0,N)neededKey[i] = mm[neededKey[i]];
		FOR(i,0,N){
			FOR(j,0,N)dif[1<<i][j] = dif[0][j];
			FORIT(it,treasureToKey[i])if(mm.find(*it) != mm.end())dif[1<<i][mm[*it]]++;
			dif[1<<i][neededKey[i]]--;
		}
		FOR(m,0,1<<N){
			int p1 = m & (-m);
			int p2 = m ^ p1;
			if(p2 == 0)continue;
			FOR(i,0,N)dif[m][i] = dif[p1][i] + dif[p2][i] - dif[0][i];
		}
		if(canFinish()){
			int mask = 0;
			FOR(ii,0,N){
				FOR(i,0,N){
					if((mask&(1<<i)) == 0){
						if(canFin[mask|(1<<i)]){
							if(dif[mask][neededKey[i]]){
								cout << " " << (1+i);
								mask |= 1<<i;
								break;
							}
						}
					}
				}
			}
			cout << "\n";
		} else {
			cout << " IMPOSSIBLE\n";
		}
	}
	return 0;
}
