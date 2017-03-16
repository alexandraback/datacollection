#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
bool seen[1001];
int last;
bool two[1001];
bool endstwo;
int lpath[1001];

int dfs(int u)
{
    if(seen[u])
    {
        last=u;
        if(two[u])
            endstwo=true;
        return 0;
    }
    seen[u]=true;
    int ret=dfs(A[u])+1;
    seen[u]=false;
    return ret;
}

void _main(int TEST)
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), lpath[i]=0;
    int ans=0;
    for(int i=1; i<=N; i++)
    {
        two[i]=i==A[A[i]];
        ans+=two[i];
    }
    int total=ans;
    for(int i=1; i<=N; i++)
    {
        endstwo=false;
        int ret=dfs(i);
        if(endstwo)
        {
            ans=max(ans, ret);
            lpath[last]=max(lpath[last], ret-2);
        }
        if(i==last)
            ans=max(ans, ret);
    }
    for(int i=1; i<=N; i++) if(two[i])
        total+=lpath[i];
    ans=max(ans, total);
    printf("%d\n", ans);
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
