#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string fail = "RICHARD";
string suc = "GABRIEL";

int t;
int x, r, c;

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &x, &r, &c);
		if (r < c) swap(r, c);
		string res;
		if (x >= 7 || r * c % x || r < x || c < (x - 1) / 2 + 1) res = fail;
		else if (c > (x - 1) / 2 + 1) res = suc;
		else if (x == 1 || x == 2 || x == 3 || x == 5) res = suc;
			 else res = fail;
		printf("Case #%d: %s\n", tc, res.c_str());
	}
	return 0;
}