// Problem B. Lawnmower
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

int n, m;
vector<vector<int> > a, b;

int max_element_column(int j){
	int r = -1;
	F(i, n) r = max(r, a[i][j]);
	return r;
}

void solve(int caso) {
	bool r = 0;
	cin >> n >> m;
	b = a = vector<vector<int> > (n, vector<int>(m, 1000));
	F(i, n) F(j, m) cin >> a[i][j];
	F(i, n) {
		int maxi = *max_element(ALL(a[i]));
		F(j, m) b[i][j] = min(b[i][j], maxi);
	}
	F(j, m) {
		int maxi = max_element_column(j);
		F(i, n) b[i][j] = min(b[i][j], maxi);
	}
	if(a == b)
		cout<<"Case #"<<caso<<": YES" << endl;
	else
		cout<<"Case #"<<caso<<": NO" << endl;
}

int main(){
	// freopen("a.in.txt", "r", stdin);
	// freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

