#include<cstdio>

int main()
{
	freopen("D:\\A-small-attempt1.in", "r", stdin);
	freopen("D:\\outA.txt", "w", stdout);
	int t, r, c, w, cases;
	scanf("%d",&t);
	for(cases=1;cases<=t;cases++){
		scanf("%d %d %d",&r, &c, &w);
		//printf("%d %d %d\n", r, c, w);
		printf("Case #%d: %d\n",cases, (c+w-1)/w+(w-1));
	}
	return 0;
}
