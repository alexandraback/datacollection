#include <stdio.h>
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("outa.txt", "w", stdout);
	int T;
	int tt = 1;
	scanf("%d", &T);
	while(T--)
	{
		int r, t;
		scanf("%d%d", &r, &t);
		int nr = r, sum = 0, nall = 0;
		while(true)
		{
			sum += (2*nr+1);
			if(sum > t) break;
			nall++;
			nr += 2;
		}
		printf("Case #%d: %d\n", tt, nall);
		tt++;
	}
	return 0;
}
