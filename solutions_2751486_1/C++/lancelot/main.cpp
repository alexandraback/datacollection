#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
char str[1000002];
int n;
int MX;
bool isCon(char c)
{
    if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u')
        return true;
    return false;
}
int main()
{
    freopen("ab.in","r",stdin);
    freopen("ab.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int C=1;C<=T;C++)
    {
        scanf("%s %d",str,&n);
        long long  res=0;
        int len=strlen(str);
        int t=0;
        long long  mk=-1;
        for(int i=0;i<len;i++)
        {
            if(isCon(str[i]))
               {
                   t++;
               }
               else t=0;
                if(t>=n)
                {
                    mk=i+1-n;
                }
                res+=mk+1;
        }
        printf("Case #%d: %lld\n",C,res);
    }
     return 0;
}
