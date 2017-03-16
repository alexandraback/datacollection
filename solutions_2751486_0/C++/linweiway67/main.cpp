#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
bool vis[30];
int n;

bool check(string s)
{
    int len = s.length();
    int i;
    int lenret = 0;
    if(s == "rtz")
    {
        int tt = 1;
    }
    for(i=0; i<len; i++)
    {
        if(vis[s[i]-'a']) // ÔªÒô×ÖÄ¸
        {
            lenret = 0;
        }
        else lenret++;
        if(lenret >= n) return 1;
    }
    return 0;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ta=1;
    cin >> T;
    memset(vis,0,sizeof(vis));
    vis['a'-'a'] = vis['e'-'a'] = vis['i'-'a'] = vis['o'-'a'] = vis['u'-'a'] = 1;
    while(T--)
    {
        string st,_subst;
        cin >> st >> n;
        int i,j,len;
        len = st.length();

        int ans = 0;
        for(i=0; i<len; i++)
        {
            for(j=1; j<=len-i; j++)
            {
                _subst = st.substr(i,j);
                if(check(_subst)) ans++;
            }
        }
        printf("Case #%d: %d\n",ta++,ans);
    }
    return 0;
}
