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

bool break_me(int e1, int e2) {
	if (e1 < 0 || e2 < 0) {
		return true;
	}
	if (e1 % k || e2 % k) return true;
	return false;
}

bool breaks_all(int a, int b) {
	for(int x = 0; x <= c; x++) {
		int cols_l = x;
		int cols_r = (c - x - 1);

		int empty_l = cols_l * r - a;
		int empty_r = cols_r * r - b;

		int empty_l2 = cols_l * r - b;
		int empty_r2 = cols_r * r - a;

		if (!break_me(empty_l, empty_r) && break_me(empty_l2, empty_r2)) {
			return false;
		}
	}
	return true;
}

bool possible_large() {
	if (k >= 2 * r + 1) {
		return false;
	}

	if ((r * c) % k) {
		return false;
	}

	if (r >= k && c >= k) {
		return true;
	}

	// r is less than k, because of swap

	for(int a = 1; a <= (k-r); a++) {
		int b = (k-r) - a;
		if (breaks_all(a, b)) {
			return false;
		}
	}

	return true;
}

void solve() {
	cin >> k >> r >> c;

	if (r >= c) {
		swap(r, c);
	}

	bool ok = possible_large();

	// REMOVE
	/*
	bool ok2 = possible();
	if (ok != ok2) {
		cout << "LIXO LIXO LIXO " << ok << endl;
		cout << k << " " << r << " " <<c << endl;
	}
	*/

	if (ok) {
		cout << "GABRIEL" << endl;
	} else {
		cout << "RICHARD" << endl;
	} 
}

int main() {

	/*
	FOR(aa, 10) FOR(bb, 10) FOR(cc, 10) {
		k = aa; r = bb; c = cc;
		if (k == 0 || r == 0 || c == 0) continue;
		cout << "FOR "<< k << "," << r << "," << c << " = " << possible_large() << endl;
	}
	*/

  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
