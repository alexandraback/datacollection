#include <stdio.h>
#include <math.h>
int main()
{
	freopen("A-small-attempt0 (1).in", "r", stdin);
	freopen("A-small-attempt0 (1)-output.txt", "w", stdout);
	int t, out, r, c, w, x;
	double add;
	scanf("%d", &t);
	for(x=1;x<=t;++x){
		scanf("%d %d %d", &r, &c, &w);
		add = ceil((c-w)/(double)w);
		out = w + (int)add;
		printf("Case #%d: %d\n", x, out);
	}
	return 0;
}
