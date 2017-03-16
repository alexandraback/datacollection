#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;
const int dx[] = {0, 1, 1, 1};
const int dy[] = {1, 0, 1, -1};

int t, n;
string s;
int a[4][4], sum;

bool win(int k) {
	int x, y;
	bool f;

	x = 0;
	forn(i, n) {
		y = 0;
		f = 1;
		forn(j, n) {
			if (a[x][y] != k && a[x][y] != 3) {
				f = 0;
				break;
			}
			y++;
		}

		if (f)
			return 1;
		x++;
	}

	y = 0;
	forn(i, n) {
		x = 0;
		f = 1;
		forn(j, n) {
			if (a[x][y] != k && a[x][y] != 3) {
				f = 0;
				break;
			}
			x++;
		}

		if (f)
			return 1;
		y++;
	}

		x = 0;
		y = 0;
		f = 1;
		forn(j, n) {
			if (a[x][y] != k && a[x][y] != 3) {
				f = 0;
				break;
			}
			x = (x + 1) % n;
			y = (y + 1) % n;
		}

		if (f)
			return 1;

		x = n - 1;
		y = 0;
		f = 1;
		forn(j, n) {
			if (a[x][y] != k && a[x][y] != 3) {
				f = 0;
				break;
			}
			x = (n + x - 1) % n;
			y = (y + 1) % n;
		}

		if (f)
			return 1;

	return 0;
}

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	scanf("%d\n", &t);
	n = 4;

	forn(ii, t) {
		cout << "Case #" << ii + 1 << ": ";
		forn(i, n) {
			cin >> s;
			forn(j, n) {
				a[i][j] = 0;
				if (s[j] == 'X') a[i][j] = 1; 
				if (s[j] == 'O') a[i][j] = 2; 
				if (s[j] == 'T') a[i][j] = 3; 
			}
		}
		
		sum = 0;
		forn(i, n)
			forn(j, n)
				sum += (a[i][j] > 0);
		if (win(1))
			cout << "X won";
		else if (win(2))
			cout << "O won";
		else if (sum == n * n)
			cout << "Draw";
		else
			cout << "Game has not completed";
		
		cout << '\n';
	}

    return 0;
}