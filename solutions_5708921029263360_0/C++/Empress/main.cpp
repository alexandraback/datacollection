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
bool flag;
void DFS(int x, int num)
{
    if(x==d)
    {
        if(num==ans)
            flag=1;
        return ;
    }
    int i=mp[x].first.first, j=mp[x].first.second, k=mp[x].second;
    if(mp1[i][j]<K && mp2[i][k]<K && mp3[j][k]<K)
    {
        mp1[i][j]++, mp2[i][k]++, mp3[j][k]++;
        DFS(x+1, num+1);
        if(flag==1)
        {
            printf("%d %d %d\n", i, j, k);
            return ;
        }
        mp1[i][j]--, mp2[i][k]--, mp3[j][k]--;
    }
    DFS(x+1, num);
}

int main()
{
    freopen("C-small-attempt6.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int J, P, S;
        scanf("%d%d%d%d", &J, &P, &S, &K);
        printf("Case #%d: ", ca++);
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        memset(mp3, 0, sizeof(mp3));
//        int ans1=0;
        d=0;
        for(int i=1;i<=J;i++)
            for(int j=1;j<=P;j++)
                for(int k=1;k<=S;k++)
                    mp[d++]=make_pair(make_pair(i, j), k);
        ans=0;
        dfs(0, 0);
        printf("%d\n", ans);
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        memset(mp3, 0, sizeof(mp3));
        flag=0;
        DFS(0, 0);
    }
    return 0;
}
/*
100
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
2 2 2 1
1 1 3 3
1 1 2 1
1 1 3 8
1 3 3 7
1 1 2 3
1 1 1 5
2 3 3 6
1 1 2 5
2 2 3 4
3 3 3 8
2 2 2 9
1 1 2 10
2 3 3 7
2 2 3 2
1 3 3 10
1 1 2 9
1 2 3 10
2 3 3 3
1 1 2 7
2 2 3 1
1 2 2 10
2 3 3 2
1 1 1 7
3 3 3 4
3 3 3 3
1 2 2 1
1 1 1 8
2 3 3 8
3 3 3 5
3 3 3 2
2 2 2 2
3 3 3 9
2 3 3 1
1 2 2 6
1 1 2 2
3 3 3 6
2 2 2 6
1 3 3 2
1 1 3 10
1 3 3 6
3 3 3 7
2 2 3 9
2 2 3 5
1 2 2 9
2 3 3 10
2 3 3 9
1 2 2 7
3 3 3 10
1 3 3 1
2 2 2 10
2 2 2 8
1 2 2 4
1 2 3 7
1 1 3 5
2 2 2 3
2 3 3 4
2 2 3 8
1 2 3 9
1 1 1 4
1 1 3 1
1 2 2 3
2 2 2 7
1 2 3 3
1 1 1 9
1 2 2 8
2 2 3 7
1 2 3 6
1 1 3 4
1 3 3 3
1 3 3 4
3 3 3 1
1 2 3 5
2 3 3 5
1 3 3 9
2 2 2 5
1 1 3 6
2 2 3 10
1 1 1 2
2 2 2 4
1 2 2 2
1 3 3 8
1 2 3 8
1 2 2 5
1 1 3 9
1 1 3 7
2 2 3 6
1 3 3 5
1 1 2 4
1 1 2 8
1 1 1 6
1 1 1 3
1 1 1 1
1 2 3 4
1 1 2 6
2 2 3 3

*/
