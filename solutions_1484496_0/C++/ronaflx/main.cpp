#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define REP(i, l, n) for(int i = l;i < int(n);++i)
const int N = 500;
const int M = 2000001;
int val[N];
map<int, vector<int> > check;
bool find(int n, int x)
{
    vector<int> a;
    REP(i, 0, n) if(x & (1 << i)) a.push_back(val[i]);
    int sum = accumulate(a.begin(), a.end(), 0);
    auto iter = check.find(sum);
    if(iter == check.end())
    {
        check.insert(make_pair(sum, a));
        return false;
    }
    else
    {
        vector<int>& b = iter->second;
        REP(i, 0, b.size())
            printf("%d%c", b[i], i == b.size() - 1 ? '\n' : ' ');
        REP(i, 0, a.size())
            printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');
        return true;
    }
}
void doit(int n)
{
    for(int i = 1;i < (1 << n);i++)
    {
        if(find(n, i))
            return;
    }
    printf("Impossible\n");
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int t, n;
    scanf("%d", &t);
    REP(cas, 0, t)
    {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d", val + i);
        check.clear();
        printf("Case #%d:\n", cas + 1);
        doit(n);
    }
    return 0;
}
