#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
string s[110];
int ans = 0;
bool used[110];
vector<int> last;

void f(int pos, int P)
{
    if(pos == n)
    {
        ++ans;
        return;
    }
    
    vector<int> last1 = last;
    for(int i = 0 ; i < n ; ++i)
    if(!used[i])
    {
        last = last1;
        bool fl = 1;
        for(int p = 0 ; fl && p < s[i].size() ; ++p)
        {
            if(last[s[i][p]-'a'] != -1)
            if(last[s[i][p]-'a'] != P+p-1)
                fl = 0;
            
            last[s[i][p]-'a'] = P+p;
        }
        if(fl)
        {
            used[i] = 1;
            f(pos+1, P+(int)s[i].size());
            used[i] = 0;
        }
    }
    last = last1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int T = 1 ; T <= t ; ++T)
    {
        cin >> n;
        for(int i = 0 ; i < n ; ++i)
            cin >> s[i];
        
        for(int i = 0 ; i < n ; ++i)
        {
            string tmp = "";
            for(int j = 0 ; j < s[i].size() ; ++j)
            {
                if(j == 0)
                    tmp += s[i][j];
                else if(s[i][j] != s[i][j-1])
                    tmp += s[i][j];
            }
            s[i] = tmp;
        }
        
        memset(used, 0, sizeof used);
        ans = 0;
        last.resize(26);
        for(int i = 0 ; i < 26 ; ++i)
            last[i]  = -1;
        
        f(0, 0);
        
        cout << "Case #" << T << ": ";
        cout << ans << "\n";
    }
    return 0;
}