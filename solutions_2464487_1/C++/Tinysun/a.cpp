
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <NTL/ZZ.h>

typedef NTL::ZZ BigInt;

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

BigInt  r, t;

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
    
   
	for(int i=1; i<=ncase; i++)
	{
        // input data
        std::cin >> r >> t;
 
        // go
        BigInt  B = 2*r - 1;
        BigInt  s;
        SqrRoot(s, B*B + 8 * t);
        BigInt ans = (-B + s)/4;

		printf("Case #%d: ", i);
        std::cout << ans;

		printf("\n");
	}
  
	return  0;  
}
