
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

int64_t  N, M;
int64_t  fair_sq[100000];
int  fair_sq_count;

int CountUntil(int64_t n)
{
    int low = 0;
    int high = fair_sq_count - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if (fair_sq[mid] > n)
            high = mid - 1;
        else if (fair_sq[mid] < n)
            low = mid + 1;
        else
            return mid;
    }

    return high;
}

bool CheckIfPalindrome(int64_t num)
{
    char str[20];
    int l = sprintf(str, "%lld", num);
    for(int i=0; i<l/2; i++)
    {
        if (str[i] != str[l-1-i])
            return false;
    }
    return true;
}

void BuildFairSq()
{
    fair_sq[0] = 0;
    fair_sq_count = 1;
    
    
    // form A^2
    for(int64_t a=1; a<=9; a++)
    {
        int64_t v = a;
        int64_t sq = v*v;
        if (CheckIfPalindrome(sq))
            fair_sq[fair_sq_count++] = sq;
    }
    
    // form AA^2
    for(int64_t a=1; a<=9; a++)
    {
        int64_t v = 10*a + a;
        int64_t sq = v*v;
        if (CheckIfPalindrome(sq))
            fair_sq[fair_sq_count++] = sq;
    }

    // form ABA^2
    for(int64_t a=1; a<=9; a++)
        for(int64_t b=0; b<=9; b++)
        {
            int64_t v = 100*a + 10*b + a;
            int64_t sq = v*v;
            if (CheckIfPalindrome(sq))
                fair_sq[fair_sq_count++] = sq;
        }
    
    // form ABBA^2
    for(int64_t a=1; a<=9; a++)
        for(int64_t b=0; b<=9; b++)
        {
            int64_t v = 1000*a + 100*b + 10*b + a;
            int64_t sq = v*v;
            if (CheckIfPalindrome(sq))
                fair_sq[fair_sq_count++] = sq;
        }

    // form ABCBA^2
    for(int64_t a=1; a<=9; a++)
        for(int64_t b=0; b<=9; b++)
            for(int64_t c=0; c<=9; c++)
            {
                int64_t v = 10000*a + 1000*b + 100*c + 10*b + a;
                int64_t sq = v*v;
                if (CheckIfPalindrome(sq))
                    fair_sq[fair_sq_count++] = sq;
            }

    // form ABCCBA^2
    for(int64_t a=1; a<=9; a++)
        for(int64_t b=0; b<=9; b++)
            for(int64_t c=0; c<=9; c++)
            {
                int64_t v = 100000*a + 10000*b + 1000*c + 100*c + 10*b + a;
                int64_t sq = v*v;
                if (CheckIfPalindrome(sq))
                    fair_sq[fair_sq_count++] = sq;
            }

    // form ABCDCBA^2
    for(int64_t a=1; a<=9; a++)
        for(int64_t b=0; b<=9; b++)
            for(int64_t c=0; c<=9; c++)
                for(int64_t d=0; d<=9; d++)
                {
                    int64_t v = 1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + a;
                    int64_t sq = v*v;
                    if (CheckIfPalindrome(sq))
                        fair_sq[fair_sq_count++] = sq;
                }
    
}

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
    BuildFairSq();
    
//    for(int i=0; i<fair_sq_count; i++)
//        printf("%d: %lld\n", i, fair_sq[i]);
    
	for(int i=1; i<=ncase; i++)
	{
        // input data
        scanf("%lld %lld", &N, &M);
 
        // go
        int ans = CountUntil(M) - CountUntil(N-1);

		printf("Case #%d: %d", i, ans);

		printf("\n");
	}
  
	return  0;  
}
