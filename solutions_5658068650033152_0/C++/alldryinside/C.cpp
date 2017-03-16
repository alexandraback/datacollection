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

void solve(int N, int M, int K)
{
    int a, b;
    if(N == 1 || M == 1)
    {
        cout << K << '\n';
        return;
    }
    if(K > M * N - 4)
    {
        cout << min(2 * (M + N - 4) + K - (M * N - 4), K) << '\n';
        return;
    }
    int i, rem, best = K, cr, diff;
    for(a = 1; a < N - 1; ++a)
    {
        for(b = 1; b < M - 1 && 2 * (a + b) <= K; ++b)
        {
            rem = K - 2 * (a + b);
            cr = 2 * (a + b);
            if(rem > a * b) continue;
            best = min(best, cr);
            for(i = 1; i <= min(a, b); ++i)
            {
                diff = (i * (i + 1)) / 2;
                if(rem <= a * b - diff) best = min(best, cr - i);
                else break;
            }
        }
    }
    cout << best << '\n';
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int N, M, K;
    cin >> N >> M >> K;
    solve(N, M, K);
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    /*for(i = 1; i < 100; ++i)
    {
        cout << i << ' ';
        solve(20, 20, i);
    }*/
    return 0;
}
