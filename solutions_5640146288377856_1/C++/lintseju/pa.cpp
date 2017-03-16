#include <stdio.h>
#include <string.h>

int main()
{
	int t, caseNum = 1, ans, r, c, w;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &r, &c, &w);
		ans = ((c - (c % w)) / w) * r + w - 1;
		if(w > 1 && w < c && c % w != 0)
			ans += 1;
		printf("Case #%d: %d\n", caseNum++, ans);
	}
	return 0;
}
