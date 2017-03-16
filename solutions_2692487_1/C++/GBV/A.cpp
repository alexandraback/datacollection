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

const int MAXN = 128;
int N, A;
int M[MAXN];

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j;
    ll mote;
    int ans, cr;
    cin >> A >> N;
    ans = N;
    for(i = 0; i < N; ++i) cin >> M[i];
    sort(M, M + N);
    for(j = N - 1; j >= 0; --j)
    {
        cr = N - 1 - j;
        mote = A;
        bool possible = true;
        for(i = 0; i <= j; ++i)
        {
            if(mote <= M[i] && mote == 1)
            {
                possible = false;
                break;
            }
            while(mote <= M[i])
            {
                mote += mote - 1;
                ++cr;
            }
            mote += (ll) M[i];
        }
        if(possible) ans = min(ans, cr);
    }
    cout << ans << '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
