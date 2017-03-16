#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

int a[15][15];

bool checkr(int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[x][i]!=1)return false;
    }
    return true;
}
bool checkc(int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i][x]!=1)return false;
    }
    return true;
}
int main()
{
int t,i,j,r,c;
cin>>t;
for(int ch=1;ch<=t;ch++)
{
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    bool poss=true;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==1)
            {
                if(checkr(i,c)==false && checkc(j,r)==false)
                {
                    poss=false;break;
                }
            }
        }
        if(!poss)break;
    }
    if(poss)
    printf("Case #%d: YES\n",ch);
    else
    printf("Case #%d: NO\n",ch);
}
return 0;
}
