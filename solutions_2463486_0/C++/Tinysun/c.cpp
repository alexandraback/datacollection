
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

int  N, M;

int CountUntil(int n)
{
    int cnt = 0;
    
    if (n >= 1)
        cnt++;
    if (n >= 4)
        cnt++;
    if (n >= 9)
        cnt++;
    if (n >= 121)
        cnt++;
    if (n >= 484)
        cnt++;
    
    return cnt;
}

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
        // input data
        scanf("%d %d", &N, &M);
 
        // go
        int ans = CountUntil(M) - CountUntil(N-1);

		printf("Case #%d: %d", i, ans);

		printf("\n");
	}
  
	return  0;  
}
