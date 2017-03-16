#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[2000],num[2000],p[2000];
int main(void)
{
    int tcase,tt;
    tt=0;

    a[1]=a[2]=a[3]=0;
    a[4]=1;
    for (int i=5;i<=1000;i++)
        if (i%2==1)
            a[i]=a[i-1];
        else
            a[i]=a[i-1]+1;

    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    cin>>tcase;
    while (tcase--)
    {
        tt++;
        int d;
        scanf("%d",&d);

        int max_=0;

        for (int i=1;i<=1000;i++)
            num[i]=0;

        for (int i=1;i<=d;i++)
        {
            scanf("%d",&p[i]);
            num[p[i]]++;
            if (p[i]>max_)
                max_=p[i];
        }

        int ans=max_;

        for (int i=1;i<=max_;i++)
        {
            int tmp=i;
            for (int j=1;j<=d;j++)
            {
                int di=p[j]/i;
                if (!(p[j]%i))
                    tmp+=(di-1);
                else
                    tmp+=di;
            }
            if (tmp<ans)
                ans=tmp;
        }

        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
