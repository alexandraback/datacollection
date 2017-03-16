#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 2005

/**
 * Deon Nicholas's Bipartite Matching code
 * Runs in O(VE) time, I think.
 */

vector<int> E[MAXN];
int match[MAXN];
bool vis[MAXN];

bool dfs(int i) {
  if (vis[i]) return false;
  vis[i] = true;
  
  int numE = E[i].size();
  for(int x=0;x<numE;++x) {
    int j = E[i][x];
    if (match[j] < 0 || dfs(match[j]))
    return (match[i]=j,match[j]=i,true);
  }
  
  return false;
}

int bip_match(int N) {
  memset(match,-1,sizeof(match));
  int ans = 0;
  for(int i=0;i<N;++i) if (match[i] < 0){
    memset(vis,0,sizeof(vis));
    ans += dfs(i);
  }
  return ans;
}

void add_edge(int i, int j) {
  E[i].push_back(j);
  E[j].push_back(i);
}

vector<string> lefts;
vector<string> rights;
map<string, int> leftIndex;
map<string, int> rightIndex;

string leftWord[MAXN];
string rightWord[MAXN];

void clear() {
	FOR(i,MAXN) E[i].clear();
	memset(match,-1,sizeof(match));
	memset(vis,0,sizeof(vis));
	lefts.clear();
	rights.clear();
	leftIndex.clear();
	rightIndex.clear();
}

int main() {
	int TEST;
	cin >> TEST;
	FOR(test,TEST) {
		clear();

		int N;
		cin >> N;
		FOR(i,N) {
			cin >> leftWord[i] >> rightWord[i];
			lefts.pb(leftWord[i]);
			rights.pb(rightWord[i]);
		}

		sort(lefts.begin(), lefts.end());
		lefts.erase(unique(lefts.begin(), lefts.end()), lefts.end());

		sort(rights.begin(), rights.end());
		rights.erase(unique(rights.begin(), rights.end()), rights.end());

		int X = lefts.size();
		FOR(i,X) leftIndex[lefts[i]] = i;

		int Y = rights.size();
		FOR(j,Y) rightIndex[rights[j]] = j;

		FOR(i,N) {
			int x = leftIndex[leftWord[i]];
			int y = rightIndex[rightWord[i]] + X;
			add_edge(x,y);
		}

		int nodes = X+Y;
		int ans = bip_match(nodes);
		FOR(i,nodes) if (match[i] < 0) ans++;
		cout << "Case #" << (test+1) << ": " << (N-ans) << endl;
	}
}































