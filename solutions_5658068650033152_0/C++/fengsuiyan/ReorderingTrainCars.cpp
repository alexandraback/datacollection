#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 100;
int dp[N];
int dp2[N];

int main()
{
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    int n;
    int m;
    int k;
    cin >> t;
    for (int i = 3; i < N; ++i)
    {
        dp[i] = i*i - 4;
    }
    for (int i = 3; i < N; ++i)
    {
        dp2[i] = i*(i+1) - 4;
    }
    for (int i = 1; i <= t; ++i)
    {
        cin >> n >> m >> k;
        if (k == n*m && n >= 3 && m >= 3)
        {
            int sum;
            sum = (n+m-2)*2;
            cout << "Case #" << i << ": " << sum << endl;
        }
        else if (k == 1)
        {
            cout << "Case #" << i << ": " << 1 << endl;
        }
        else
        {
            if (n > m)
            {
                int t = m;
                m = n;
                n = t;
            }               //m >= n
            if (n >= 3)
            {
                if (n*n - 4 >= k)
                {
                    int index = -1;
                    for (int j = 3; j < N; ++j)
                    {
                        if (k <= dp[j])
                        {
                            index = j;
                            break;
                        }
                    }
                    int index2 = -1;
                    for (int j = 3; j < N; ++j)
                    {
                        if (k <= dp2[j])
                        {
                            index2 = j;
                            break;
                        }
                    }
                    assert(index != -1);
                    assert(index2 != -1);
                    int sum;
                    if (index2 < index)
                    {
                        sum = (index2-2)*2 + (index2-1)*2;
                    }
                    else
                    {
                        sum = (index-2)*4;
                    }
                    cout << "Case #" << i << ": " << sum << endl;
                }
                else
                {
                    if ((k + 4) % n == 0)
                    {
                        int t = (k+4) / n;
                        int sum;
                        sum = (t-2)*2 + (n-2)*2;
                        cout << "Case #" << i << ": " << sum << endl;
                    }
                    else
                    {
                        int t = (k+4) / n + 1;
                        int sum;
                        sum = (t-2)*2 + (n-2)*2;
                        cout << "Case #" << i << ": " << sum << endl;
                    }
                }
            }
            else if (n == 1)
            {
                if (k != 1)
                    cout << "Case #" << i << ": " << 2 << endl;
                else
                    cout << "Case #" << i << ": " << 1 << endl;
            }
            else
            {
                if (k == 2)
                {
                    cout << "Case #" << i << ": " << 2 << endl;
                }
                else if (k % 2 == 0)
                {
                    cout << "Case #" << i << ": " << k-2 << endl;
                }
                else if (k == 1)
                {
                    cout << "Case #" << i << ": " << 1 << endl;
                }
                else
                {
                    cout << "Case #" << i << ": " << k-1 << endl;
                }
            }
        }
    }
    return 0;
}

