#include <stdio.h>
#include <algorithm>

using namespace std;

int test, k, c, s;

int main()
{
	freopen("d-small.in", "r", stdin);
	freopen("d-small.out", "w", stdout);
	
	scanf("%d" ,&test);
	
	for(int t=1; t<=test; t++)
	{
		scanf("%d %d %d" ,&k ,&c ,&s);
		
		printf("Case #%d:" ,t);
		
		for(int i=1; i<=s; i++)
			printf(" %d" ,i);
		
		printf("\n");
	}
}
