#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int run = 0; run < T; ++run)
    {
        int sum = 0;
        int ans = 0;

        int Smax;
        cin >> Smax;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); ++i)
        {
            int si = s[i] - '0';

            if (si > 0 && sum < i) {
                ans += (i - sum);
                sum = i;
            }

            sum += si;
        }

        cout << "Case #" << run + 1 << ": " << ans << endl;
    }
    return 0;
}
