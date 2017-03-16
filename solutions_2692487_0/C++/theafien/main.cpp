#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <list>
#include <vector>
#include <algorithm>
#include <complex>

int main()
{
    unsigned int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int a;
        int n;
        scanf("%d %d", &a, &n);
        int ans=n;
        std::vector<int> mot,step;
        mot = std::vector<int>();
        step = std::vector<int>(n);
        for(int j=0;j<n;j++)
        {
            int t;
            scanf("%d", &t);
            mot.push_back(t);
        }
        sort(mot.begin(),mot.end());
        if(a!=1)
        {
        int c=0;
        for(int j=0;j<n;j++)
        {
            while(a<=mot[j])
            {
                a=(2*a)-1;
                c++;
            }
            step[j]=c;
            a=a+mot[j];
        }
        for(int j=0;j<n;j++)
        {
            if((step[j]+n-j-1)<ans)
                    ans=(step[j]+n-j-1);
        }
        }
        printf("Case #%d: %d\n", i+1, ans);
    }
    return 0;
}
