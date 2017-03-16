#include <bits/stdc++.h>

using namespace std;

int K, C, S;
vector<int> group[100];
long long pw[101];

void _main(int TEST)
{
    scanf("%d%d%d", &K, &C, &S);
    int goal=(K+C-1)/C;
    if(S<goal)
    {
        printf(" IMPOSSIBLE\n");
        return;
    }
    for(int i=0; i<K; i++)
        group[i].clear();
    for(int i=0; i<K; i++)
        group[i/C].push_back(i);
    pw[0]=1;
    for(int i=1; i<=C; i++)
        pw[i]=1LL*pw[i-1]*K;
    for(int i=0; i<K; i++) if(!group[i].empty())
    {
        long long pos=0;
        for(int j=0; j<(int)group[i].size(); j++)
            pos+=group[i][j]*pw[C-j-1];
        printf(" %lld", pos+1);
    }
    printf("\n");
}

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d:", i);
        _main(i);
    }
    return 0;
}
