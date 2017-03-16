#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair

typedef pair<int, int> PII;
typedef pair<int, PII> triple;

#define MAXN 120
int N, S, P;
int sum[MAXN];
vector< triple > V[31];
inline void pre_compute()
{
    for(int a=0;a<=10;a++)
    {
        for(int b=a;b<=10;b++)
        {
            for(int c=b;c<=10;c++)
            {
                if((c - a) > 2)continue;
                V[a+b+c].push_back(mp(a, mp(b, c)));
            }
        }

    }

}

#define INF (int)1e8
int memo[MAXN][MAXN];
int solve(int idx, int S)
{
    int &ret = memo[idx][S];
    if(ret != -1) return ret;

    if(idx == N)
    {
        if(S == 0)
        return ret = 0;
        else
        return ret = -INF;
    }

    // try possible scores for idx
    int x = sum[idx];
    ret = 0;
    for(int i=0;i<V[x].size();i++)
    {
        triple t = V[x][i];
        int a = t.first;
        int b = t.second.first;
        int c = t.second.second;
        if((c - a) == 2)
        {
            if(S > 0)
            {
                ret = max(ret, (c>=P) + solve(idx+1, S-1));
            }
        }
        else
        ret = max(ret, (c>=P) + solve(idx+1, S));
    }
    return ret;
}
int main()
{
    pre_compute();
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for(int cases=1;cases<=T;cases++)
    {
        cin >> N >> S >> P;
        for(int i=0;i<N;i++)
        cin >> sum[i];
        memset(memo, -1, sizeof memo);
        cout << "Case #" << cases << ": " << solve(0, S) << endl;
    }

}
