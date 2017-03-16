
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <NTL/ZZ.h>

typedef NTL::ZZ BigInt;

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

int  E, R, N;
int  v[10001];
int  p[10001];
int  s[10001];

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
    
   
	for(int i=1; i<=ncase; i++)
	{
        // input data
        std::cin >> E >> R >> N;
        for(int j=0; j<N; j++)
            std::cin >> v[j];
/*
        printf("%d %d %d\n", E, R, N);
        for(int j=0; j<N; j++)
        printf("%d ", v[j]);
*/
        p[0] = E;
        s[0] = E;
        for(int j=1; j<N; j++)
        {
            p[j] = R;
            s[j] = R;
        }
        
        for(int j=N-1; j>0; j--)
        {
            for(int k=j-1; k>=0; k--)
            {
                if (v[k] > v[j])
                    break;
                if (s[j] == E)
                    break;
                int steal = min(E - s[j], s[k]);
                steal = min(steal, E - p[j]);
                if (steal == 0)
                    break;
                s[j] += steal;
                s[k] -= steal;
                p[j] += steal;
            }
        }
        int ans = 0;
        for(int j=0; j<N; j++)
            ans += v[j] * s[j];

		printf("Case #%d: ", i);
        std::cout << ans;

		printf("\n");
	}
  
	return  0;  
}
