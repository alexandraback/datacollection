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
typedef long long   LL;

int N, M, K;
vector<int> mul;
set<string> conj;
string resp;

void verifyGood(string s) {
	vector<int> dig;
	F(i, N)
		dig.PB(s[i]-'0');
	vector<bool> vis(K, false);
	int c = 0;
	F(mask, 1<<N) {
		int num = 1;
		F(j, N) {
			if(mask&(1<<j)){
				num *= dig[j];
			}
		}
		F(j, K) {
			if(mul[j] == num && !vis[j]) {
				vis[j] = true;
				c++;
			}
		}
	}
	if(c == K) resp = s;
}

void bruteF(string s) {
	if(conj.find(s) == conj.end()) {
		conj.insert(s);
		verifyGood(s);
		if(resp.S) return;
		F(i, N) {
			if(s[i]-'0' < M) {
				string xs = s;
				xs[i]++;
				bruteF(xs);
			}
		}
	}
}

void solve() {
	int R, kk, x;
	cin >> R >> N >> M >> kk;
	F(i, R) {
		set<int> conjAux;
		F(j, kk) {
			cin >> x;
			if(x >= 2) conjAux.insert(x);
		}

		mul = vector<int> (ALL(conjAux));
		K = mul.S;

		conj.clear();
		resp = "";
		string s(N, '2');

		bruteF(s);
		cout << resp << endl;
	}
}

int main(){
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++){
		printf("Case #%d:\n", cas);
		solve();
	}
}
