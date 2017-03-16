#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int T;
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    int num[10];
    int v[10000];
    for(int k = 1;k <= T; ++k)
    {
        printf("Case #%d:\n",k);
        int R,N,M,K;
        scanf("%d%d%d%d",&R,&N,&M,&K);
        for(int i = 0;i < R; ++i)
        {
            for(int j = 0;j < K; ++j)
            {
                scanf("%d",&num[j]);
            }
            memset(v,0,sizeof(v));
            bool oo = 1;
            for(int t1 = 2;t1 <= M; ++t1)
            {
                for(int t2 = 2;t2 <= M; ++t2)
                {
                    for(int t3 = 2;t3 <= M; ++t3)
                    {
                        memset(v, 0, sizeof(v));
                        v[t1*t2*t3] = 1;
                        v[t1*t2] = 1;
                        v[t1*t3] = 1;
                        v[t3*t2] = 1;
                        v[t1] = 1;
                        v[t2] = 1;
                        v[t3] = 1;
                        v[1] = 1;
                        bool flag = 0;
                        for (int j = 0; j < K; ++j)
                        if (v[num[j]] == 0) {
                            flag = 1;
                        }
                        if (!flag) {
                            oo = 0;
                            printf("%d%d%d\n",t1,t2,t3);
                            break;
                        }
                    }
                    if (oo == 0) break;
                }
                if(oo == 0) break;
            }
            if(oo == 1)
                printf("222\n");
        }
        return 0;
    }
}
