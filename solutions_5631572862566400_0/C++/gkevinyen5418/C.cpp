#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int F[2000];
vector<int> v[2000];

bool visit[2000];
bool in[2000];

int mx;
stack<int> stk;

void DFS(int O)
{
    visit[O] = true;
    in[O] = true;
    stk.push(O);

    if( visit[F[O] ] && !in[F[O] ] );
    else if( visit[F[O] ] )
    {
        int cnt = 1;

        while( stk.top() != F[O] )
        {
            in[stk.top() ] = false, stk.pop();
            cnt++;
        }

        mx = max(mx, cnt);
    }
    else DFS(F[O] );

    if( in[O] )
    {
        in[O] = false;
        stk.pop();
    }
}

int DFS(int O, int a, int b)
{
    int r = 0;

    for(int vi = 0; vi < v[O].size(); vi++)
        if( v[O][vi] != a && v[O][vi] != b )
            r = max(r, DFS(v[O][vi], a, b) );

    return r+1;
}

int solve(int a, int b)
{
    return DFS(a, a, b) + DFS(b, a, b);
}

int main()
{
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        int N;
        scanf("%d", &N);

        for(int Ni = 1; Ni <= N; Ni++)
        {
            scanf("%d", &F[Ni]);
            visit[Ni] = false;
            v[Ni].clear();
        }

        for(int Ni = 1; Ni <= N; Ni++)
            v[F[Ni] ].push_back(Ni);

        mx = 0;

        for(int Ni = 1; Ni <= N; Ni++)
            if( !visit[Ni] ) DFS(Ni);

        int ans = mx;

        int sum = 0;

        for(int Ni = 1; Ni <= N; Ni++)
            if( F[F[Ni] ] == Ni && Ni < F[Ni] ) sum += solve(Ni, F[Ni]);

        ans = max(ans, sum);

        printf("Case #%d: %d\n", Ti, ans);
    }
}
