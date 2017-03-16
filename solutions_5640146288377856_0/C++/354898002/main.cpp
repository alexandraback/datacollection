#include <iostream>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<vector>
#include <algorithm>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int Cal(int m,int w)
{

    if(m == w)
        return m;

    int ans = 0;

    while(m-w > w)
        m -= w,ans++;

    return ans + w+1;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("data1.out","w",stdout);
    int n,m,w;

    int ans = 0;

    int T,icase = 1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d",&n,&m,&w);

        printf("Case #%d: %d\n",icase++,n*Cal(m,w));
    }


    return 0;
}






