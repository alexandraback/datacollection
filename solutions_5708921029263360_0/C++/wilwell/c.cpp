#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> ans;
int res = -1;

struct costum
{
    int a, b, c;
};



void gen(int i, vector<costum> &arr, vector<bool> &use, vector<vector<vector<int>>> &num, int K, int cur)
{
    if (i == arr.size())
    {
        if (cur > res)
        {
            res = cur;
            ans = use;
        }
        return;
    }
    if (num[0][arr[i].a][arr[i].b] + 1 <= K && num[1][arr[i].a][arr[i].c] + 1 <= K && num[2][arr[i].b][arr[i].c] + 1 <= K)
    {
        num[0][arr[i].a][arr[i].b]++;
        num[1][arr[i].a][arr[i].c]++;
        num[2][arr[i].b][arr[i].c]++;
        use[i] = true;
        gen(i + 1, arr, use, num, K, cur + 1);
        num[0][arr[i].a][arr[i].b]--;
        num[1][arr[i].a][arr[i].c]--;
        num[2][arr[i].b][arr[i].c]--;
    }
    if (cur + int(arr.size()) - i - 1 > res)
    {
        use[i] = false;
        gen(i + 1, arr, use, num, K, cur);
    }
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
    {
        int J, P, S, K;
        cin >> J >> P >> S >> K;
        res = -1;
        vector<costum> arr;
        for (int a = 0; a < J; ++a)
        {
            for (int b = 0; b < P; ++b)
            {
                for (int c = 0; c < S; ++c)
                {
                    costum x;
                    x.a = a;
                    x.b = b;
                    x.c = c;
                    arr.push_back(x);
                }
            }
        }
        ans.clear();
        vector<bool> use(arr.size(), false);
        vector<vector<vector<int>>> num(3, vector<vector<int>>(10, vector<int>(10, 0)));
        gen(0, arr, use, num, K, 0);
        printf("Case #%d: %d\n", test, res);
        for (int i = 0; i < ans.size(); ++i)
        {
            if (ans[i])
            {
                printf("%d %d %d\n", arr[i].a + 1, arr[i].b + 1, arr[i].c + 1);
            }
        }
    }
}
