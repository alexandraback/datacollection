#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 102;
int n,c,s,p;

void solve()
{
    scanf("%d %d %d",&n,&s,&p);
    int res = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c);
        int tmp = c % 3;
        if(tmp == 0)
        {
            if(c/3 >= p)
            {
                res++;
            }
            else if(s && (c/3+1) >= p && (c/3+1) <= 30 && (c/3-1) >= 0)
            {
                s--;
                res++;
            }
        }
        else if(tmp == 1)
        {
            if((c/3+1) >= p)
            {
                res++;
            }
        }
        else
        {
            if((c/3+1) >= p)
            {
                res++;
            }
            else if(s && (c/3+2) >= p)
            {
                s--;
                res++;
            }
        }
    }
    printf("%d\n",res);
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas,x = 0;
    scanf("%d",&cas);
    while(x < cas)
    {
        printf("Case #%d: ",++x);
        solve();
    }
    return 0;
}
