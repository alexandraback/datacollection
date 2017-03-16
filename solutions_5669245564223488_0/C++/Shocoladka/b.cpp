#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define ll long long
#define ld long double
#define op operator
#define m_p make_pair
#define fi first
#define se second

const int maxn = 105;

string str[maxn];
int us[maxn * 3];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t = 0; t < 100; t++)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> str[i];
        if(!(t >= 0 && t < 25))
            continue;
        cout << "Case #" << t + 1 << ": ";
        int a[n];
        for(int i = 0; i < n; i++)
            a[i] = i;
        int ans = 0;

        do
        {
            string s;
            for(int i = 0; i < n; i++)
            {
                s += str[a[i]];
            }
            for(int i = 0; i < 30; i++)
                us[i] = 0;
            int t = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(us[s[i] - 'a'] == 1)
                {
                    t = 1;
                    break;
                }
                else
                {
                    while(s[i] == s[i + 1] && i + 1 < s.size())
                        i++;
                    us[s[i] - 'a'] = 1;
                }
            }
            if(t == 0)
                ans++;
        }while(next_permutation(a, a + n));
        cout << ans << endl;
    }
}
