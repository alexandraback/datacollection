#include <iostream>

using namespace std;

void solve(void)
{
    int n, s, p;
    cin >> n >> s >> p;
    int limit1 = (max(p - 1, 0) << 1) + p;
    int limit2 = (max(p - 2, 0) << 1) + p;
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= limit1)
        {
            num1++;
        }
        else if (x >= limit2)
        {
            num2++;
        }
    }
    cout << num1 + min(s, num2) << endl;
}

int main(void)
{
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; testCase++)
    {
        cout << "Case #" << testCase << ": ";
        solve();
    }
    return 0;
}

