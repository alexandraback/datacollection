#include <iostream>
#include <cstdio>
using namespace std;

bool completed[2][1000];
int N;
int a[1000],b[1000];



int handle_tc()
{
	int x,y;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
		completed[0][i] = completed[1][i] = false;
	}
	
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(b[j] < b[i] || (b[j]==b[i] && a[i] < b[j]))
			{
				x = a[i];
				y = b[i];
				a[i] = a[j];
				b[i] = b[j];
				a[j] = x;
				b[j] = y;
			}
			
	// for(int i = 0; i < N; i++)
		// printf("%d %d\n", a[i], b[i]);
	
	
	bool done = false;
	int stars = 0;
	int result = 0;
	while(!done && !completed[1][N-1])
	{
		done = true;
		for(int i = 0; i < N; i++)
			if(!completed[1][i] && b[i] <= stars)
			{
				if(!completed[0][i])
					stars += 2;
				else
					stars += 1;
				completed[0][i] = completed[1][i] = true;
				done = false;
				result++;
			}
			
		for(int i = N-1; i >= 0; i--)
			if(!completed[0][i] && a[i] <= stars)
			{
				stars++;
				completed[0][i] = true;
				done = false;
				result++;
				break;
			}
	}
	if(!completed[1][N-1])
		return -1;
	return result;
}

int main()
{
	int T,C;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		C = handle_tc();
		if(C == -1)
			printf("Case #%d: Too Bad\n", i);
		else
			printf("Case #%d: %d\n", i, C);
	}
}