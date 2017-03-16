/*
 ID: aaandrew
 PROG: gcj 13 qual round 
 LANG: C++
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <fstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define PB push_back

const int max_key = 8, N = 22;
int T, k, n, st, here[max_key], freq[N][max_key], tt[N], kk[N];
bool dp[1100000];
int par[1100000];

int main() {
	cin >> T;
	REP(t,T) {
		CL(freq);
		CL(dp);
		
		cin >> k >> n;
		REP(j,k) {
			cin >> st;
			freq[n][st]++;
		}
		REP(i,n) {
			cin >> tt[i] >> kk[i];
			REP(j,kk[i]) {
				cin >> st;
				freq[i][st]++;
			}
		}
		
		dp[0] = true;
		REP(i,1<<n) {
			if (dp[i]) {
				//propagate!
				CL(here);
				REP(k,max_key) here[k] += freq[n][k]; //initial
				REP(j,n) if (i & (1<<j)) {
					here[ tt[j] ]--; //to open
					REP(k,max_key) here[k] += freq[j][k]; //jackpot!
				}
				
				/*cout << i << endl;
				REP(k,max_key) cout << here[k] << " ";
				cout << endl;*/
				
				REP(j,n) if (!dp[i | (1<<j)] && !(i & (1<<j)) && here[ tt[j] ]>0) {
					par[i | (1<<j)] = j;
					dp[i | (1<<j)] = true;
				}
			}
		}
		
		cout << "Case #" << (t+1) << ":";
		if (!dp[(1<<n)-1]) 
			cout << " IMPOSSIBLE" << endl;
		else {
			vector<int> v;
			int x = (1<<n)-1;
			while (x) {
				v.PB(1+par[x]);
				x = x & (~(1<<par[x]));
			}
			REP(i,v.size()) cout << " " << v[v.size()-1-i];
			cout << endl;
		}
	}
}
