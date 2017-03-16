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
#define sz 310
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define mp make_pair

const double PI  = acos(-1.0);

int t;
string s;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cout << "Case #" << T << ": ";

        int buf;
        cin >> buf;
        cin >> s;
        int cur = 0, ans = 0;
        for (int i = 0; i < len(s); i++)
        {
            ans += max(0, i - (cur + ans));
            cur += s[i] - '0';
        }

        cout << ans << "\n";

    }
}
