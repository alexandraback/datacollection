#include<iostream>


using namespace std;

int main()
{

	
	int V[20],R,E,N,cases;

	scanf("%d",&cases);
	for(int test = 1; test <= cases; test++)
	{
		scanf("%d %d %d",&E, &R, &N);

		int ans = 0 ,max = 0;

		for(int i = 1; i <= N;i++)
		{
			scanf("%d",&V[i]);
			if(V[i] > max) max = V[i];
		}
		
		bool flag = false;
		if(R < E)
		{
			for(int i = 1; i <= N; i++)
			{
				if(!flag && V[i] == max) { ans += V[i] * E; flag = true; }
				else ans += V[i] * R;
			}
		}
		else
		{
			for(int i = 1; i <= N ;i++) ans += V[i];
			ans *= E;
		}

		

		printf("Case #%d: %d\n",test, ans);
	}


	return 0;
}