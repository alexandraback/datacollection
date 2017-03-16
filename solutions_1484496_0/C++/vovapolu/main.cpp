#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int t;
vector <int> a;
vector <int> ans1, ans2;

bool Go(int sum1, int sum2, int num)
{
    if (sum1 == sum2 && sum1 != 0)
        return true;
    if (num >= a.size())
        return false;
    ans1.push_back(a[num]);
    sum1 += a[num];
    if (Go(sum1, sum2, num + 1)) return true;
    ans1.pop_back();
    sum1 -= a[num];

    ans2.push_back(a[num]);
    sum2 += a[num];
    if (Go(sum1, sum2, num + 1)) return true;
    ans2.pop_back();
    sum2 -= a[num];

    if (Go(sum1, sum2, num + 1)) return true;

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ":" << endl;
        int n;
        cin >> n;
        a.resize(n);
        ans1.clear();
        ans2.clear();
        for (int j = 0; j < n; j++)
            cin >> a[j];
        if (Go(0, 0, 0))
        {
            int sum1 = 0, sum2 = 0;
            for (int k = 0; k < ans1.size(); k++)
            {
                cout << ans1[k] << ' ';
                sum1 += ans1[k];
            }
            //cout << sum1;
            cout << endl;

            for (int k = 0; k < ans2.size(); k++)
            {
                cout << ans2[k] << ' ';
                sum2 += ans2[k];
            }
            //cout << sum2;
            cout << endl;
        }
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
