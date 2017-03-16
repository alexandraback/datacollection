#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int tc,ans;
    scanf("%d",&tc);
    for (int i=0; i<tc; i++)
    {
        printf("Case #%d: ",i+1,ans);
        //Read in stuff
        int x,y;
        scanf("%d%d",&x,&y);
        if (y<0)
        {
           for (int j=0; j<(-y); j++)
           {
               printf("NS");
           }
        }
        if (x<0)
        {
           for (int j=0; j<(-x); j++)
           {
               printf("EW");
           }
        }
        if (y>0)
        {
           for (int j=0; j<y; j++)
           {
               printf("SN");
           }
        }
        if (x>0)
        {
           for (int j=0; j<x; j++)
           {
               printf("WE");
           }
        }
        //Return ans
        printf("\n");
    }
}
