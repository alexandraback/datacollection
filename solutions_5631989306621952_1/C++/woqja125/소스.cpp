#include<stdio.h>
#include<algorithm>
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	char in[1001], stk1[1001], stk2[1001];
	int t1, t2, c, i;
	for (int TT = 1; TT <= T; TT++)
	{
		scanf("%s", in);
		t1 = t2 = -1; c = 1;
		stk1[++t1] = in[0];
		for (; in[c]; c++)
		{
			if (stk1[t1] <= in[c]) stk1[++t1] = in[c];
			else stk2[++t2] = in[c];
		}
		printf("Case #%d: ", TT);
		for (i = t1; i >= 0; i--) printf("%c", stk1[i]);
		stk2[++t2] = 0;
		printf("%s\n", stk2);
	}
	return 0;
}