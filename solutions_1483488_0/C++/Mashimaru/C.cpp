#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

const int expo[10] = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
const double ep = 1e-9;

int test, A, B, ans;

int d(int n)
{
	int ans = 0;
	while (expo[ans] <= n) ans++;
	return ans;
}

int main()
{
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	scanf("%d", &test);
	for (int num = 1; num <= test; num++)
	{
		scanf("%d %d", &A, &B);
		ans = 0;
		for (int x = A; x <= B; x++)
		{
			set <int> cnt;
			for (int t = 1; expo[t] < x; t++)
			{
				int y = (x % expo[t]) * expo[d(x) - t] + x / expo[t];
				if (A <= y && y < x) cnt.insert(y);
			}
			ans += cnt.size();
		}
		printf("Case #%d: %d\n", num, ans);
	}
	return 0;
}
