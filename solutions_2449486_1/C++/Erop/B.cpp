#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.);

int T[110], R[110];
int A[110][110];

void solve()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
    {
        R[i] = 0;
        for (int j = 0; j < M; ++j)
        {
            T[j] = 0;
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            R[i] = max(R[i], A[i][j]);
            T[j] = max(T[j], A[i][j]);
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (R[i] > A[i][j] && T[j] > A[i][j])
            {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }
	return 0;
}