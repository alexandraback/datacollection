#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;

int n;
double a[1005], b[1005];

void solve() {
	cout << "Case #" << ++CASE << ": ";
	
	sort(a,a+n);
	sort(b,b+n);
	
	int dwr = 0;
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > b[j]) {
			dwr++;
			j++;
		}
	}
	
	j = 0;
	int war = n;
	for(int i = 0; i < n; i++) {
		while(j < n && b[j] < a[i]) {
			j++;
		}
		if(j < n) {
			war--;
			j++;
		}
	}
	
	cout << dwr << ' ' << war << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> TESTS;
	for(int i = 0; i < TESTS; i++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}
		solve();
	}
}
