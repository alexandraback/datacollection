#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//int cal(int x,int w)
//{
//    if(x<w) return 0;
//    if(x==w) return 1;
//    int m=x/2;
//    return 1+cal(m-1,w)+cal(x-m,w);
//}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,kcase=0;
    scanf("%d",&t);
    while(t--)
    {
        int r,c,w;
        scanf("%d%d%d",&r,&c,&w);
        int ans=(r-1)*(c/w)+c/w+w-1;
        if(c%w) ans++;
//        cout<<cal(c,w)<<endl;
        printf("Case #%d: %d\n",++kcase,ans);

    }
    return 0;
}
