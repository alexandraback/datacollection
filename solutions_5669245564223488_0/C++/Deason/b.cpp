#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>


using namespace std;

const int mod = 1000000007;

int T, cases = 0;
int n;
int pure[26];
int CNT;
vector<string> ss;

int vis[110], isf[326], isr[326];
int dfs(int);
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    string s;
    cin >> T;
    while (T--)
    {
        cout << "Case #" << (++cases) << ": ";
        cin >> n;
        ss.clear();
        memset(pure, 0, sizeof(pure));
        memset(vis, 0, sizeof(vis));
        memset(isf, 0, sizeof(isf));
        memset(isr, 0, sizeof(isr));
        int flag = 1;
        CNT = 0;
        for (int i=0;i<n;++i)
        {
            cin >> s;
            int pos[26] = {}, cnt = 0;
            for (int j=0;s[j];++j)
            {
                if (!pos[s[j]-'a'])
                    ++cnt;
                if (pos[s[j]-'a'] != j && pos[s[j]-'a'])
                {
                    flag = 0;
                    break;
                }
                pos[s[j]-'a'] = j+1;
            }
            if (cnt > 1)
            {
                for (int i=1;i<s.size()-1;++i)
                    if (s[i] != s[0] && s[i] != s[s.size()-1])
                        isf[s[i]] = isr[s[i]] = 1;
                ss.push_back(s);
            }
            else
                pure[s[0]-'a']++;
        }
        int ccc = 0;
        for (int i=0;flag&&i<ss.size();++i)
        {
            if (isf[ss[i][0]] || isr[ss[i][ss[i].size()-1]])
            {
                flag = 0;
                break;
            }
            isf[ss[i][0]] = 1;
            isr[ss[i][ss[i].size()-1]] = 1;
        }
        for (int i=0;flag&&i<ss.size();++i)
        {
            if (!vis[i])
            {
                ++CNT;
                vis[i] = ++ccc;
                flag = dfs(i);
            }
        }
        if (flag)
        {
            long long ANS = 1;
            for (int i=0;i<26;++i)
                for (int j=2;j<=pure[i];++j)
                    ANS = (ANS*j) % mod;
            for (int i=0;i<26;++i)
                if (isf[i+'a']==0 && isr[i+'a']==0 && pure[i])
                    ++CNT;
            for (int i=2;i<=CNT;++i)
                ANS = (ANS*i) % mod;
            cout << ANS << endl;
        }
        else
            cout << "0" << endl;
    }
    return 0;
}
int dfs(int p)
{
    int sz = ss[p].size();
    for(int i=0;i<ss.size();++i)
    {
        if (ss[p][sz-1] == ss[i][0])
        {
            if (vis[i] == vis[p])
                return 0;
            if (vis[i])
                --CNT;
            vis[i] = vis[p];
            return dfs(i);
        }
    }
}
