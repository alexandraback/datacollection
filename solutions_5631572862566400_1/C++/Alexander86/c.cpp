
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
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

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


int bf[1024];

int N;
bool direct[1024];
int in_circ[1024];
int vis[1024];
vi adj[1024];

int rek(int n){
	int res = 1;
	FOR(i,0,sz(adj[n]))res = max(res, 1 + rek(adj[n][i]));
	return res;
}
void calc(){
	cin >> N;
	FOR(i,0,N)cin >> bf[i];
	FOR(i,0,N)--bf[i];
	FOR(i,0,N)direct[i] = (bf[bf[i]] == i);
	memset(vis,-1,sizeof(vis));
	FOR(i,0,N)in_circ[i] = false;
	int res = 0;
	FOR(i,0,N)if(vis[i] == -1){
		int c = i;
		vis[c] = i;
		c = bf[c];
		while(vis[c] == -1){
			vis[c] = i;
			c = bf[c];
		}
		if(vis[c] == i){
			int C = 0;
			while(!in_circ[c]){
				++C;
				in_circ[c] = true;
				c = bf[c];
			}
			res = max(res, C);
		}
	}
	FOR(i,0,N)adj[i].clear();
	FOR(i,0,N)if(bf[bf[i]] != i)adj[bf[i]].push_back(i);
	int res2 = 0;
	FOR(i,0,N)if(direct[i])res2 += rek(i);
	res = max(res, res2);
	cout << res << endl;
}

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1){
		cout << "Case #" << tc << ": ";
		calc();
	}
	return 0;
}
