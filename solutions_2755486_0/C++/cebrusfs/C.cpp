#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 1005
#define MAXd 676065
#define MAXw 1000
#define SHIFT 1000

using namespace std;

struct data
{
    int w, e, s;

    data (int a, int b, int c) : w(a), e(b), s(c) 
    {
    }
};
int h[MAXw+SHIFT];

vector<data> ary[MAXd];

int main()
{
    int T;
    scanf("%d", &T);


    for(int Ti=1; Ti<=T; Ti++)
    {
        int N;
        scanf("%d", &N);

        memset(h, 0, sizeof(h));
        for(int i=0; i<MAXd; i++)
            ary[i].clear();

        for(int i=0; i<N; i++)
        {
            int d, n, w, e, s, dd, dp, ds;
            scanf("%d %d %d %d %d %d %d %d", 
                    &d, &n, &w, &e, &s, 
                    &dd, &dp, &ds);
            --e;

            ary[d].push_back( data(w, e, s) );

            for(int j=1; j<n; j++)
            {
                d += dd;
                w += dp;
                e += dp;
                s += ds;

                ary[d].push_back( data(w, e, s) );
            }
        }

        int ans = 0;
        for(int i=0; i<MAXd; i++)
        {
            for( data d : ary[i] )
            {
                //printf("day %d : [%d %d] %d\n", i, d.w, d.e, d.s);
                int l = d.w + SHIFT, r = d.e + SHIFT;

                bool flag = 0;
                for(int j = l; j <= r; j++ )
                    if( h[j] < d.s )
                        flag = 1;

                ans += flag;
            }

            for( data d : ary[i] )
            {
                int l = d.w + SHIFT, r = d.e + SHIFT;

                for(int j = l; j <= r; j++ )
                    h[j] = max(h[j], d.s);
            }
        }
        printf("Case #%d: %d\n", Ti, ans);
    }

}
