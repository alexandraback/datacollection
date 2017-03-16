#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n, p[1123], h[1123];

int test(int x)
{
	memset(h, 0, sizeof(h));
	for(int i = 0; i < n; i++)
		h[p[i]]++;
	int t = 0, k = 1000;
	while(k > x && t + x <= 1000)
		if(h[k] > 0)
			h[k]--, h[x]++, h[k-x]++, t++;
		else
			k--;
	return t + x;
}

int foo()
{
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ans = max(ans, p[i]), i++)
		scanf("%d", &p[i]);
	
	for(int i = 1; i <= 1000; i++)
		ans = min(ans, test(i));
	return ans;
}

int
main(void)
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
		printf("Case #%d: %d\n", t, foo());
}

