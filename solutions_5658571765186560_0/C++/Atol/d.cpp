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

int k, r, c;

bool possible() {
	if (k > r + c - 1) {
		return false;
	}

	if ((r * c) % k) {
		return false;
	}

  // return k >= r - 1 && k >= c - 1?

	if (k <= 2) {
		return true;
	}

	if (k == 3) {
		return r >= 2 && c >= 2;
	}

	if (k == 4) { 
		return r >= 3 && c >= 3;
	}

	return true;
}

void solve() {
	cin >> k >> r >> c;

	if (possible()) {
		cout << "GABRIEL" << endl;
	} else {
		cout << "RICHARD" << endl;
	} 
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
