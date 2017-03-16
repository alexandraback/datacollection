#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



const int maxn = 1000 + 5;
double a[maxn];
double b[maxn];


void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[i] );
	for (int i = 0; i < n; i++)
		scanf("%lf", &b[i] );
	sort(a, a + n);
	sort(b, b + n);

	int x = 0, y = 0;
	int l = 0, r = n;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[l] )
		{
			x++;
			l++;
		}
		else
		{
			r--;
		}
	}
	l = 0;
	r = n;
	reverse(a, a + n);
	reverse(b, b + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[l] )
		{
			y++;
			r--;
		}
		else
		{
			l++;
		}
	}
	printf("%d %d", x, y);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		fprintf(stderr, "Case #%d\n", i);
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}



	return 0;
}
