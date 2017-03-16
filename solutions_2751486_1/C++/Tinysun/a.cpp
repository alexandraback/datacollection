
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

char  name[1000010];
int   n;
int   pattern[1000010];
int   pat_len;
int   tailsum[1000010];

bool is_vowels(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return  true;
    
    return false;
}

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
    
   
	for(int i=1; i<=ncase; i++)
	{
        // input data
        std::cin >> name >> n;
        //printf("%s %d\n", name, n);
        size_t len = strlen(name);
    
        pat_len = 0;
        pattern[pat_len] = 0;
        int  status = 1; // vowels
        for(int j=0; j<len; j++)
        {
            if (status == 1)
            {
                if (is_vowels(name[j]))
                {
                    pattern[pat_len]++;
                }
                else
                {
                    pat_len++;
                    pattern[pat_len] = 1;
                    status = 2;
                }
            }
            else
            {
                if (is_vowels(name[j]))
                {
                    if (pattern[pat_len] < n)
                    {
                        pat_len--;
                        pattern[pat_len] += pattern[pat_len+1];
                        pattern[pat_len]++;
                    }
                    else
                    {
                        pat_len++;
                        pattern[pat_len] = 1;
                    }
                    status = 1; // change to vowels
                }
                else
                {
                    pattern[pat_len]++;
                }
            }
        }
        if (status == 2)
        {
            if (pattern[pat_len] < n)
            {
                pat_len--;
                pattern[pat_len] += pattern[pat_len+1];
            }
        }
        
//       for(int j=0; j<=pat_len; j++)
//           printf("%d:%d ", j, pattern[j]);
//       printf("\n");
        
        int  sum = 0;
        for(int j=pat_len; j>=0; j--)
        {
            sum += pattern[j];
            tailsum[j] = sum;
        }
        tailsum[pat_len+1] = 0;
        
        int64_t  cnt_sum = 0;
        for(int j=1; j<=pat_len; j+=2)
        {
            int64_t  pat_n = pattern[j] - n;
            int64_t  pat_n1 = pattern[j-1]+1;
            if (j >= 3)
                pat_n1 += n-1;
            int64_t  cnt = pat_n1 * (pat_n+1+ tailsum[j+1])
                        +pat_n*tailsum[j+1] + (pat_n)*(pat_n+1)/2;
            cnt_sum += cnt;
        }
        
        int64_t  ans = cnt_sum;
        
		printf("Case #%d: ", i);
        std::cout << ans;

		printf("\n");
	}
  
	return  0;  
}
