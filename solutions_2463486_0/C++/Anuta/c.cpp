#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;

ll p[10000007];

bool pal(ll x)
{
    stringstream ss;
    ss << x;
    string s = ss.str();
    //printf ("!!! %s\n", s.c_str());
    bool b = true;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        if (s[i] != s[j])
        {
            b = false;
            break;
        }        
    return b;
}

int main()
{
    for (ll i = 1; i <= 1000; ++i)
    {
        p[i] = p[i-1];
        if (pal(i) &&  pal(i*i))
            ++p[i];
    }
    //for (int i = 0; i < 12; ++i)
    //    printf("%d %I64d\n", i, p[i]);
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        ll a, b;
        scanf("%I64d %I64d", &a, &b);
        ll a1 = sqrt((double)a);
        if (a1*a1 < a) ++a1;
        ll b1 = sqrt((double)b);
        ll ans = p[b1] - p[a1-1];
        
        printf("Case #%d: %I64d\n", t + 1, ans);
    }
    return 0;
}
