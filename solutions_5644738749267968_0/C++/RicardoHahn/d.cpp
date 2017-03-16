#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1100

int main()
{
    int t;
    scanf("%d",&t);
    for(int ccnt=1; ccnt<=t; ++ccnt)
    {
        int N;
        double n[MAX], k[MAX];
        int y=0,z=0;
        int i,j;

        scanf("%d",&N);

        for(i=0; i<N; ++i)
            scanf("%lf",&n[i]);
        for(i=0; i<N; ++i)
            scanf("%lf",&k[i]);
        sort(n,n+N);
        sort(k,k+N);

        for(i=j=N-1;i>=0; --i)
        {
            if(n[i]>k[j])
                ++z;
            else
                --j;
        }
        for(i=j=N-1;j>=0; --j)
        {
            if(n[i]>k[j])
            {
                ++y;
                --i;
            }
        }
        printf("Case #%d: %d %d\n",ccnt, y, z);
    }
    return 0;
}
