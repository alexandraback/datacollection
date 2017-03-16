#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#define msg(var) cerr << #var << " = " << var << endl
using namespace std;

int r, n, m, k, a[20];
vector<int> numbers;

void generate()
{
    for (int i = 1000; i <= 9999; i++)
    {
        bool flag = false;
        int temp = i;
        while (temp)
        {
            int dig = temp % 10;
            if (dig == 1 || dig > m || dig == 0) flag = true;
            temp /= 10;
        }
        if (!flag) numbers.push_back(i);
    }
}

double check(int n)
{
    vector<int> digs;
    while (n > 0)
    {
        digs.push_back(n % 10);
        n /= 10;
    }
    bool mark[20];
    memset(mark, 0, sizeof(mark));
    double prob = 0;

    for (int i = 0; i < k; i++)
        if (a[i] == 1)  mark[i] = true;

    for (int i = 0; i < k; i++)
    {
        if (mark[i]) continue;
        for (int j = 0; j < digs.size(); j++)
            if (digs[j] == a[i])
            {
                mark[i] = true;
                prob += 0.5;
                break;
            }
    }

    for (int i = 0; i < k; i++)
    {
        if (mark[i]) continue;
        for (int j = 0; j < digs.size(); j++)
            for (int k = j + 1; k < digs.size(); k++)
                if (digs[j] * digs[k] == a[i])
                {
                    mark[i] = true;
                    prob += 0.5 * 0.5;
                    break;
                }
    }

    for (int i = 0; i < k; i++)
    {
        if (mark[i]) continue;
        for (int j = 0; j < digs.size(); j++)
            for (int k = j + 1; k < digs.size(); k++)
                for (int z = k + 1; z < digs.size(); z++)
                    if (digs[j] * digs[k] * digs[z] == a[i])
                    {
                        mark[i] = true;
                        prob += 0.5 * 0.5 * 0.5;
                        break;
                    }
    }

    for (int i = 0; i < k; i++) if (!mark[i]) return 0;
    return prob;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    cin >> r;
    cout << "Case #1:\n";
    cin >> r >> n >> m >> k;
    generate();
    while (r--)
    {
        for (int i = 0; i < k; i++)
            cin >> a[i];

        int ans = numbers[0];
        double ansProb = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            //msg(numbers[i]);
            double prob = check(numbers[i]);
            if (prob > ansProb)
            {
                ansProb = prob;
                ans = numbers[i];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
