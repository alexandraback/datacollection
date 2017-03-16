
#include <cstdio>

int main()
{
    int i;
    int t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int a,b,kk;
        scanf("%d %d %d",&a,&b,&kk);
        
        int j,k;
        int cnt = 0;
        for(j=0;j<a;j++)
        {
            for(k=0;k<b;k++)
            {
                if((j& k) < kk)
                  cnt++;
            }
        }
        printf("Case #%d: %d\n",i,cnt);
    }


}
