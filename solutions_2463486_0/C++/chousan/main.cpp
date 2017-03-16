#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int ans[1100];

int main()
{
    freopen("5.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i;
    ans[0]=0;
    for(i=1;i<=1000;++i)
    {
        if(i<4)ans[i]=1;
        else if(i<9)ans[i]=2;
        else if(i<121)ans[i]=3;
        else if(i<484)ans[i]=4;
        else ans[i]=5;
    }
    int cas;
    scanf("%d",&cas);
    for(int c=1;c<=cas;++c)
    {
        printf("Case #%d: ",c);
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",ans[b]-ans[a-1]);
    }
    return 0;
}
