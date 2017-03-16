#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<climits>
using namespace std;

int t, arr[110][110], maxcol[110], maxrow[110], n, m, temp, flag, counter=1;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&arr[i][j]);
        for(int i=1; i<=n; i++)
        {
            temp=1;
            for(int j=1; j<=m; j++)
                temp=max(temp, arr[i][j]);
            maxrow[i]=temp;
        }
        for(int j=1; j<=m; j++)
        {
            temp=1;
            for(int i=1; i<=n; i++)
                temp=max(temp, arr[i][j]);
            maxcol[j]=temp;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if((arr[i][j]<maxrow[i])&&(arr[i][j]<maxcol[j]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            printf("Case #%d: YES\n", counter++);
        else
            printf("Case #%d: NO\n", counter++);
    }
    return 0;
}
