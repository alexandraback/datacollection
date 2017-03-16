#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

struct level
{
    int s1;
    int s2;
}lv[1001];

bool used[1001][2];
int n;
int mMin, stars, times;

void dfs(int cnt)
{
    if (times >= mMin)
        return;
    if (cnt == n)
    {
        mMin = times;
        return;
    }
    int i;
    bool check = true;
    for (i = 0; i < n; i++)
    {
        if (!used[i][1] && stars >= lv[i].s2)
        {
            check = false;
            used[i][1] = true;
            stars += 2;
            times++;
            dfs(cnt + 1);
            times--;
            stars -= 2;
            used[i][1] = false;
        }
    }
    if (!check)
        return;
    for (i = 0; i < n; i++)
    {
        if (!used[i][0] && stars >= lv[i].s1)
        {
            used[i][0] = true;
            stars++;
            times++;
            dfs(cnt);
            times--;
            stars--;
            used[i][0] = false;
        }
    }
}

int main()
{
    FILE *out = fopen("out.out", "w");
    int t;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cin >> n;
        int i;
        mMin = 999999999;
        stars = times = 0;
        memset(used, false, sizeof(used));
        for (i = 0; i < n; i++)
        {
            cin >> lv[i].s1 >> lv[i].s2;
        }
        dfs(0);
        if (mMin == 999999999)
            fprintf(out, "Case #%d: Too Bad\n", k);
        else
            fprintf(out, "Case #%d: %d\n", k, mMin);
        k++;
    }
    return 0;
}
