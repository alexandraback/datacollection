#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[1000];
int flag[1000];

int calc()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second >> a[i].first;
        flag[i] = 2;
    }
    sort(&a[0], &a[n]);

    int t = 0, s = 0;
    for (int i = 0; i < n; ++i)
        if (s >= a[i].first)
        {
            s += flag[i];
            t += 1;
            //cerr << "take " << a[i].second << ' ' << a[i].first << " 2star" << endl;
        }
        else
        {
            while (s < a[i].first)
            {
                bool found = false;
                for (int j = n - 1; j >= i; --j)
                {
                    if (s >= a[j].second && flag[j] == 2)
                    {
                        t += 1;
                        s += 1;
                        flag[j] = 1;
                        found = true;
                        //cerr << "take " << a[j].second << ' ' << a[j].first << " 1star" << endl;
                        break;
                    }
                }
                if (!found) return 0;
            }
            s += flag[i];
            t += 1;
            //cerr << "take " << a[i].second << ' ' << a[i].first << " 2-1star" << endl;
        }
    return t;
}


int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int ans = calc();
        if (ans == 0)
            printf("Case #%d: Too Bad\n", i);
        else
            printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}

