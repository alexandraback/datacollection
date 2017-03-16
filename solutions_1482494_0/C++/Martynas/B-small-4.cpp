#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool works(vector<pair<int, int> >& v)
{
    int stars = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (stars < v[i].first) return false;
        stars += v[i].second;
    }
    return true;
}

void solve()
{
    int N;
    scanf("%d", &N);
    int a[N], b[N];
    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    int best = -1;
    for (int i = 0; i < (1 << N); ++i)
    {
        vector<pair<int, int> > v;
        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
            {
                v.push_back(make_pair(a[j], 1));
                v.push_back(make_pair(b[j], 1));
            }
            else
            {
                v.push_back(make_pair(b[j], 2));
            }
        }
        sort(v.begin(), v.end());
        if (works(v))
        {
            if (best == -1 || best > v.size()) best = v.size();
        }
    }
    if (best == -1)
    {
        printf("Too Bad\n");
    }
    else
    {
        printf("%d\n", best);
    }
}

int main() {
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
}
