
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

int N;
vector<string> first;
vector<string> second;

bool findfirst(string s, vi ori) {
	FOR(i, sz(ori)) {
		if (first[ ori[i] ] == s ) {
			return true;
		}
	}
	return false;
}

bool findsecond(string s, vi ori) {
	FOR(i, sz(ori)) {
		if (second[ ori[i] ] == s ) {
			return true;
		}
	}
	return false;
}

bool canmake(vi ori, vi fake) {
	FOR(i, sz(fake)) {
		int pos = fake[i];

		if (!findfirst( first[pos], ori)) {
			return false;
		}
		if (!findsecond( second[pos], ori)) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> N;
	first.clear();
	second.clear();

	FOR(i, N) {
		string aux;
		cin >> aux;
		first.pb(aux);
		cin >> aux;
		second.pb(aux);
	}

	int ans = 0;
	FOR(i, (1<<N)) {
		vector<int> original, fake;
		FOR(j, N) {
			if (i & (1<<j)) {
				original.pb(j);
			} else {
				fake.pb(j);
			}
		}
		if (canmake(original, fake)) {
			ans = max(ans, sz(fake));
		}
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
