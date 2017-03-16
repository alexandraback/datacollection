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


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		int x, r, c;
		cin >> x >> r >> c;
		if (r > c)
			swap(r, c);
		bool f = false;
		if (x == 1)
			f = true;
		else if (x == 2)
			f |= r >= 1 && c >= 2 && (r * c) % 2 == 0;
		else if (x == 3)
			f |= r >= 2 && c >= 3 && (r * c) % 3 == 0;
		else if (x == 4)
			f |= r >= 3 && c >= 4 && (r * c) % 4 == 0;
		else if (x == 5)
			f |= r >= 4 && c >= 5 && (r * c) % 5 == 0;
		else if (x == 6)
			f |= r >= 4 && c >= 6 && (r * c) % 6 == 0;
		
		string ans = "Richard";
		if (f)
			ans = "Gabriel";
		cout << "Case #" << test << ": " << ans << "\n";
	}
}





