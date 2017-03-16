#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair<PI, int> PII;
const double eps=1e-5;
const int inf=1e5;
const double pi=acos(-1.0);
const int N=5e5+5;

int mp1[15][15], mp2[15][15], mp3[15][15];
PII mp[100005];
int ans, d, K;
void dfs(int x, int num)
{
    if(x==d)
    {
        ans=max(ans, num);
        return ;
    }
    int i=mp[x].first.first, j=mp[x].first.second, k=mp[x].second;
    if(mp1[i][j]<K && mp2[i][k]<K && mp3[j][k]<K)
    {
        mp1[i][j]++, mp2[i][k]++, mp3[j][k]++;
        dfs(x+1, num+1);
        mp1[i][j]--, mp2[i][k]--, mp3[j][k]--;
    }
    dfs(x+1, num);
}
//int main()
//{
////    freopen("C-small-attempt4.in", "r", stdin);
////    freopen("C.out", "w", stdout);
//    int t, ca=1;
//    scanf("%d", &t);
//    while(t--)
//    {
//        int J, P, S;
//        scanf("%d%d%d%d", &J, &P, &S, &K);
//        printf("Case #%d: ", ca++);
//        memset(mp1, 0, sizeof(mp1));
//        memset(mp2, 0, sizeof(mp2));
//        memset(mp3, 0, sizeof(mp3));
//        int ans1=0;
//        d=0;
//        for(int i=1;i<=J;i++)
//            for(int j=1;j<=P;j++)
//                for(int k=1;k<=S;k++)
//                {
//                    mp[d++]=make_pair(make_pair(i, j), k);
////                    if(mp1[i][j]<K && mp2[i][k]<K && mp3[j][k]<K)
////                        ans1++, mp1[i][j]++, mp2[i][k]++, mp3[j][k]++;
//                }
//        ans=0;
//        dfs(0, 0);
//        printf("%d\n", ans);
//    }
//    return 0;
//}
/*
100
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
1 2 3 3
2 2 3 8
1 1 1 9
2 3 3 6
3 3 3 6
2 2 2 3
1 1 1 8
1 3 3 4
1 1 2 5
2 2 2 5
2 3 3 5
1 1 2 3
1 1 2 6
2 2 2 1
3 3 3 8
1 1 3 10
3 3 3 5
2 3 3 1
2 2 2 9
1 1 3 7
1 2 2 1
1 1 3 6
1 3 3 9
1 2 3 9
3 3 3 7
1 1 3 4
2 2 3 7
1 1 1 6
3 3 3 10
1 3 3 3
1 2 2 8
1 2 2 4
2 3 3 4
2 3 3 3
2 3 3 8
1 3 3 8
1 2 3 5
1 2 2 3
1 2 2 6
2 2 2 2
3 3 3 3
1 1 1 5
2 2 3 1
2 2 2 7
1 3 3 10
1 1 2 2
1 2 2 9
1 2 3 6
1 1 2 8
2 2 3 6
3 3 3 1
3 3 3 4
2 2 3 2
1 1 3 5
2 3 3 9
1 3 3 2
1 3 3 5
2 2 3 3
1 1 2 9
1 2 3 10
1 2 2 2
3 3 3 2
1 1 1 2
2 2 2 10
2 2 2 6
1 1 2 10
2 2 3 9
2 2 2 4
1 2 2 5
1 2 2 7
3 3 3 9
2 2 3 5
2 2 2 8
1 2 3 7
1 2 3 4
1 2 2 10
1 1 2 4
2 3 3 7
1 3 3 1
2 2 3 10
1 1 2 7
2 3 3 10
1 2 3 8
1 1 3 8
1 1 1 3
1 1 3 9
1 1 2 1
2 2 3 4
1 1 3 3
1 1 1 1
1 1 1 4
1 1 3 1
2 3 3 2
1 3 3 6
1 1 1 7
1 3 3 7

*/

int g[55][55];
LL cnt[55];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        LL b, m;
        scanf("%I64d%I64d", &b, &m);
        printf("Case #%d: ", ca++);
        if(b==2)
        {
            if(m==1)
            {
                puts("POSSIBLE");
                puts("01\n00");
            }
            else
                puts("IMPOSSIBLE");
            continue;
        }
        memset(g, 0, sizeof(g));
        for(int i=2; i<=b-1; i++)
        {
            cnt[i] = 1ll << (i - 2);
            for(int j=2; j<i; j++)
                g[i][j] = 1;
            g[i][b] = 1;
        }

        if((m & (m -1))==0)
            m--, g[1][b] = 1;

        LL val = 0;
        for(int j=2; j<=b-1; j++)
        {
            int idx = j - 2;
            if( m & (1ll << idx) )
            {
                val+=1ll<<idx;
                g[1][j]=1;
            }
        }
        if(val!=m)
            puts("IMPOSSIBLE");
        else
        {
            puts("POSSIBLE");
            for(int i=1; i<=b; i++)
            {
                for(int j=1; j<=b; j++)
                    printf("%d", g[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
