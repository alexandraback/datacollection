#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
using namespace std;

#define pi (2*acos(0.0))
#define inf 1<<30
#define maxi(a,b) ((a>b)?a:b)
#define mini(a,b) ((a>b)?b:a)
#define pb(a) push_back(a)
#define sz 20
int r,c;
int arr[sz][sz];

bool solve(int val,int row,int col)
{
    int i,j;
    bool a=true,b=true;

    for(i=1;i<=c;i++)
    {
        if(arr[row][i]>val)
        {
          a=false;
          break;
        }
    }

    for(i=1;i<=r;i++)
    {
        if(arr[i][col]>val)
        {
            b=false;
            break;
        }
    }
    if(!a && !b)    return false;

    return true;
}


int main()
{
    int i,j,k,num,t,test;


    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        scanf("%d%d",&r,&c);

        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
                scanf("%d",&arr[i][j]);
        }

        bool flag=true;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(!solve(arr[i][j],i,j))
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)   break;
        }

        printf("Case #%d: ",t);
        if(flag)
            printf("YES");
        else
            printf("NO");
        puts("");


    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

