#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,R,C,w;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d%d",&R,&C,&w);
        int res=0;
        res=(C/w)*R;
        res+=w-1;
        if(C%w!=0) res++;
        printf("Case #%d: %d\n",kase,res);
    }
    return 0;
}
