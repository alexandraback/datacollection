#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <ctime>
#include <queue>
#include <map>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef bool bl;
typedef pair<bl, bl> pbl;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define ft first
#define sd second
#define forn(i, y, x) for(int i = y; i < x; i++)
#define ford(i, y, x) for(int i = y; i >= x; i--)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define error exit(1)
#define DEBUG
const int mod = (int)1e9;
const int inf = (int)1e9;
const int base = 1000 * 1000 * 1000;
const int maxn = 2005;
const ld pi = acosl(-1.0);
const ld eps = 1e-9;

void solve()
{
	int t;
	scanf("%d", &t);
	forn(tt, 1, t + 1){
		string arr[10] = { "ZERO", "TWO", "SIX", "EIGHT", "FOUR", "THREE", "FIVE", "SEVEN", "NINE", "ONE" };
		char p[10] = { 'Z', 'W', 'X', 'G', 'U', 'R', 'F', 'S', 'I', 'O' };
		int num[10] = { 0, 2, 6, 8, 4, 3, 5, 7, 9, 1 };
		string s;
		cin >> s;
		map<char, int> m;
		int cnt[10] = { 0 };
		forn(i, 0, sz(s)) m[s[i]]++;
		forn(i, 0, 10){
			int d = m[p[i]];
			cnt[num[i]] += d;
			forn(j, 0, sz(arr[i])) m[arr[i][j]] -= d;
		}
		cout << "Case #" << tt << ": ";
		forn(i, 0, 10) forn(j, 0, cnt[i]) cout << i;
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}