#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t,cas,i,j,k,n,a,b;
    cin>>t;
    for (cas=1; cas<=t; cas++)
    {
        cin>>n;
        int data[1010][1010]={0};
        for (i=1; i<=n; i++)
        {
            cin>>a;
            for (j=0; j<a; j++)
            {
                cin>>b;
                data[i][b]++;
            }
        }
        for (k=1; k<=n; k++)
        {
            for (i=1; i<=n; i++)
            {
                for (j=1; j<=n; j++)
                {
                    if (data[i][k] && data[k][j]) data[i][j]++;
                }
            }
        }
        bool ans=0;
        for (i=1; i<=n; i++)
        {
            for (j=1; j<=n; j++)
            {
                if (data[i][j]>1) ans=1;
                if (ans) break;
                //printf("%d ",data[i][j]);
            }
            //printf("\n");
            if (ans) break;
        }
        if (ans) printf("Case #%d: Yes\n",cas);
        else     printf("Case #%d: No\n",cas);
    }
    return 0;
}
