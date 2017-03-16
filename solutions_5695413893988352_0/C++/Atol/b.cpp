
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

string AA, BB;
long long best;

long long tolong(string s) {
	long long val = 0;
	FOR(i, sz(s)) {
		val *= 10ll;
		val += (long long) (s[i] - '0');
	}
	return val;
}

void update_final(string A, string B) {
	long long a = tolong(A);
	long long b = tolong(B);
	long long d = a > b ? a - b : b - a;

	if (best == -1 || d < best) {
		AA = A;
		BB = B;
		best = d;
	} else if (d == best) {
		if (A < AA) {
			AA = A;
			BB = B;
			best = d;
		}
	}
}

void update(string A, string B, int pos) {
	if (pos == sz(A) + sz(B)) {
		update_final(A, B);
		return;
	}

	if (pos < sz(A)) {
		if (A[pos] == '?') {
			FOR(i, 10) {
				A[pos] = i + '0';
				update(A, B, pos+1);
			}
			A[pos] = '?';
		} else {
			update(A, B, pos+1);
		}
	} else {
		int posb = pos - sz(A);
		if (B[posb] == '?') {
			FOR(i, 10) {
				B[posb] = i + '0';
				update(A, B, pos+1);
			}
			B[posb] = '?';
		} else {
			update(A, B, pos+1);
		}
	}
}

void solve() {
	string A, B;
	cin >> A >> B;
	best = -1;
	AA = "no", BB = "no";
	update(A, B, 0);
	cout << AA << " " << BB << endl;
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
