#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

typedef long long int LongNumber;

const LongNumber MOD = 1000000007LL;

int main()
{
    int t;
    cin >> t;
    for (int qq = 1; qq <= t; ++qq)
    {
        int n;
        cin >> n;
        vector<string> ss(n);
        for (int i = 0; i < n; ++i)
            cin >> ss[i];

        LongNumber result = 1;

        vector<int> inside(256, 0);
        vector<int> first(256, 0);
        vector<int> last(256, 0);
        vector<int> firstlast(256, 0);
        vector<int> paths(256, -1);
        for (size_t k = 0; k < ss.size(); ++k)
        {
            const string& s = ss[k];
            char ch = s[0];

            if (ch == s.back())
            {
                ++firstlast[ch];

                for (size_t i = 1; result && i < s.length() - 1; ++i)
                    if (ch != s[i]) result = 0;
            }
            else
            {
                if (paths[ch] < 0) paths[ch] = k;

                ++first[ch];
                ++last[s.back()];

                for (size_t i = 0; i < s.length() - 1; ++i)
                    if (s[i] != s[i + 1]) ++inside[s[i]];
                --inside[ch]; // the cycle will always add one excessively
            }

            if (!result) break;
        }

        int factor = 0;
        for (char ch = 'a'; result && ch <= 'z'; ++ch)
        {
            //cerr << ch << ": " << first[ch] << ' ' << last[ch] << ' ' << firstlast[ch] << endl;
            if (first[ch] > 1 || last[ch] > 1 || inside[ch] > 1 ||
                    (first[ch] + last[ch] + firstlast[ch] > 0 && inside[ch] > 0))
            {
                result = 0;
                break;
            }

            vector<bool> visited(256, false);
            char t = ch;
            while (paths[t] >= 0 && !visited[t])
            {
                visited[t] = true;
                t = ss[paths[t]].back();
            }
            //cerr << ch << "->" << t << endl;
            if (paths[t] >= 0)
                result = 0;

            for (int i = 2; i <= firstlast[ch]; ++i)
                result = (result * i) % MOD;

            if (first[ch] + firstlast[ch] > 0 && !last[ch])
            {
                //cerr << ch << endl;;
                ++factor;
            }
        }

        for (int i = 2; i <= factor; ++i)
            result = (result * i) % MOD;

        cout << "Case #" << qq << ": " << result << endl;
    }
    return 0;
}
