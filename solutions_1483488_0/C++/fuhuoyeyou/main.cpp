#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[150];
char hash[300];
int change(int a)
{
    if(a<10)
       return 1;
    if(a<100)
       return 10;
    if(a<1000)
       return 100;
    if(a<10000)
       return 1000;
    if(a<100000)
       return 10000;
    if(a<1000000)
       return 100000;
    if(a<10000000)
       return 1000000;
}
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("1.txt", "w", stdout);
    int casenum;
    scanf("%d",&casenum);
    int num=1;
    int a,b;
    while(casenum--)
    {
        scanf("%d%d",&a,&b);
        int ta,tb,temp;
        int ans=0;
        for(int i=a;i<=b;++i)
        {
            temp=change(i);
            ta=(i%10)*temp+i/10;
            while(ta)
            {
                if(ta==i)
                   break;
                if(ta>i && ta>=a && ta<=b)
                {
                    ++ans;
                }
                ta =(ta%10)*temp+ta/10;
            }
        }
        printf("Case #%d: %d\n",num++,ans);
    }
    return 0;
}
