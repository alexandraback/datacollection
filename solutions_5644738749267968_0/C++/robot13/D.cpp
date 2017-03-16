#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    int t;
    scanf("%d", &t);

    for(int CASE = 1; CASE <= t; CASE ++)
    {
        int n;
        scanf("%d", &n);
        double naomi[1003], ken[1003];
        for(int i = 0; i < n; i ++)
            scanf("%lf", &naomi[i]);
        for(int i = 0; i < n; i ++)
            scanf("%lf", &ken[i]);
        sort(naomi, naomi+n);
        sort(ken, ken+n);
        int dwar = 0;
        int nn = 0; int kk = 0;
        while(nn < n && kk < n)
        {
            if(naomi[nn] > ken[kk])
            {
                dwar ++;
                nn ++;
                kk ++;
            }
            else
            {
                nn ++;
            }
        }
        
        int war = 0;
        nn = n-1; kk = n-1;
        while(nn >= 0 && kk >= 0)
        {
            if(naomi[nn] > ken[kk])
            {
                war ++;
                nn --;
            }
            else
            {
                nn --;
                kk --;
            }
        }
        printf("Case #%d: %d %d\n", CASE, dwar, war);
    }
    return 0;
}
