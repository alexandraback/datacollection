#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

using namespace std;

int A[10];

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("output3.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int test = 1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		int C, D, V;
		scanf("%d %d %d", &C, &D, &V);
		
		for(int i=0; i<D; i++)
			scanf("%d", &A[i]);
		
		int flag = 0;
		
		if(A[D-1]!=V)
		{
			A[D] = V;
			D++;
			flag = 1;
		}
		
		int cannot = 1, ans = 0;
		
		for(int i=0; i<D; i++)
		{
			if(A[i]<=cannot)
			{
				if(flag && i==D-1 && A[i]==cannot)
					ans++;
				
				cannot+= A[i];
			}
			else
			{
				ans++;
				cannot+= cannot;
				i--;
			}
		}
		
		printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
