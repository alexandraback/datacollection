#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int l, n;
string s;
vector <int> c, c1, c2, c3;
vector <long long> cc1, cc2;

bool is_consonant(char c)
{
    if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) return false;
    return true;
}

int main()
{
    bool consonant;
    int a, cnt, i, j, k, l1, n1, t, temp, temp2;
    long long res;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> s; cin >> n; l = s.length();
        res = 0; c.resize(l); c1.resize(l - n + 1);
        for (i = 0; i < l; i++) c[i] = (is_consonant(s[i]) ? 1 : 0);
        for (i = 0; i <= l - n; i++) c1[i] = 0;
        c1[0] = n;
        for (i = n - 1; i >= 0; i--)
        {
            if (!c[i])
            {
                c1[0] = n - i - 1;
                break;
            }
        }
        for (i = 1; i <= l - n; i++)
        {
            if (c[n + i - 1]) c1[i] = c1[i - 1] + 1;
            else c1[i] = 0;
            if (c1[i] > n) c1[i] = n;
        }
        c2.resize(l - n + 1); c3.resize(l - n + 1);
        temp = 0; n1 = 0;
        for (i = 0; i <= l - n; i++)
        {
            if (c1[i] == n) c2[i] = 1;
            else c2[i] = 0;
            /*if (!i) c3[i] = c2[i];
            else c3[i] = c3[i - 1] + c2[i]; // no of substring consonants*/
            //if (i) cout << " "; cout << c2[i];
            if (c2[i]) { c3[n1] = i; n1++; }
        }
        c3.resize(n1); cc1.resize(n1); cc2.resize(n1);
        l1 = l - n + 1;
        for (i = 0; i < n1; i++)
        {
            cc1[i] = l1 - c3[i];
            if (!i) cc2[i] = c3[i] + 1;
            else cc2[i] = c3[i] - c3[i - 1];
        }
        /*cout << endl;
        for (i = 0; i <= l - n; i++) { if (i) cout << " "; cout << c3[i]; }
        cout << endl;*/
        res = 0;
        for (i = 0; i < n1; i++) res += (cc1[i] * cc2[i]);
        cout << "Case #" << cnt << ": " << res << endl;
    }
    return 0;
}
