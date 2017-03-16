#include <cstdio>

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int tc;
    scanf("%d", &tc);
    for(int ti = 1; ti <= tc; ti++)
    {
        int maxn[110];
        int maxs[110];
        int mark[110];
        int n,s,p;
        scanf("%d%d%d", &n, &s, &p);
        int sum[110];
        for(int i = 0; i < n; i++){
            scanf("%d", &sum[i]);

            maxn[i] = sum[i]/3;
            if(sum[i]%3)maxn[i]++;

            maxs[i] = sum[i]/3+1;
            if(sum[i]%3==2)maxs[i]++;
            if(sum[i] <2 || sum[i] > 28)maxs[i] = -10;
            mark[i] = 0;
        }
        int cnt=0;
        for(int i = 0; i < n; i++){
            if(maxn[i] >= p){
                mark[i] = 1;
                cnt++;
            }
        }
        for(int i = 0; i < n && s > 0; i++){
            if(maxs[i] >= p && !mark[i]){
                s--;
                mark[i] = 1;
                cnt++;
            }
        }
        printf("Case #%d: %d\n", ti, cnt);

    }
    return 0;
}

