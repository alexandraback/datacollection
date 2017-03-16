#include <cstdio>

    int T, N, S, p;
    int t;

int main()
{
    scanf("%d", &T);
    for(int z=1; z<=T; ++z) {
        scanf("%d %d %d", &N, &S, &p);
        int ans = 0;
        for(int i=0; i<N; ++i) {
            scanf("%d", &t);
            int h = t/3;
            if(t%3) {
                ++h;
            }
            if(t%3==0 || t%3==2) {
                if(h>0 && h<10 && h==p-1 && S>0) {
                    ++h;
                    --S;
                }
            }
            if(h>=p) {
                ++ans;
            }
        }
        printf("Case #%d: %d\n", z, ans);
    }
    return 0;
}
