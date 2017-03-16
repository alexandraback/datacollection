#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    freopen("B-small-attempt1 (1).in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int caseno=1; caseno<=t; caseno++)
    {
        int a,b,k,i,j, ans=0;
        scanf("%d%d%d",&a,&b,&k);

        for(i=0; i<a; i++)
            for(j=0; j<b; j++)
                if( (i&j) < k ) ans++;


        printf("Case #%d: %d\n",caseno, ans);

    }


    return 0;
}



