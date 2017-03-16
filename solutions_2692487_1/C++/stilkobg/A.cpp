#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,T;
long long A,n,a[128],bans=-1;
void print(int x,long long ans)
{
    printf("Case #%d: %I64d\n",x,ans);
}
int main()
{
    scanf("%d",&T);
    while(t++<T)
    {
        scanf("%I64d%d",&A,&n);
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        i=0;
        long long br=0;
        while(a[i]<A&&i<n)
        {
            A+=a[i];
            i++;
        }
        if(i==n)
        {
                print(t,0);
                continue ;
        }
        if(A==1){print(t,n);continue ;}
        int ti=i;
        for(;i<n;i++)
            if(A>a[i])A+=a[i];
        else
        {
            if(i==n-1){br++;continue;}
            while(A<=a[i])
            {
                A=A+A-1;
                br++;
            }
            A+=a[i];
        }
        print(t,min(br,n-(ti)));
    }
    return 0;
}
