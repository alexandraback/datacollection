#include <cstdio>
#include <set>
#include <string>
using namespace std;

typedef pair <bool, int> bi;
typedef long long ll;

const int Maxl = 10005;

int t;
int l;
ll x;
char str[Maxl];

bi Mult(bi a, bi b)
{
	bi c; c.first = a.first ^ b.first;
	if (a.second == 3) c.second = b.second;
	else if (b.second == 3) c.second = a.second;
	else if (a.second == b.second) { c.first = !c.first; c.second = 3; }
	else if ((a.second + 1) % 3 == b.second) c.second = (b.second + 1) % 3;
	else { c.first = !c.first; c.second = (a.second + 1) % 3; }
	return c;
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %lld", &l, &x);
		scanf("%s", str);
		bi has = bi(0, 3), a = bi(0, 3);
		int st = 0;
		for (int i = 0; i < x && i < 16 && st < 2; i++)
			for (int j = 0; j < l; j++) {
				bi mult = str[j] == 'i'? bi(0, 0): str[j] == 'j'? bi(0, 1): bi(0, 2);
				has = Mult(has, mult);
				if (i == 0) a = Mult(a, mult);
				if (st == 0 && has == bi(0, 0) || st == 1 && has == bi(0, 2)) st++;
			}
		string ans = "NO";
		if (st == 2) {
			bi res = bi(0, 3);
			while (x) {
				if (x & 1) res = Mult(res, a);
				x >>= 1; a = Mult(a, a);
			}
			if (res == bi(1, 3)) ans = "YES";
		}
		printf("Case #%d: %s\n", tc, ans.c_str());
	}
	return 0;
}