#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

using namespace std;

char key[10], target[10], X[10];
long long banana;

void checkx()
{
	banana = 0;
	
	for(int i=0; X[i]!='\0'; i++)
	{
		int flag = 0, k = i;
		
		for(int j=0; target[j]!='\0'; j++)
		{
			if(X[k++]!=target[j])
			{
				flag = 1;
				break;
			}
		}
		
		if(flag==0)
			banana++;
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int test = 1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		int K, L, S;
		scanf("%d %d %d", &K, &L, &S);
		
		scanf(" %s %s", key, target);
		
		target[L] = '\0';
		
		long long event = 0, max_banana = 0, limit = (long long)pow(K, S);
		
		while(1)
		{
			int k = 0;
			long long tmp = event;
			
			for(; k<S; k++)
			{
				X[k] = key[tmp%K];
				tmp/= K;
			}
			
			X[k] = '\0';
			checkx();
			
			//printf("\t%s %s %d\n", X, target, banana);
			
			if(banana>max_banana)
				max_banana = banana;
			
			event++;
			
			if(event==limit)
				break;
		}
		
		if(max_banana==0)
		{
			printf("0.000000\n");
			continue;
		}
		
		double ans = 0;
		
		for(long long i=0; i<event; i++)
		{
			int k = 0;
			long long tmp = i;
			
			for(; k<S; k++)
			{
				X[k] = key[tmp%K];
				tmp/= K;
			}
			
			X[k] = '\0';
			//printf("\t\t%s\n", X);
			
			checkx();
			
			ans+= (double)(max_banana-banana)/(double)event;
			
			//printf("\t%lf\n", ((double)(max_banana-banana)/(max_banana))/(double)event);
		}
		
		printf("%lf\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
