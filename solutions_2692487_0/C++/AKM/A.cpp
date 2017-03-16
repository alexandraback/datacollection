#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int main()
{
    int tt;
    cin >> tt;
    for (int tc = 1; tc <= tt; tc++)
    {
        int a, n;
        cin >> a >> n;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        sort(v.begin(), v.end());
        int i = 0, opers = 0, ans = n;
        while (i < v.size() && v[i] < a)
        {
            a += v[i];
            i++;
        }
        while (i < v.size())
        {
            ans = min(ans, opers + (int)v.size() - i);
            if (a == 1)
                break;
            else
            {
                a += a - 1;
                opers++;
            }
            while (i < v.size() && v[i] < a)
            {
                a += v[i];
                i++;
            }
        }
        ans = min(ans, opers + (int)v.size() - i);
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
