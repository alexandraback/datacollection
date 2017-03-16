#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
bool ok(char c)
{
    if(c!='a'&&c!='e'&&c!='o'&&c!='u'&&c!='i')return true;
    else return false;
}
int main()
{
   // freopen("B-small-attempt0.in", "r", stdin);
   // freopen("b.out", "w", stdout);
    int x,y,t,_=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",++_);
        if(x>0)
         for(int i=0;i<x;++i)
          printf("WE");
        else
         for(int i=0;i>x;--i)
          printf("EW");

        if(y>0)
         for(int i=0;i<y;++i)
          printf("SN");
        else
         for(int i=0;i>y;--i)
          printf("NS");
        printf("\n");
    }
    return 0;
}

