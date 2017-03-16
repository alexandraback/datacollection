#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define y0 isdnfviu
#define y1 asinhiv
#define fst first
#define snd second
#define count sdifnsugh

ld a[1111], b[1111];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	for (int g = 1; g <= q; g++)
	{
		cout << "Case #" << g << ": ";
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int pra = 1;
		int prb = 1;
		int x = 0;
		while (true)
		{
			if (pra > n && prb > n)
				break;
			while (a[pra] < b[prb] && pra <= n)
				pra++;
			if (pra > n)
				break;
			x++;
			prb++;
			pra++;
		}
		pra = 1, prb = 1;
		int y = 0;
		while (true)
		{
			if (pra > n && prb > n)
				break;
			while (b[prb] < a[pra] && prb <= n)
				prb++;
			if (prb > n)
				break;
			y++;
			pra++;
			prb++;
		}
		y = n - y;
		cout << x << " " << y << endl;
	}
	cin >> q;
	return 0;
}
