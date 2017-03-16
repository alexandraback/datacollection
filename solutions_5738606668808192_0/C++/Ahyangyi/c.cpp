// This way stupid trick creates F(n - 3) solutions.
// Therefore, the number of solutions it can produce is
//             2 for n = 6;
//           233 for n = 16;
//        514229 for n = 32.
#include <iostream>

using namespace std;

int search(int n, int j, string d, int s)
{
    if (s == n - 1)
    {
        if (d[d.size() - 1] == '1')
        {
            d = "0" + d;
            for (int i = 0; i < d.size();)
                if (i + 1 < d.size() && d[i + 1] == '1')
                {
                    cout << "11";
                    i += 2;
                }
                else
                {
                    cout << "0";
                    i += 1;
                }
            for (int i = 2; i <= 10; i ++)
                cout << " " << i + 1;
            cout << endl;

            return 1;
        }
        else
        {
            return 0;
        }
    }

    int ans = search(n, j, d + "0", s + 1);
    if (d[d.size() - 1] == '0' && j > ans)
    {
        ans += search(n, j - ans, d + "1", s + 1);
    }
    return ans;
}

void solve(int n, int j)
{
    search(n, j, "1", 1);
}

int main()
{
    int ct, t;

    cin >> t;
    for (ct = 1; ct <= t; ct ++)
    {
        int n, j;

        cin >> n >> j;
        cout << "Case #" << ct << ": " << endl;
        solve(n, j);
    }

    return 0;
}
