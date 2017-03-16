#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define maxn 1005
#define INF 1000000000

int main()
{
    int T,cas=1,a,b,k;
    scanf("%d",&T);
    while(T--)
    {
        int res=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                if((i&j) < k) res++;
        printf("Case #%d: %d\n",cas++,res);
    }
    return 0;
}
