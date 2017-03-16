#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

int T;
int E, R, N;
int v[10];

int result;

void maxGain(int idx, int e, int gained)
{
	if(idx >= N)
	{
		result = max(result, gained);
		return;
	}

	for(int i = 0; i <= e; i++)
	{
		maxGain(idx+1, min(E, e-i+R), gained + i*v[idx]);
	}
}

int main()
{
	scanf("%d", &T);
	
	for(int ca = 1; ca <= T; ca++)
	{
		scanf("%d %d %d", &E, &R, &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", v+i);
		}
		result = 0;
		maxGain(0, E, 0);

		printf("Case #%d: %d\n", ca, result);
	}

	return 0;
}

