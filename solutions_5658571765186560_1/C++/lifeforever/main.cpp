#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int R,C,X;
    int T,index=1;
    freopen("D-large.in","r",stdin);
    freopen("D1.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&X,&R,&C);
        if((R%X==0||C%X==0)&&R>=X-1&&C>=X-1){
            printf("Case #%d: GABRIEL\n",index++);
        }
        else{

            printf("Case #%d: RICHARD\n",index++);
        }
    }
    return 0;
}
