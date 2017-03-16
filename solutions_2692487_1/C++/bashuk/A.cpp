#define _CRT_SECURE_NO_DEPRECATE

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <ctime>
using namespace std;

#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef pair<int, int> pii;


int T;

int A, N, t;
int res, cur;
vint a;


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-bg-output.txt", "w", stdout);

    cin >> T;
    rep(test, T)
    {
        a.clear();

        scanf("%d %d", &A, &N);
        rep(i, N)
        {
            scanf("%d", &t);
            a.pb(t);
        }

        res = sz(a);
        sort(all(a));
        cur = 0;

        if (A <= 1)
        {
            printf("Case #%d: %d\n", test + 1, res);
            continue;
        }

        rep(i, N)
        {
            while (A <= a[i])
            {
                A += A - 1;
                cur++;
            }
            A += a[i];

            res = min(res, cur + N - i - 1);
        }

        printf("Case #%d: %d\n", test + 1, res);
    }


    return 0;
}
