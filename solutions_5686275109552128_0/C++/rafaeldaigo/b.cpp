#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        int n;
        int count[1100];
        int largest = 0;
        scanf("%d", &n);
        for (int i = 0; i <= 1000; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            count[a]++;
        }
        for (largest = 1000; largest >= 1; largest--)
        {
            if (count[largest] > 0)
            {
                break;
            }
        }
        int best = largest;
        for (int eatTime = largest; eatTime >= 1; eatTime--)
        {
            int cand = eatTime;
            for (int i = 1; i <= largest; i++)
            {
                cand += count[i] * ((i - 1) / eatTime);
            }
            best = min(best, cand);
        }

        printf("Case #%d: %d\n", t+1, best);
    }
    return 0;
}
