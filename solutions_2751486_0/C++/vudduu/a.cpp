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
#define S           size()
#define MP          make_pair
#define LSOne(x)	(x&(-x))
typedef long long   LL;

string s;
int t[1000001], longToValid[1000001];
bool valid[1000001];

void solve() {
	int n, it;
	cin >> s >> n;
	memset(t, 0, sizeof(t));
	memset(longToValid, 0, sizeof(longToValid));
	memset(valid, 0, sizeof(valid));
	bool flag = false;
	for(int i=s.S-1; i>=0 ;i--) {
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') t[i] = 0;
		else t[i] = t[i+1]+1;
		if(t[i] >= n){
			it = i;
			flag = true;
		}
		longToValid[i] = it-i;
		valid[i] = flag;
	}
	LL r = 0;
	F(i, s.S) {
		if(!valid[i]) continue;
		r += LL(s.S) - LL(i + longToValid[i] + n - 1);
	}
	cout << r << endl;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++) {
		printf("Case #%d: ", cas);
		solve();
	}
}
