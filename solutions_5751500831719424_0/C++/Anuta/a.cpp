#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T, n;
string s[150];
char ss[150];
string a;
vi b[150];
int k;

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", ss);
            s[i] = ss;

        }
        for (int i = 0; i < n; ++i)
            b[i].resize(0);
        int x = 0;
        a = ""; 
        for (int i = 1; i < s[0].size(); ++i)
        {
           if (s[0][i-1] == s[0][i])
           {
            ++x;
           } 
           else
           {
             b[0].push_back(x + 1);
             a.push_back(s[0][i-1]);
             x = 0;
           }
        }
        b[0].push_back(x+1);
        a.push_back(s[0][s[0].size()-1]);
        bool ok = true;
        for (int i = 1; i < n && ok; ++i)
        {
            x = 0;
            int c = 0;
            for (int j = 1; j < s[i].size() && ok; ++j)
            {
                if (s[i][j-1] == s[i][j])
                {
                    ++x;
                }
                else
                {
                    if (a[c] != s[i][j-1])
                    {
                        ok = false; break;
                    }
                    b[i].push_back(x+1);
                    x = 0; 
                    ++c;
                }    
            }
            if (c != b[0].size()-1 || a[c] != s[i][s[i].size()-1])
            {
                ok = false;
            }
            else
            {
                b[i].push_back(x+1);
            }
        }
        if (!ok)
        {
            printf("Case #%d: Fegla Won\n", t + 1);
            continue;
        }
        int res = 0;
        for (int i = 0; i < b[0].size(); ++i)
        {
            int mn = 100000000;
            for (int j = 0; j < n; ++j)
            {
                int p = 0;
                for (int z = 0; z < n; ++z)
                {
                    p += abs(b[z][i] - b[j][i]);
                }
                mn = min(p, mn);
            }
            res += mn;
        }
        printf("Case #%d: %d\n", t + 1, res);
    }
    return 0;
}