#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;
int n, m;

int T,TT;


bool vis[MAXN];
bool appear[200];
string str[MAXN];


bool test(string s) {
    memset(appear, 0, sizeof(appear));
    appear[s[0]-'a'] = 1;
    for(int i = 1; i < s.length(); i ++)
        if(s[i] != s[i - 1] && appear[s[i] - 'a'])
            return false;
        else
            appear[s[i] - 'a'] = true;

    return true;
}

int dfs(string s, int x) {
    //cout << s << endl;
    if(n == x)
    {
        //if(test(s))
        return 1;
       // else
            //return 0;
    }

    int total = 0;
    for (int i = 0; i < n; i ++)
    {
        if(vis[i] == 0) {
            if(test(s + str[i]))
            {
                vis[i] = 1;
                total += dfs(s + str[i], x + 1);
                vis[i] = 0;
            }
        }
    }
    return total;
}

int main()
{
    freopen("R1C_2_in.txt", "r", stdin);
    freopen("R1C_2_out.txt", "w", stdout);

    cin >> T;
    TT = 1;

    while(T) {

        memset(vis, 0, sizeof(vis));

        cin >> n;
        for(int i = 0; i < n; i ++)
            cin >> str[i];

        int x = dfs("", 0);

        cout << "Case #" << TT << ": ";
        cout << x << endl;
        T --;
        TT ++;
    }

    return 0;
}

