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

void dummy()
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

struct word
{
    int first, last, msk;
};
const int mod = 1000000007;

int dsu[maxn], after[maxn];

inline int get(int v)
{
    return dsu[v] == v ? v : dsu[v] = get(dsu[v]);
}

inline void unite(int u, int v)
{
    u = get(u), v = get(v);
    if (u == v) return;
    dsu[v] = u;
}

void solve()
{
    cin >> n;
    vector<word> wds;
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
        wds.pb(word());
        wds.back().first = words[i][0] - 'a';
        wds.back().last = words[i].back() - 'a';
        wds.back().msk = 0;
        for (size_t j = 0; j < words[i].size(); ++j)
            wds.back().msk |= 1 << (words[i][j]- 'a');
    }
    for (int i = 0; i < n; ++i) dsu[i] = i;
    for (int i = 0; i < n; ++i)
        if (isbad(words[i]))
        {
            printf("0\n");
            return;
        }
    ll ans = 1;
    memset(after, -1, sizeof(after));
    for (int c = 0; c < 26; ++c)
    {
        int cnt = 0, fst = -1, lst = -1, mid = -1;
        for (size_t i = 0; i < wds.size(); ++i)
        {
            if ((wds[i].msk & (1 << c)) == 0) continue;
            if (wds[i].first == c && wds[i].last == c)
                cnt++;
            else if (wds[i].first == c)
            {
                if (fst != -1)
                {
                    printf("0\n");
                    return ;
                }
                fst = i;
            }
            else if (wds[i].last == c)
            {
                if (lst != -1)
                {
                    printf("0\n");
                    return ;
                }
                lst = i;
            }
            else
            {
                if (mid != -1)
                {
                    printf("0\n");
                    return ;
                }
                mid = i;
            }
        }
//         cerr << mid << " " << lst << " " << fst << endl;
        if (mid != -1 && (lst != -1 || fst != -1 || cnt != 0))
        {
            printf("0\n");
            return ;
        }
        if (lst != -1 || fst != -1 || mid != -1 || cnt != 0)
        {
            int x = -1;
            for (size_t i = 0; i < wds.size(); ++i)
            {
                if (wds[i].msk & (1 << c))
                {
                    if (x == -1) x = i;
                    else unite(i, x);
                }
            }
        }
        if (fst != -1 && lst != -1)
        {
            if (after[fst] == lst || after[lst] != -1)
            {
                printf("0\n");
                return ;
            }
            after[lst] = fst;
        }
//         if (cnt) cerr << cnt << endl;
        for (int i = 1; i <= cnt; ++i)
            ans = (ans * i) % mod;
    }
    set<int> s;
    for (int i = 0; i < n; ++i) s.insert(get(i));
    for (size_t i = 1; i <= s.size(); ++i)
        ans = (ans * i) % mod;
    printf("%lld\n", ans);
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
