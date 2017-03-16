#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Triple{
    int a, b, c;
    Triple() : a(0), b(0), c(0){}
    Triple(int _a, int _b, int _c) : a(_a), b(_b), c(_c){}

    bool operator<(const Triple & other)const
    {
        return hashCode() < other.hashCode();
    }

    int hashCode()const
    {
        return a * 100 + b * 10 + c;
    }

    void print()const
    {
        printf("%d %d %d\n", a, b, c);
    }
};

int j, p, s, k;
map<Triple, int> mp;
vector<Triple> ans;

void tryAdd(int a, int b, int c)
{
    Triple t1 = Triple(a, b, 0);
    Triple t2 = Triple(a, 0, c);
    Triple t3 = Triple(0, b, c);
    if (mp[t1] < k && mp[t2] < k && mp[t3] < k)
    {
        ans.push_back(Triple(a, b, c));
        mp[t1]++;
        mp[t2]++;
        mp[t3]++;
    }
}

void solve()
{
    mp.clear();
    ans.clear();
    for (int a = 1; a <= j; a++)
    {
        for (int b = 1; b <= p; b++)
        {
            for (int c = 1; c <= s; c++)
            {
                tryAdd(a, b, c);
            }
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i].print();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q;
    scanf("%d", &q);
    for (int t = 1; t <= q; ++t)
    {
        scanf("%d%d%d%d", &j, &p, &s, &k);
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}