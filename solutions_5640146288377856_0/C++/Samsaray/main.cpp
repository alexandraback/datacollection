#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int ans,T,R,C,W;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d%d%d",&R,&C,&W);

        ans = R*(C/W)+ W;
        if(C%W==0){
            ans--;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
