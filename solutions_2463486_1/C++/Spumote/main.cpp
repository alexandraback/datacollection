#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define next qwertyusdfgh
#define read(x) scanf("%d", &x)
#define write(x) printf("%d ", x)
#define writeln(x) printf("%d\n", x)

const int con = 10000000;
const int kol = 39;

int a[150];
ll b[150];

//-------------------------------------------------------------------------------------------------

bool check(ll x) {
	int kol = 0;
	while (x > 9) {
		kol++;
		a[kol] = x % 10;
		x /= 10;	
	}
	kol++;
	a[kol] = x;

	for (int i = 1; i <= kol; i++)
		if (a[i] != a[kol - i + 1])
			return false;

	return true;
}

void init() {
	b[1] = 1;
	b[2] = 4;
	b[3] = 9;
	b[4] = 121;
	b[5] = 484;
	b[6] = 10201;
	b[7] = 12321;
	b[8] = 14641;
	b[9] = 40804;
	b[10] = 44944;
	b[11] = 1002001;
	b[12] = 1234321;
	b[13] = 4008004;
	b[14] = 100020001;
	b[15] = 102030201;
	b[16] = 104060401;
	b[17] = 121242121;
	b[18] = 123454321;
	b[19] = 125686521;
	b[20] = 400080004;
	b[21] = 404090404;
	b[22] = 10000200001;
	b[23] = 10221412201;
	b[24] = 12102420121;
	b[25] = 12345654321;
	b[26] = 40000800004;
	b[27] = 1000002000001;
	b[28] = 1002003002001;
	b[29] = 1004006004001;
	b[30] = 1020304030201;
	b[31] = 1022325232201;
	b[32] = 1024348434201;
	b[33] = 1210024200121;
	b[34] = 1212225222121;
	b[35] = 1214428244121;
	b[36] = 1232346432321;
	b[37] = 1234567654321;
	b[38] = 4000008000004;
	b[39] = 4004009004004;

}

int main() {
	init();

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		ll x, y;
		cin >> x >> y;
		int ans = 0;
		for (int i = 1; i <= kol; i++)
			if (x <= b[i] && b[i] <= y)
				ans++;
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}