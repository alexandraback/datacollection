#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 100;
const int MAXM = 3000;

int a[2 * MAXN][MAXN];
int num[MAXM];
int n;

void get_res () {
	for (int i = 0; i < MAXM; ++i) {
		num[i] = 0;
	}

	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			num[a[i][j]]++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < MAXM; ++i) {
		if (num[i] % 2 == 1) {
			a[2 * n - 1][cnt++] = i;
		}
	}

	sort (a[2 * n - 1], a[2 * n - 1] + n);
}


int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;


	for (int i = 0; i < tc; ++i) {
		cin >> n;

		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		
		get_res();
		
		cout << "Case #" << i + 1 << ":";
		for (int i = 0; i < n; ++i) {
			cout << " " << a[2 * n - 1][i];
		}
		cout << endl;
	}

	return 0;
}
