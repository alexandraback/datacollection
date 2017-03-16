#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

typedef long long i64d;

const int maxN = 256;

int N, M;
i64d a[maxN], A[maxN];
i64d b[maxN], B[maxN];

i64d ans;

void dfs(int x, int y, i64d ret)
{
    if( x == N || y == M) {
        ans = max(ans, ret);
        return ;
    }

    if( A[x] == B[y] ) {
        if( a[x] == b[y] )
            dfs(x + 1, y + 1, a[x] + ret);
        else if( a[x] < b[y] ) {
            b[y] -= a[x];
            dfs(x + 1, y, a[x] + ret);
            b[y] += a[x];
        } else {
            a[x] -= b[y];
            dfs(x, y + 1, b[y] + ret);
            a[x] += b[y];
        }
    } else
        dfs(x, y + 1, ret);

    dfs(x + 1, y, ret);
}

void foo(i64d x[], i64d X[], int &nx)
{
    if( nx == 1 )
        return ;

    if( nx == 2 )
        if( X[0] != X[1] )
            return ;

    if( nx == 2 ) {
        x[0] += x[1];
        nx = 1;
        return ;
    }

    if(X[0] == X[1] && X[1] == X[2]) {
        nx = 1;
        x[0] += x[1]; x[0] += x[2];
        return ;
    }

    if( X[0] == X[1] ) {
        x[0] += x[1];
        x[1] = x[2]; X[1] = X[2];
        nx = 2;
        return ;
    }

    if( X[1] == X[2] ) {
        x[1] += x[2];
        nx = 2;
        return ;
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int idx = 0, nt; cin >> nt;
    while( (nt --) > 0 ) {
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            cin >> a[i] >> A[i];
        for(int i = 0; i < M; i++)
            cin >> b[i] >> B[i];

        ans = 0LL;
        dfs(0, 0, 0);

        cout << "Case #" << ++idx << ": " << ans << endl;
    }
    return 0;
}


