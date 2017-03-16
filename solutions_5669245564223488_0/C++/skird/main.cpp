#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef double lf;

const int maxn = 100;
const int alph = 26;

int n, last[maxn], first[maxn], perm[maxn], msk[maxn];
string words[maxn];

bool isbad(const string &w)
{
    int last[26];
    memset(last, -1, sizeof(last));
    for (int i = 0; i < (int) w.length(); ++i)
    {
        int x = w[i] - 'a';
        if (last[x] != -1 && last[x] + 1 < i)
            return true;
        last[x] = i;
    }
    return false;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
        first[i] = words[i][0] - 'a';
//         cerr << words[i] << endl;
        last[i] = words[i].back() - 'a';
        msk[i] = 0;
        for (size_t j = 0; j < words[i].size(); ++j)
            msk[i] |= 1 << (words[i][j] - 'a');
    }
    for (int i = 0; i < n; ++i)
        if (isbad(words[i]))
        {
            printf("0\n");
            return;
        }

//     cerr << msk[0] << " " << msk[1] << " " << msk[2] << " " << msk[3] << endl;
    int ans = 0;
    for (int i = 0; i < n; ++i) perm[i] = i;
    do
    {
        int used = 0, lst = 26;
        bool fail = false;
        for (int i = 0; i < n; ++i)
        {
            if (msk[perm[i]] & used)
            {
                if (__builtin_popcount(msk[perm[i]] & used) > 1 || first[perm[i]] != lst)
                    fail = true;

            }
            lst = last[perm[i]];
            used |= msk[perm[i]];
        }
        if (!fail)
        {
//             for (int i = 0; i < n; ++i) cerr << perm[i] << " ";
//             cerr << endl;
            ans++;
        }
    }
    while (next_permutation(perm, perm + n));
    printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }
	return 0;
}
