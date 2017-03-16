#include<stdio.h>
#define MAX(a,b) a>b? a:b
#define MIN(a,b) a<b? a:b

int main()
{
    int i,t,n,s,p,j;
    int a[101];
    int low_ns,low_s,ans;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        scanf("%d %d %d",&n,&s,&p);
        for(j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        low_ns=3*p-2;


        for(j=0,ans=0;j<n;j++)
        {
            if(a[j]>=low_ns)
            {
                ans++;
                a[j]=-1;
            }
        }
        low_s=3*p-4;
        low_s=MIN(low_s,28);
        low_s=MAX(low_s,2);

        for(j=0;j<n && s>0;j++)
        {
            if(a[j]>=low_s)
            {
                ans++;
                a[j]=-1;
                s--;
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
