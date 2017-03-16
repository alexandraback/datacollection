#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t,x;
    char s[2000];
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        scanf("%d %s",&x,s);
        int tro=0,rez=0;
        for(int i=0;i<x+1;i++)
        {
            if(tro<i && s[i]!='0'){
                rez+=-tro+i;
                tro=i;
            }
            tro+=s[i]-'0';
        }
        printf("Case #%d: %d\n",CASE,rez);
    }
    return 0;
}
