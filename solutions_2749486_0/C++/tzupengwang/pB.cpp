#include<stdio.h>
#include<string.h>

int main()
{

    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);

    int amm,cnt=0;
    scanf("%d",&amm);
    while (amm--)
    {
        cnt++;
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case #%d: ",cnt);
        if (a<0)
        {
            for (int i=0;i<-a;i++)
            {
                printf("EW");
            }
        }
        else
        {
            for (int i=0;i<a;i++)
            {
                printf("WE");
            }
        }
        if (b<0)
        {
            for (int i=0;i<-b;i++)
            {
                printf("NS");
            }
        }
        else
        {
            for (int i=0;i<b;i++)
            {
                printf("SN");
            }
        }
        puts("");
    }
    return 0;
}
