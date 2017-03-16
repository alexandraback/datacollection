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
int n, x, y;
int s, b;

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B_tmp_py.py", "w", stdout);

    cin >> T;

    rep(test, T)
    {
        scanf("%d %d %d", &n, &x, &y);

        s = 1;
        b = 1;
        while (1)
        {
            if (n >= b + 2 * s + 3)
            {
                b = b + 2 * s + 3;
                s += 2;
            }
            else
                break;
        }
        n -= b;

        if (abs(x) + y < s)
        {
            printf("res = 1.0\n", n, y);
            printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
            continue;
        }

        if (abs(x) + y > s + 2)
        {
            printf("res = 0.0\n", n, y);
            printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
            continue;
        }

        if (x == 0 || n == 0)
        {
            /*if (n == 0)
            {
                printf("res = 1.0\n", n, y);
                printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
            }
            else*/
            {
                printf("res = 0.0\n", n, y);
                printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
            }
            continue;
        }

        if (n - (s + 1) > y)
        {
            printf("res = 1.0\n", n, y);
            printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
            continue;
        }

        if (n < y + 1)
        {
            printf("res = 0.0\n", n, y);
            printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
            continue;
        }

        int mn = max(y + 1, n - (s + 1));
        printf("res = (C(%d, %d)", n, mn);
        FOR(i, mn + 1, min(n, s + 1))
            printf(" + C(%d, %d)", n, i);

        printf(") * 1.0 / (");

        mn = max(0, n - (s + 1));
        printf("C(%d, %d)", n, mn);
        FOR(i, mn + 1, min(n, s + 1))
            printf(" + C(%d, %d)", n, i);

        printf(")\n");


        printf("f.write('Case #%d: ' + str(res) + '\\n')\n\n", test + 1);
    }


    return 0;
}
