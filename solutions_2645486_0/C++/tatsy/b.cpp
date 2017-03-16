#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++) 
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

int T, E, R, N;
int v[11];
int maxval;

void dfs(int e, int g, int d) {
	if(d == N) {
		if(maxval < g) {
			maxval = g;
		}
		return;
	}

	for(int i=0; i<=e; i++) {
		int ne = min(E, (e-i) + R);
		int ng = g +i * v[d];
		dfs(ne, ng, d+1); 
	}
}

int solve() {
	maxval = 0;
	dfs(E, 0, 0);
	return maxval;
}

int main() {
	cin>>T;
	rep(t,T) {
		cin>>E>>R>>N;
		rep(i,N) cin>>v[i];
		printf("Case #%d: %d\n", t+1, solve());
	}
}
