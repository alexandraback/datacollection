#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
char a[999];
int n;
int dap()
{
	int i, j;
	for (n = 0; a[n]; n++);
	a[n] = '+';
	int res = 0;
	for (i = 0; i < n; i++)
		if (a[i] != a[i + 1])
			res++;
	return res;
}
int main()
{
	int t;
	int tv = 1;


//	freopen("B-small-attempt0.in", "rt", stdin);
//	freopen("B-small-attempt0.out", "wt", stdout);
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", a);
		printf("Case #%d: ", tv);
		printf("%d\n", dap());
		tv++;
	}
}