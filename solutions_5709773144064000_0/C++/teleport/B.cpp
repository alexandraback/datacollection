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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	for (int g = 1; g <= q; g++)
	{
		cout << "Case #" << g << ": ";
		ld c, f, x;
		cin >> c >> f >> x;
		ld ans = x / 2, t = 0, y = 2;
		for (int i = 1; i <= 100000; i++)
		{
			t += c / y;
			y += f;
			ans = min(ans, t + x / y); 
		} 
		cout.precision(7);
		cout << fixed << ans << endl;
	}
	cin >> q;
	return 0;
}
