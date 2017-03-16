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

int a[200][200];
int row[200];
int col[200];

int main()
{
int t,r,c,i,j,m1,m2;
cin>>t;
for(int ch=1;ch<=t;ch++)
{
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        m1=0;
        for(j=0;j<c;j++)
        {
            m1=max(m1,a[i][j]);
        }
        row[i]=m1;
    }
    for(j=0;j<c;j++)
    {
        m1=0;
        for(i=0;i<r;i++)
        {
            m1=max(m1,a[i][j]);
        }
        col[j]=m1;
    }
    bool found=true;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(!(a[i][j]==row[i] || a[i][j]==col[j]))
            {
                found=false;
                break;
            }
        }
        if(!found)break;
    }
    if(found)
    printf("Case #%d: YES\n",ch);
    else
    printf("Case #%d: NO\n",ch);
}
return 0;
}
