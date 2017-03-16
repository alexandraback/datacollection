#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


int J, P, S, K;
int a[3][3][3];
vector<pair<int, pair<int, int> > >ans; 
int maxx;

void dfs(int d, vector<pair<int, pair<int, int> > >tmp)
{
    if((int)tmp.size() >= maxx)
    {
        maxx = (int)tmp.size(); 
        ans = tmp;
    }
    if(d >= J * P * S)
    {
        return;
    }

    dfs(d + 1, tmp);

    int j, p, s;
    j = d % J;
    p = d / J % P;
    s = d / (J  * P) % S;
    if(a[0][p][s] + 1 <= K && a[1][j][s] + 1 <= K && a[2][j][p] + 1 <= K)
    {
        a[0][p][s] += 1;
        a[1][j][s] += 1;
        a[2][j][p] += 1;
        tmp.push_back(MP(j, MP(p, s)));
        dfs(d + 1, tmp);
        a[0][p][s] -= 1;
        a[1][j][s] -= 1;
        a[2][j][p] -= 1;
    }
}
int main() {
    freopen("in","r",stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d%d%d", &J, &P, &S, &K);
        printf("Case #%d: ", cas + 1);

        if(K >= S)
        {
            printf("%d\n", J * P * S);
            for(int i = 0; i < J; i++) for(int j = 0; j < P; j++) for(int k = 0; k < S; k++) printf("%d %d %d\n", i + 1, j + 1, k + 1);
        }
        else
        {
            clr(a, 0);
            maxx = -1;
            vector<pair<int, pair<int, int> > >tmp; 
            dfs(0, tmp);
            printf("%d\n", maxx);
            for(int i = 0; i < (int)ans.size(); i++)
            {
                printf("%d %d %d\n", ans[i].first + 1, ans[i].second.first + 1, ans[i].second.second + 1);
            }
        }
    }

    return 0;
}
