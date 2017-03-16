#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>

using namespace std;

typedef unordered_map<int64_t, int> m;
typedef unordered_set<int64_t> x;

static const int maxn = 500;

int64_t s[maxn];
m f;

void dump(m::iterator iter, x &a)
{
    int64_t sum = iter->first;
    while (sum > 0)
    {
        a.insert(s[iter->second]);
        sum -= s[iter->second];
        iter = f.find(sum);
    }
}

void show(const x &a, const x &b)
{
    bool first = true;
    for (x::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter)
    {
        if (b.find(*iter) != b.end())   continue;
        printf(first ? "%lld" : " %lld", *iter);
        first = false;
    }
    printf("\n");
}

void check(const x &a, const x &b)
{
    return;
    int64_t s = 0;
    for (x::const_iterator iter = a.cbegin(); iter != a.cend(); ++iter)
        s += *iter;
    for (x::const_iterator iter = b.cbegin(); iter != b.cend(); ++iter)
        s -= *iter;
    printf("s = %lld\n", s);
}

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &s[i]);
    sort(&s[0], &s[n]);

    f.clear();
    f.insert(make_pair(s[0], 0));

    for (int i = 1; i < n; ++i)
    {
        m::iterator iter = f.find(s[i]);
        if (iter != f.end())
        {
            x a, b;
            dump(iter, a);
            show(a, b);
            printf("%lld\n", s[i]);
            return;
        }
        vector<int64_t> ts;
        for (m::iterator it = f.begin(); it != f.end(); ++it)
        {
            int64_t t = it->first + s[i];
            m::iterator iter = f.find(t);
            if (iter != f.end())
            {
                x a, b;
                dump(iter, a);

                dump(it, b);
                b.insert(s[i]);

                show(a, b);
                show(b, a);

                check(a, b);
                return;
            }
            ts.push_back(t);
        }
        for (vector<int64_t>::iterator iter = ts.begin(); iter != ts.end(); ++iter)
            f.insert(make_pair(*iter, i));
        f.insert(make_pair(s[i], i));
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}

