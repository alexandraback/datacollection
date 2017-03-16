#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
char str[1002];
int n;
int MX;
bool cons(int a,int b)
{
    MX=0;
    int f=0;
    int t=0;
    for(int i=a;i<=b;i++)
    {
        if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
        {
            t++;
        }
        else t=0;
        MX=max(MX,t);
        if(t>=n)
            return 1;
    }
    return 0;
}
int main()
{
    freopen("as.in","r",stdin);
    freopen("as.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int C=1;C<=T;C++)
    {
        scanf("%s %d",str,&n);
        int res=0;
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            for(int j=i;j<len;j++)
            {
                //printf("%d %d maxlen:%d\n",i,j,MX);
                if(cons(i,j))
                 {
                     res++;

                 }
            }
        }
        printf("Case #%d: %d\n",C,res);
    }
     return 0;
}
