#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iomanip>
#include<queue>
#include<iterator>
using namespace std;

#define MAXN 100000 + 10
typedef int Int;
char s[MAXN];
Int T, n;
char v[] = "aoeiu";
bool inv(char x)
{
    for(Int i = 0; i < 5; ++i) if(x == v[i]) return true;
    return false;
}
int main(int argv, char **args)
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> T;
    for(Int id = 1; id <= T; ++id)
    {
        cin >> s >> n;
        Int len = strlen(s);
        Int ans = 0;
        for(int i = 0; i < len; ++i)
        {
            for(int j = i + n - 1; j < len; ++j)
            {
                int cnt = 0;
                for(int k = i; k <= j; ++k)
                {
                    if(inv(s[k])) cnt = 0;
                    else ++cnt;
                    if(cnt == n)
                    {
                        ++ans;
                        break;
                    }
                }
            }
        }
        cout << "Case #" << id << ": " << ans << endl;
    }
    return 0;
}
