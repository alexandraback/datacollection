#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[110];
int main()
{
    int T;
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        int N,S,P;
        scanf("%d%d%d",&N,&S,&P);
        int i;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        int ok,justsoso;
        ok=3*P-2;
        justsoso=3*P-4;
        if(justsoso<P)
            justsoso=P;
        sort(a,a+N,cmp);
//        printf("ok:%d\tjustsoso:%d\n",ok,justsoso);
        int res=0;
        for(i=0;i<N;i++)
        {
            if(a[i]>=ok)
                res++;
            else if(a[i]>=justsoso && S)
            {
                S--;
                res++;
            }
        }
        printf("Case #%d: %d\n",_,res);
    }
    return 0;
}
