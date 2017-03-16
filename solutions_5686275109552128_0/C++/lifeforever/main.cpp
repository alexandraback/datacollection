#include <iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int pile[maxn];
int n;
int judge(int cut)
{
    int sum=0,Max=0;
    for(int i=0; i<n; i++)
    {
        if(pile[i]>cut)
        {
            sum+=1;
            if((pile[i]-cut)>cut)
            {
                if((pile[i]-cut)%cut)
                    sum+=(pile[i]-cut)/cut;
                else sum+=(pile[i]-cut)/cut-1;
            }
            Max=cut;
        }
        else
            Max=max(pile[i],Max);
    }
    //cout<<sum<<"| "<<Max<<endl;
    return sum+Max;
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B.out","w",stdout);
    int t,index=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int Max=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&pile[i]);
            Max=max(Max,pile[i]);
        }
        int hight=Max;
        int Min=0x3f3f3f3f;
        for(int i=1; i<=hight; i++)
        {
            Min=min(Min,judge(i));
        }
        printf("Case #%d: %d\n",index++,Min);
    }
    return 0;
}
