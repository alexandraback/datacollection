#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int l, n;
string s;
vector <int> c;

int main()
{
    bool consonant;
    int a, cnt, i, j, k, res, t, temp, temp_max;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> s; cin >> n; l = s.length();
        res = 0;
        for (i = 0; i <= l - n; i++)
        {
            for (j = i + n; j <= l; j++)
            {
                temp = 0; temp_max = 0;
                for (k = i; k < j; k++)
                {
                    consonant = true;
                    if ((s[k] == 'a') || (s[k] == 'e') || (s[k] == 'i') || (s[k] == 'o') || (s[k] == 'u')) consonant = false;
                    if (consonant) temp++; if (!consonant) temp = 0;
                    if (temp > temp_max) temp_max = temp;
                    if (temp == n) { res++; break; }
                }
            }
        }
        cout << "Case #" << cnt << ": " << res << endl;
    }
    return 0;
}
