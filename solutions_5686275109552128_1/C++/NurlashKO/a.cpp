//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base LL(1e9 + 7)
#define fname ""
#define sz 3010
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define mp make_pair

const double PI  = acos(-1.0);

int a[sz], test, n, ans, cur;
priority_queue <int> q;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        cout << "Case #" << t << ": ";
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ans = 1000;
        cur = 0;
        for (int i = 1; i <= 1000; i++)
        {
            cur = 0;
            for (int j = 1; j <= n; j++)
                cur += a[j] / i - (a[j] % i == 0);
            ans = min(ans, cur + i);
        }
        cout << ans << "\n";
    }
}
