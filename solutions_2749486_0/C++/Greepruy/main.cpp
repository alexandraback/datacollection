#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char ans[1000];
int main()
{
    freopen("2.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=0;cas<t;++cas)
    {
        printf("Case #%d: ",cas+1);
        int x,y;
        scanf("%d%d",&x,&y);
        int k=0;
        if(x>0)
        {
            for(int i=0; i<x; ++i)
            {
                ans[k++]='W';
                ans[k++]='E';
            }
        }
        else
        {
            for(int i=0; i>x; --i)
            {
                ans[k++]='E';
                ans[k++]='W';
            }
        }
        if(y>0)
        {
            for(int i=0; i<y; ++i)
            {
                ans[k++]='S';
                ans[k++]='N';
            }
        }
        else
        {
            for(int i=0; i>y; --i)
            {
                ans[k++]='N';
                ans[k++]='S';
            }
        }
        ans[k]='\0';
        printf("%s\n",ans);
    }
    return 0;
}
