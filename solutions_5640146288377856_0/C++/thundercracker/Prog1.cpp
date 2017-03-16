#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

//#include <bits/stdc++.h>

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output1.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int test = 1; test<=T; test++)
	{
		printf("Case #%d: ", test);
		
		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);
		
		if(C%W)
			printf("%d\n", C/W + W);
		else
			printf("%d\n", C/W + W - 1);
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
