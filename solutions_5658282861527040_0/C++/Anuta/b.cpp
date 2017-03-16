#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        int a, b, k;
        ll res = 0;
        scanf("%d %d %d", &a, &b, &k);
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
            {
                if ( (i & j) < k) ++ res;
            }
        printf("Case #%d: %I64d\n", t + 1, res);
    }
    return 0;
}