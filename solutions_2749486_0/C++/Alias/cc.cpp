#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <queue>
#include <memory.h>
#include <iostream>
#include <stack>
#include <complex>
#include <list>

using namespace std;
 
void ASS(bool b)
{
    if (!b)
    {
        ++*(int*)0;
    }
}
 
#define FOR(i, x) for (int i = 0; i < (int)(x); ++i)
#define CL(x) memset(x, 0, sizeof(x))
#define CLX(x, y) memset(x, y, sizeof(x))
 
#pragma comment(linker, "/STACK:106777216")
 
typedef vector<int> vi;
typedef long long LL;

string sY = "NS";
string sX = "EW";

string Solve() {
	int x, y;
	cin >> x >> y;
	int cx = 0, cy = 0;
	string res;
	while (!(cx == x && cy == y)) {
		if (cx < x) {
			cx++;
			res += sX[1];
			res += sX[0];
			continue;
		}
		if (cx > x) {
			cx--;
			res += sX[0];
			res += sX[1];
			continue;
		}
		if (cy < y) {
			cy++;
			res += sY[1];
			res += sY[0];
			continue;
		}
		if (cy > y) {
			cy--;
			res += sY[0];
			res += sY[1];
			continue;
		}
	}
	return res;
}

int main()
{
	freopen("c:\\my\\in.txt", "r", stdin);
	freopen("c:\\my\\out.txt", "w", stdout);
	int n;
	cin >> n;
	FOR(i, n) {
		string res = Solve();
		cout << "Case #" << (i + 1) << ": " << res << "\n";
	}

	return 0;
}