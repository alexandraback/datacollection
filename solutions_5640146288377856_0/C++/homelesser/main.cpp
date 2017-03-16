#include <iostream>
#include <cstdio>
using namespace std;

int T;
int R,C,W;

int calc_first(int R,int C,int W) {
    if (C >= W * 2) {
        return calc_first(R, (C+1) / 2, W) + R;
    }
    return R;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w",stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <=T; cas ++) {
        scanf("%d%d%d",&R,&C,&W);
        int ans = 0;
        ans += R*((C/W)+(C%W!=0));
        ans += W-1;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
