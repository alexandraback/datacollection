//Google Code Jam Round 1C 2014 - Problem C.
//https://code.google.com/codejam

#include<stdio.h>
#include<stdlib.h>
#include<string.h>//Google Code Jam Round 1C 2014 - Problem A.
//https://code.google.com/codejam

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;


int main()
{
    freopen ("c_output.txt","w",stdout);

    int T, N, M, K, ans, tmp;

    scanf("%d", &T);

    for(int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d %d %d", &N, &M, &K);
        printf("Case #%d: ", testCase);
        //printf("%d %d %d ", N, M ,K);
        if(K == 1 || K ==2 || K==3 || K==4)
        {
            printf("%d\n", K);
            continue;
        }
        // I need N is small
        if(N > M)
        {
            tmp = N;
            N = M;
            M = tmp;
        }

        if(N == 1)
            ans = K;
        else if(N == 2)
            ans = K;
        else if(N == 3)
        {
            K -= 1;
            ans = 0;
            if(K%3 == 0)
            {
                ans += 3;
                K-= 4;
            }
            if((M-2)*3 <K)
            {
                ans += (M-2)*2;
                ans += K-((M-2)*3);
                ans += 1;
            }
            else
            {
                ans += (K % 3);
                ans = ans + (K/3)*2;
                ans += 1;
            }

        }
        else if(N == 4)
        {
            K-=2;
            ans = 0;
            if(K % 4 == 0)
            {
                ans += 3;
                K-= 4;
            }
            if((M-2)*4 <K)
            {
                ans += (M-2)*2;
                ans += K-((M-2)*4);
                ans+=2;
            }
            else
            {
            ans += (K % 4);
            ans = ans + (K/4)*2;
            ans += 2;
            }
        }
        else
        {
            printf("=========================\n");
        }

        printf("%d", ans);
        printf("\n");
    }
    return 0;
}
