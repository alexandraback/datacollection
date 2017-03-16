#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n, m;
long long line1[110][2];
long long line2[110][2];
long long list[110][110];
long long remain[110][110];
long long cnt[110], rem[110];

int main()
{
    int aa, nn, i, j, k, h;
    long long t, tt, tmp, ans;
    scanf("%d", &nn);
    for ( aa = 1; aa <= nn; ++aa ) {
        scanf("%d %d",&n,&m);
        for ( i = 0; i < n; ++i ) {
            scanf("%lld %lld",&line1[i][0], &line1[i][1]);
        }
        for ( i = 0; i < m; ++i ) {
            scanf("%lld %lld",&line2[i][0], &line2[i][1]);
        }
        memset(list,0,sizeof(list));

        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < m; j++ ) {
                cnt[j] = 0; rem[j] = line2[j][0];
                for ( k = 0; k < i; k++ ) {
                    if (list[k][j] > cnt[j] ) {
                        cnt[j] = list[k][j];
                        rem[j] = remain[k][j];
                    }
                }
                //printf("%d %d %lld %lld\n",i,j,cnt[j],rem[j]);
                t = line1[i][0]; tt = cnt[j];
                if (line1[i][1] == line2[j][1]) {
                    tmp = min(rem[j],t);
                    tt += tmp; t-= tmp;
                    if ( tt > list[i][j] ) {
                        list[i][j] = tt;
                        remain[i][j] = rem[j]-tmp;
                    }
                }
                //printf("-> %lld %lld\n",t,tt);
                for ( k = j+1; t && k < m; k++ ) {
                    if (line1[i][1] != line2[k][1]) {
                        remain[i][k] = line2[k][0];
                        list[i][k] = list[i][k-1];
                        continue;
                    }
                    tmp = min(t,line2[k][0]);
                    tt += tmp; t -= tmp;
                    if ( tt > list[i][k] ) {
                        list[i][k] = tt;
                        remain[i][k] = line2[k][0]-tmp;
                    }
                }
            }
        }
        //printf("-> %lld\n",remain[0][2]);
/*
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < i; j++) {
                for ( k = 0; k < m; k++ ) {
                    if (list[j][k] == 0 ) continue;
                    t = line1[i][0]; tt = list[j][k];
                    if (line1[i][1] == line1[j][1]) {
                        tmp = min(remain[j][k],t);
                        tt += tmp; t-= tmp;
                        if ( tt > list[i][k] ) {
                            list[i][k] = tt;
                            remain[i][k] = remain[j][k]-tmp;
                        }
                    }
                    for ( h = k+1; t && h < m; h++ ) {
                        if (line1[i][1] != line2[h][1]) continue;
                        tmp = min(t,line2[h][0]);
                        tt += tmp; t -= tmp;
                        if (tt > list[i][h]) {
                            list[i][h] = tt;
                            remain[i][h] = line2[h][0]-tmp;
                        }
                    }
                }
            }
            // start from beginning
            t = line1[i][0]; tt = 0;
            for ( j = 0; t && j < m; j++ ) {
                if (line1[i][1] != line2[j][1]) continue;
                tmp = min(t,line2[j][0]);
                tt += tmp; t -= tmp;
                if ( tt > list[i][j] ) {
                    list[i][j] = tt;
                    remain[i][j] = line2[j][0]-tmp;
                }
            }
        }
*/
        ans = 0;
        for ( i = 0; i < n; i++ ) {
            for (j = 0; j < m; j++ ) {
                ans = max(ans,list[i][j]);
            }
        }
        printf("Case #%d: %lld\n",aa,ans);
    }
    return 0;
}

