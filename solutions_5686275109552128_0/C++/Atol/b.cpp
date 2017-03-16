#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

int n;
vector<int> v;

long long calc(long long big) {
	long long aux = big;
	FOR(i, n) {
		long long x = v[i];
		long long breaks = (x + big - 1) / big;
		aux += (breaks - 1);
	}
	return aux;
}

void solve() {
	cin >> n;
	v.clear();
	FOR(i, n) { 
		int aux;
		cin >> aux;
		v.pb(aux);
	}
	sort(all(v));
	reverse(all(v));

	long long ans = 1000000000;
	FOR(i, 1001) {
		if (i == 0) continue;
		long long tmp = calc(i);
		ans = min(ans, tmp);
	}

	cout << ans << endl;
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
