#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

#define N 16
#define J 50

using namespace std;

void print(long long x)
{
    if(!x)      return;

    print(x >> 1);
    printf("%d" , x & 1);

    return;
}

vector < int > A({2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59});

int main()
{
    freopen("out.out" , "w" , stdout);

    int cnt = 0;
    for(long long i = (1 << (N - 1)) + 1;i < (1 << (N));i += 2)
    {
        int all = 0;
        vector < long long > ans , nums;
        for(int j = 2;j < 11;++j)
        {
            long long z = 1;
            long long num = 0;
            for(int k = 0;k < N;++k)
            {
                num += ((i & (1 << k)) ? 1 : 0) * z;
                z *= j;
            }
            for(int k = 0;k < (int)A.size();++k)
                if(!(num % A[k]) and (A[k] < num))
                {
                    ans.push_back(A[k]);
                    nums.push_back(num);
                    ++all;
                    break;
                }
        }
        if(all == 9)
        {
//            for(int i = 0;i < (int)nums.size();++i)
//                printf("%lld " , nums[i]);
//            printf(":   ");
            print(i);
            printf(" ");
            for(int i = 0;i < (int)ans.size();++i)
                printf("%lld " , ans[i]);

            printf("\n");
            ++cnt;
        }
        if(cnt == J)
            break;
    }
    return 0;
}


