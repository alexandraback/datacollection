#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#define maxn 2000000
using namespace std;
int num[2000005]={0};
int b[2000005]={0};
int Q[100];

int main()
{
    freopen("aa.txt","r",stdin);
    freopen("bb.txt","w",stdout);

    int x,i,y,fac=100,top=0;

    int cas,ta=1;
    cin >> cas;

    while(cas--)
    {
        int A,B;
        scanf("%d%d",&A,&B);

        int ans = 0;
        fac = 1;
        while(fac/B == 0) fac*=10;

        for(x=A; x<=B; x++)
        {
                top = 0;
                for(i=10; x/i; i*=10)
                {
                    y = x/i + (x%i)*fac/i;

                    if(y*10/fac && y<x && y>=A && !b[y])
                    {
                        ans++;
                        b[y] = 1;
                        Q[top++] = y;
                    }
                }
                for(i=0; i<top; i++) b[Q[i]] = 0;
        }
        printf("Case #%d: %d\n",ta++,ans);
    }
    return 0;
}
