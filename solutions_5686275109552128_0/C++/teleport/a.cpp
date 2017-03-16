#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 alfdjasldfjeao
#define y1 safiodjafis

const int maxn = 1003;
int f[maxn], a[maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		for (int i = 0; i <= 1000; i++)
			f[i] = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= a[i]; j++)
				f[j] += (a[i] + j - 1) / j - 1;
		int ans = 1000;
		for (int i = 1; i <= 1000; i++)
			ans = min(ans, i + f[i]);
		cout << "Case #" << test << ": " << ans << "\n";
	}
}





