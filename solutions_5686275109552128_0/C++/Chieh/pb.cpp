#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int s[1000000];
int ans;

void Solve(int n, int ti)
{
    int *tmp = new int[n];
    if( ti > ans ) return;
    //special
    int mx = s[0], idx = 0;
    for( int i = 1; i < n; i++ )
        if( s[i] > mx )
        {
            mx = s[i];
            idx = i;
        }
    for( int i = 1; i <= s[idx] / 2; i++ )
    {
        s[idx] -= i;
        s[n] = i;
        Solve(n + 1, ti + 1);
        s[idx] += i;
    }

    for( int i = 0; i < n; i++ ) tmp[i] = s[i];
    for( int i = 0; i < n; i++ ) s[i]--;
    idx = 0;
    for( int i = 0; i < n; i++ )
        if( s[i] != 0 ) s[idx++] = s[i];
    if( idx == 0 ) ans = min(ans, ti);
    else Solve(idx, ti + 1);
    for( int i = 0; i < n; i++ ) s[i] = tmp[i];
    delete []tmp;
    return;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 0; tt < cases; tt++ )
    {
        int n, idx = 0;
        scanf("%d", &n);
        ans = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &s[i]);
            ans = max(ans, s[i]);
        }
        for( int i = 0; i < n; i++ )
            if( s[i] != 0 ) s[idx++] = s[i];
        Solve(idx, 1);
        printf("Case #%d: %d\n", tt + 1, ans);
    }
    return 0;
}
