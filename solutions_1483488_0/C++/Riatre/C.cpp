#include <stdio.h>
#include <string.h>

int bucket[2222222];

int countdigi(int x)
{
	int ans = 0;
	while(x)
	{
		ans++;
		x /= 10;
	}
	return ans;
}

int roll(int x,int mask)
{
	int highest = x/mask;
	x = (x%mask)*10+highest;
	return x;
}

int main(void)
{
	freopen("c-small.in","rt",stdin);
	freopen("c-small.out","wt",stdout);
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		memset(bucket,0,sizeof(bucket));
		
		int A = 0;
		int B = 0;
		scanf("%d %d",&A,&B);
		int d = countdigi(A)-1;
		int mask = 1;
		for(int i = 0;i < d;i++) mask *= 10;

		unsigned long long ans = 0;
		for(int i = A;i <= B;i++)
		{
			int x = i;
			for(int j = 0;j < d;j++)
			{
				x = roll(x,mask);
				if(x > i && x <= B && bucket[x] != i)
				{
					ans++;
					bucket[x] = i;
				}
			}
		}
		printf("Case #%d: %I64d\n",++TK,ans);
	}
	return 0;
}
