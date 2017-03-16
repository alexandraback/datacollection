#include<stdio.h>
int reverse(int n)
{
    int out=0;
    while(n)
    {
        out=out*10 + n%10;
        n=n/10;
    }
    return out;
}
int main()
{
    int i,t,n,cnt,curr,rev;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        cnt=1;
        curr=1;
        while(curr!=n)
        {
            rev=reverse(curr);
            if(rev>curr && rev<=n)
            {
                cnt++;
                curr=rev;
            }
            else
            {
                curr++;
                cnt++;
            }
        }
        printf("Case #%d: %d\n",i,cnt);

    }
    return 0;
}
