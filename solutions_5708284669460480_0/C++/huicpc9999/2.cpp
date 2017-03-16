#include <iostream>
#include <cstdio>
using namespace std;
int k, l, s;
char keyboard[200], tar[200];
double ans, maxB;

double check(string str)
{
    double res = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        int j = 0;
        while (i+j < str.length() && j < l && tar[j] == str[i+j]) ++j;
        if (j == l) res += 1.0;
    }
    maxB = max(maxB, res);
    return res;
}
void dfs(int idx, string str, double p)
{
    //printf("idx = %d, s = %d\n", idx, s);
    //cout << "i = " << i << "str = " << str << "p = " << p << endl;
    if (idx == s)
    {
        ans += check(str) * p;
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        dfs(idx+1, str+keyboard[i], p*(1.0/k));
    }
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s %s", keyboard, tar);
        ans = 0;
        maxB = 0;
        dfs(0, "", 1);
        printf("Case #%d: %.6lf\n", cas, maxB - ans);
    }
    return 0;
}
