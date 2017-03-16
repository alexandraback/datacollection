#include <stdio.h>

int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int T;
	int B;
	long long int M;
	long long int t;
	int arr[51];
	int flag;
	scanf("%d", &T);
	for(int test_case=1;test_case<=T;test_case++)
	{	
		flag = 0;
		scanf("%d %lld", &B, &M);

		t = 1;
		for(int i=0;i<B-2;i++)
			t *= (long long int)2;
		if(t < M)
		{
			printf("Case #%d: IMPOSSIBLE\n", test_case);
		}
		else
		{
			printf("Case #%d: POSSIBLE\n", test_case);
			if(t==M)
			{
				flag = 1;
				M--;
			}

			int idx = B-1;
			for(idx=B-1;idx>=0;idx--)
			{
				if(M%2==1)
					arr[idx]=1;
				else
					arr[idx] = 0;

				idx--;

				M/=2;
			}

			for(int i=1;i<=B;i++)
			{
				for(int j=1;j<=B;j++)
				{
					if(i>=j)
						printf("0");
					else if(i==1)
					{
						if(j==B && flag)
							printf("1");
						else if(j==B && flag==0)
							printf("0");
						else if(arr[j])
							printf("1");
						else
							printf("0");
					}
					else
						printf("1");
				}
				printf("\n");
			}
		}

	}

	return 0;
}