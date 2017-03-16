#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#define MAXN 15
using namespace std;
vector <char> star;
int num[MAXN << 1];
string a, b;
char temp[MAXN];
int k, l, s;
double ans;
void solve()
{
    double res = 1.0;
    for(int i = 0; i < s; i++)
    {
        res *= ((double)num[temp[i] - 'A'] / (double)k);
    }
    int nn = 0;
    for(int i = 0; i < s; i++)
    {
        int flag = 1;
        for(int j = 0; j < l; j++)
        {
            if(i + j >= s || temp[i + j] != b[j])
            {
                flag = 0;
                break;
            }
        }
        nn += flag;
    }
    ans += ((double)nn * res);
}
void dfs(int now)
{
    if(now >= s)
    {
        solve();
        return;
    }
    for(int i = 0; i < star.size(); i++)
    {
        temp[now] = star[i];
        dfs(now + 1);
    }
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("outB.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int numCase = 1; numCase <= t; numCase++)
    {
        cin >> k >> l >> s;
        cin >> a;
        cin >> b;
        star.clear();
        memset(temp, 0, sizeof(temp));
        memset(num, 0, sizeof(num));
        for(int i = 0; i < a.size(); i++)
        {
            if(num[a[i] - 'A'] == 0)
            {
                star.push_back(a[i]);
            }
            num[a[i] - 'A']++;
        }
        int nnn = 0;
        for(int i = 1; i < b.size(); i++)
        {
            if(string(b.begin() + i, b.end()) ==
               string(b.begin(), b.end() - i))
            {
                nnn = i;
                break;
            }
        }
        int ttt;
        if(nnn != 0)
            ttt = 1 + (s - l) / nnn;
        else
            ttt = s / l;
        ans = 0.0;
        dfs(0);
        if(ans != 0.0)
            ans = (double)ttt - ans;
        //printf("-------%d %d\n", ttt, nnn);
        printf("Case #%d: %.8f\n", numCase, ans);
    }
    return 0;
}
