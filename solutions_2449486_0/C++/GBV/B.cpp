#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

int A[128][128], N, M;
int r[128], c[128];

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, k;
    cin >> N >> M;
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j) cin >> A[i][j];
    for(i = 0; i < 128; ++i)
    {
        r[i] = 0;
        c[i] = 0;
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            r[i] = max(r[i], A[i][j]);
            c[j] = max(c[j], A[i][j]);
        }
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            if(A[i][j] < r[i] && A[i][j] < c[j])
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
