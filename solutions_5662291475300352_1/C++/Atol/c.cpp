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

vector< pair<long long, long long> > hikersM;

int go_small1() {

	if (hikers.size() <= 1) {
		return 0;
	}

	if (hikers.size() > 2) {
		cout << "NOT a SMALL 1 condition, I dont know the answer" << endl;
		return -1;
	}

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

int go_small2() {
	vector< pair<long long, long long> > v = hikersM;

	sort(all(v));
	int n = sz(v);
	vector<long long> ultrapassado;
	FOR(i, n) ultrapassado.pb(0);

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			long long ti = (360 - v[i].second) * v[i].first;
			long long tj = (360 - v[j].second) * v[j].first;
			for (int voltas = 1; voltas <= (n*n) + 1; voltas++) {
				if (ti + (voltas * 360) * v[i].first <= tj) {
					ultrapassado[j]++;
				}
			}
		}
	}

	int ans = n;
	for(int i = n; i >= 0; i--) {
		int maxi = 0;
		for (int j = i-1; j >= 0; j--) {
			if(ultrapassado[j] > maxi) {
				maxi = ultrapassado[j];
			}
		}
		int tmp = (n - i) + maxi;
		ans = min(ans, tmp);
	}

//	cout << "small 2, n = " << n << endl;
//	FOR(i, n) cout << ultrapassado[i] << " "; cout << endl;
	return ans;
}

void solve() {
	cin >> G;
	hikers.clear();
	hikersM.clear();
	FOR(i, G) {
		long long d, h, m;
		cin >> d >> h >> m; 
		FOR(j, h) {
			hikers.pb(mp(d, m));
			hikersM.pb(mp(m, d));
		}
	}
	
	// cout << go_small1() << endl;
	cout << go_small2() << endl;
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
