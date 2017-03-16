#include <stdio.h>
int main()
{
    int totalcase;
    scanf("%d",&totalcase);
    for(int o=0;o<totalcase;o++)
    {
        int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int ans=0;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            int temp=(i&j);
            if(temp<c)
            {
                ans++;
            }
        }

    }printf("Case #%d: %d\n",o+1,ans);
    }

    return 0;
}
