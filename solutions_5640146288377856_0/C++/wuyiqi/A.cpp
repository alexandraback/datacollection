#include <bits/stdc++.h>

int main()
{
        freopen("A-small-attempt0.in","r",stdin);
        freopen("out.txt", "w", stdout);
        int t, ca = 1;
        scanf("%d", &t);
        while(t--) {
                int r,c,w;
                scanf("%d%d%d", &r, &c, &w);
                int ret;
                if(c % w == 0) {
                        ret = (c / w + w - 1) + (r - 1) * c / w;
                } else {
                        ret = (c / w + 1 + w - 1)  + (r - 1) * c / w;
                }
                printf("Case #%d: %d\n",ca ++, ret);
        }
        return 0;
}
