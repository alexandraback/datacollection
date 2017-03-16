
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

int  A, N;
int  m[101];
int  add[101];
int  sum[101];
int  rev_sum[101];

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
    
   
	for(int i=1; i<=ncase; i++)
	{
        // input data
        std::cin >> A >> N;
        for(int j=0; j<N; j++)
            std::cin >> m[j];

        std::sort(m, m+N);
/*
        printf("%d %d\n", A, N);
        for(int j=0; j<N; j++)
        printf("%d ", m[j]);
*/
        if (A == 1)
        {
            printf("Case #%d: %d\n", i, N);
            continue;
        }
        
        int  mote = A;
        for(int j=0; j<N; j++)
        {
            int cnt = 0;
            while (mote <= m[j])
            {
                mote = mote + (mote - 1);
                cnt++;
            }
            mote = mote + m[j];
            add[j] = cnt;
        }
        
        sum[0] = add[0];
        for(int j=1; j<N; j++)
            sum[j] = sum[j-1] + add[j];
        
        rev_sum[N-1] = add[N-1];
        for(int j=N-2; j>=0; j--)
            rev_sum[j] = rev_sum[j+1] + add[j];
        
        int  minsol = min(N, rev_sum[0]);
        for(int j=1; j<N; j++)
        {
            int t = sum[j-1] + min(N-j, rev_sum[j]);
            minsol = min(minsol, t);
        }
 
        int  ans = minsol;
        
		printf("Case #%d: ", i);
        std::cout << ans;

		printf("\n");
	}
  
	return  0;  
}
