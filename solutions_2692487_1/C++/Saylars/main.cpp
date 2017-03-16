#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int a, n;
        cin >> a >> n;
        vector <int> b;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            b.push_back(temp);
        }
        sort(b.begin(), b.end());
        int c[n + 1];
        int ans;
        if (a != 1)
        {
            int tempa = a;
            for (int i = 0; i < n; i++)
            {
                if (tempa > b[i])
                {
                    tempa += b[i];
                    c[i] = 0;
                }
                else
                {
                    int w =0;
                    while (tempa <= b[i])
                    {
                        w++;
                        tempa = tempa + tempa - 1;
                    }
                    tempa += b[i];
                    c[i] = w;
                }
            }
            ans = n;
            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                tmp += c[i];
                if (tmp + n - i - 1< ans)
                    ans = tmp + n - i - 1;
            }
        }
        else
        {
            ans = n;
        }
        cout << "Case #"<<q + 1 << ": " << ans << endl;
    }
    return 0;
}
