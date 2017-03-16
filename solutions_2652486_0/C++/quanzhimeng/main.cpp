#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int cases;
    int t;
    int i;
    int r,n,m,k;
    int a[100];
    scanf("%d",&cases);
    t=1;
    while(cases--)
    {
        printf("Case #%d:\n",t);
        t++;
        scanf("%d%d%d%d",&r,&n,&m,&k);
        while(r--)
        {
            for(i=0;i<k;++i)
            {
                scanf("%d",&a[i]);
            }
            sort(a,a+k);
        }
    }
    return 0;
}
