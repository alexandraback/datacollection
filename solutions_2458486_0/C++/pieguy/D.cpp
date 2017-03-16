#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

struct door{
    int color;
    vector<int> keys;
};

char dp[1<<20];

vector<int> solve(const vector<int> keys, const vector<door> doors)
{
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
    int N = doors.size();
    queue<int> q;
    for(q.push(0); !q.empty(); q.pop())
    {
        int m=q.front();
        if(dp[m]==-1)
            continue;
        map<int, int> counts;
        for(int i=0; i<keys.size(); i++)
            counts[keys[i]]++;
        for(int i=0; i<N; i++)
        {
            if((m>>i)&1)
            {
                counts[doors[i].color]--;
                for(int j=0; j<doors[i].keys.size(); j++)
                    counts[doors[i].keys[j]]++;
            }
        }
        for(int i=0; i<N; i++)
        {
            if((m>>i)&1)
                continue;
            int next = m|(1<<i);
            if(dp[next]!=-1)
                continue;
            int c = doors[i].color;
            auto it = counts.find(c);
            if(it != counts.end() && it->second > 0){
                dp[next] = i;
                q.push(next);
            }
        }
    }
    if(dp[(1<<N)-1] == -1)
        return vector<int>();
    vector<int> res;
    for(int at=(1<<N)-1; at!=0; at^=1<<dp[at])
    {
        res.push_back(dp[at]+1);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        fprintf(stderr, "t=%d\n", t);
        vector<int> keys;
        int K, N;
        scanf("%d %d", &K, &N);
        while(K--)
        {
            int c;
            scanf("%d", &c);
            keys.push_back(c);
        }
        vector<door> doors(N);
        for(int i=0; i<N; i++)
        {
            int c, n;
            scanf("%d %d", &c, &n);
            doors[i].color=c;
            while(n--)
            {
                scanf("%d", &c);
                doors[i].keys.push_back(c);
            }
        }
        vector<int> ans = solve(keys, doors);
        printf("Case #%d:", t);
        if(!ans.size())
        {
            puts(" IMPOSSIBLE");
        }else{
            for(int i=0; i<ans.size(); i++)
            {
                printf(" %d", ans[i]);
            }
            puts("");
        }
    }
}
