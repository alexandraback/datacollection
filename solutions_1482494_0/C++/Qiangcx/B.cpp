#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

#define maxn 1010
#define Fup(i, s, t) for (int i = s; i <= t; i ++)
#define Fdn(i, s, t) for (int i = s; i >= t; i --)
#define Path(i, s) for (int i = s; i; i = d[i].next)

using namespace std;

struct node {int a, b, v;}x[maxn];
int n, t;

bool compare(const node &x, const node &y)
{
    if (x.b != y.b)
        return x.b < y.b;
    return x.a > y.a;
}

void init()
{
    cin >> n;
    Fup(i, 1, n){
        cin >> x[i].a >> x[i].b;
        x[i].v = 2;
    }
}

void solve()
{
    sort(x + 1, x + n + 1, compare);
    int ans = n, sum = 0;
    bool flag = true;
    Fup(i, 1, n){
        if (x[i].b <= sum){
            sum += x[i].v;
            continue;
        }
        int t = sum + 1;
        Fup(j, t, x[i].b)
            Fdn(k, n, i)
                if (x[k].v == 2 && x[k].a <= sum){
                    ans ++;
                    sum ++;
                    x[k].v = 1;
                    break;
                }
        if (x[i].b <= sum)
            sum += x[i].v;
        else{
            flag = false;
            break;
        }
    }
    if (flag)
        cout << ans << endl;
    else
        cout << "Too Bad" << endl;
}

int main()
{
//    freopen("temp.in", "r", stdin);
//    freopen("temp.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    Fup(i, 1, t){
        cout << "Case #" << i << ": ";
        init();
        solve();
    }
    return 0;
}
