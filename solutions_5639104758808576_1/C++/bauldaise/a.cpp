#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main()
{
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);

    ifstream f("ain.in");
    ofstream g("aout.out");

    int t; f >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n; string s;
        f >> n;
        f >> s;
        int cnt = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (cnt < i)
            {
                res += i - cnt;
                cnt = i;
            }
            cnt += (int) (s[i] - '0');
        }
        g << "Case #" << tt << ": " << res << endl;
    }
    f.close(); g.close();
    return 0;
}
