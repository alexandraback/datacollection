#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
int A,B,K;
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&A, &B, &K);
		printf("Case #%d: ",i);
		int sum = 0;
		for (int j=0;j<A;j++)
			for (int k=0;k<B;k++)
			{
				if ((j & k) < K)
					sum++;
			}
		printf("%d\n", sum);
		
	}
	return 0;
}