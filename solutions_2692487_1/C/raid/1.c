#include <stdio.h>
#include <stdlib.h>

int maxa,maxcnt;
int m[101],n;
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int search(int i,int a,int cnt)
{
    int ta,t,cnt1,cnt2;
    if(i >= n)
    {
        return cnt;
    }
    ta = a;
    t = 0;
    if(a <= m[i] && a!= 1)
    {
        while(ta <= m[i])
        {
            t++;
            ta += ta-1;
        }
    }
    else if(a == 1)
    {
        t = 1000000;
    }
    cnt1 = 1000000;
    //printf("%d\n",a);
    if(a != 1) cnt1 = search(i+1,ta+m[i],cnt+t);
    cnt2 = 1000000;
    if(cnt+1 < cnt+t) cnt2 = search(i+1,a,cnt+1);
    if(cnt1 < cnt2)
    {
        return cnt1;
    }
    else return cnt2;
}
int main()
{
    int t,c,i,a;
    int cnt1,cnt2,ans,ta,j;
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d%d",&a,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
        }
        qsort(m,n,sizeof(int),cmp);
        ans = search(0,a,0);
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
