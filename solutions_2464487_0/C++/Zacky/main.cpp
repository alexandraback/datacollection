#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int cas,T,r,t,cnt,cost;
    scanf("%d",&T);
    for(cas = 1;cas <= T;++cas) {
        scanf("%d %d",&r,&t);
        cnt = 0;
        while(t > 0) {
            if(t < 2 * r + 1) break;
            t -= 2 * r + 1;
            cnt++;
            r = r + 2;
        }
        printf("Case #%d: %d\n",cas,cnt);
    }
}
