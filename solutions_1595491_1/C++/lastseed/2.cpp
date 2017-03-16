#include <stdio.h>

int main()
{
	int T, t, i, j, n, s, p, a, ans;
	
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &T);
	for (t=1; t<=T; t++)
	{
		ans=0;
		scanf("%d%d%d", &n, &s, &p);
		for (i=1; i<=n; i++){
			scanf("%d", &a);
			if (p==1&&a==0) continue;
			if (a>=p*3-2) ans++;
			else if (a>=p*3-4&&s>0){ans++; s--;}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}