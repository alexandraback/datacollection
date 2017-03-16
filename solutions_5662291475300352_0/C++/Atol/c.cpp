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

int G;

vector< pair<long long, long long> > hikers;

int go_small1() {

	long long d1 = hikers[0].first;
	long long m1 = hikers[0].second;

	long long d2 = hikers[1].first;
	long long m2 = hikers[1].second;

	// just follow them
	if (m1 == m2) {
		return 0;
	}

	if (m1 > m2) {
		swap(d1, d2);
		swap(m1, m2);
	}

	long long t1 = (360 - d1) * m1;
	long long t2 = (360 - d2) * m2;

	if (t1 >= t2) return 0;

	if (t1 + 360 * m1 <= t2) {
		return 1;
	}

	return 0;
}

void solve() {
	cin >> G;
	hikers.clear();
	FOR(i, G) {
		long long d, h, m;
		cin >> d >> h >> m; 
		FOR(j, h) {
			hikers.pb(mp(d, m));
		}
	}

	if (hikers.size() <= 1) {
		cout << 0 << endl;
		return;
	}

	if (hikers.size() > 2) {
		cout << "NOT a SMALL 1 condition, I dont know the answer" << endl;
		return;
	}

	cout << go_small1() << endl;
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
