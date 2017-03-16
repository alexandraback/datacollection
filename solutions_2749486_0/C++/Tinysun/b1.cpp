
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

#include <NTL/ZZ.h>

typedef NTL::ZZ BigInt;

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

int  X, Y;

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
    
   
	for(int i=1; i<=ncase; i++)
	{
        // input data
        std::cin >> X >> Y;
//        printf("%d %d\n", X, Y);
        
        char  ans[600];
        int   len = 0;
        
        if (X < 0)
        {
            for(int k=0; k<-X; k++)
            {
                ans[len++] = 'E';
                ans[len++] = 'W';
            }
        }
        else
        {
            for(int k=0; k<X; k++)
            {
                ans[len++] = 'W';
                ans[len++] = 'E';
            }
        }
        
        if (Y < 0)
        {
            for(int k=0; k<-Y; k++)
            {
                ans[len++] = 'N';
                ans[len++] = 'S';
            }
        }
        else
        {
            for(int k=0; k<Y; k++)
            {
                ans[len++] = 'S';
                ans[len++] = 'N';
            }
        }
        ans[len++] = '\0';
        
		printf("Case #%d: ", i);
        std::cout << ans;

		printf("\n");
	}
  
	return  0;  
}
