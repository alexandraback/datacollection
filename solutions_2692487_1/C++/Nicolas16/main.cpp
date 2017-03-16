#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main()
{
	int i, j, T, t;
	int A, N;
	int action;
	int result;
	vector<int> autres;
	scanf("%d\n", &T);
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d %d", &A, &N);
		autres.resize(N);
		action = 0;
		result = N;
		for(i = 0; i < N; i++)
		{
			scanf("%d", &autres[i]);
		}
		sort(autres.begin(), autres.end());
		if(A == 1) printf("%d\n", N);
		else
		{
		
		for(i = 0; i < N; i++)
		{
			if(autres[i] < A) // On peut le manger
			{
				A += autres[i];
			}
			else
			{
				action += 1;
				A += (A-1);
				i--;
			}
			// On en a mangé i+1, avec un nombre d'actions égal à action
			result = min(result, action + N-(i+1));
		}
		
		printf("%d\n", result);
		
		}
	}

	return 0;
}
