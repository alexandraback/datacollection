#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <set>

using namespace std;

int main()
{
	set< pair<int,int> > pairs;
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		
		int res = 0;
		
		pairs.clear();
		
		for(int n = A; n <= B; n++)
		{
			char ns[10];
			sprintf(ns, "%d", n);
			
			int nlen = strlen(ns);
			
			char ms[10];
			for(int i = 1; i < nlen; i++)
			{
				if(ns[i] == '0')
					continue;
					
				int k = 0;
				for(int j = i; j < nlen; j++, k++)
					ms[k] = ns[j];
				
				for(int j = 0; j < i; j++, k++)
					ms[k] = ns[j];
				
				ms[k] = 0;
				
				int m = atoi(ms);
				if(n < m && m <= B)
				{
					if(pairs.insert(make_pair(n,m)).second)
						res++;
				}
			}
		}
		
		printf("Case #%d: %d\n", t, res);
	}
}
