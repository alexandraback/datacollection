#include <stdio.h>

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int T;
	char str[1002];
	int note[1002];
	char ans[1002];
	int len, idx;
	int maxi;


	scanf("%d", &T);
	for(int test_case=1;test_case<=T;test_case++)
	{
		scanf("%s", str);
		for(len=0;str[len]!=0;len++);
		ans[len] = 0;

		idx = 0;
		maxi = 0;
		for(int i=0;i<len;i++)
		{
			if(str[i] >= maxi)
			{
				note[idx] = i;
				maxi = str[i];
				idx++;
			}
		}
		note[idx] = 0;

		int l, r, tidx;

		ans[idx-1] = str[note[0]];
		l = idx-2;
		r = idx;
		tidx = 1;

		for(int i=1;i<len;i++)
		{
			if(i==note[tidx])
			{
				ans[l] = str[i];
				l--;
				tidx++;
			}
			else
			{
				ans[r] = str[i];
				r++;
			}
		}

		printf("Case #%d: %s\n", test_case, ans);

	}

	return 0;
}