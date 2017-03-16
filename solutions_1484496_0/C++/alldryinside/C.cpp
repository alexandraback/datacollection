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

const int maxn = 512;
int N, A[maxn];
vector<int> F[(1<<21) + 7];

void solve_case(int case_id)
{
    printf("Case #%d:\n", case_id);
    int i, j, k, mask;
    bool found = false;
    vector<int> cr;
    cin >> N;
    for(i = 0; i < N; ++i) cin >> A[i];
    for(mask = 0; mask < (1<<N); ++mask)
    {
        k = 0;
        cr.clear();
        for(j = 0; j < N; ++j)
        {
            if(mask & (1<<j))
            {
                k += A[j];
                cr.pb(A[j]);
            }
        }
        if(!F[k].empty())
        {
            found = true;
            for(i = 0; i < F[k].size() - 1; ++i) printf("%d ", F[k][i]);
            printf("%d\n", F[k][F[k].size() - 1]);
            for(i = 0; i < cr.size() - 1; ++i) printf("%d ", cr[i]);
            printf("%d\n", cr[cr.size() - 1]);
            break;
        }
        F[k] = cr;
    }
    if(!found) printf("Impossible\n");
    for(i = 0; i < (1<<21) + 7; ++i) F[i].clear();
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
