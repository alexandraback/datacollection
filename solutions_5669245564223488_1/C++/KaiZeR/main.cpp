#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long mod = 1e9+7;

int n;
string s[110];
long long ans = 0;
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
            //cout << s[i] << "\n";
        }
        sort(s, s+n);
        
        int nn = 1;
        long long P = 1;
        vector<int> v;
        
        
        for(int i = 1 ; i < n ; ++i)
        {
            int cnt = 1;
            while(i < n && s[i] == s[i-1] && s[i].size() == 1)
            {
                ++i, ++cnt;
            }
            if(cnt > 1)
            {
            	v.push_back(cnt);
            	--i;
            }
            else
                s[nn++] = s[i];
        }
        n = nn;
        
        bool fl = 1;
        while(fl)
        {
            fl = 0;
            for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < n ; ++j)
                if(i != j)
                if(s[i].back()==s[j][0])
                {
                    s[i] += s[j];
                    for(int k = j+1 ; k < n ; ++k)
                        s[k-1] = s[k];
                    --n;
                    i = j = n;
                    fl = 1;
                }
        }
        
        bool res = 1;
        
        int uu[30], pos[30];
        for(int i = 0 ; i < 27 ; ++i)
            uu[i] = -1, pos[i] = -1;
        
        for(int i = 0 ; res == 1 && i < n ; ++i)
        {
            for(int j = 0 ; res == 1 && j < s[i].size() ; ++j)
            {
                if(uu[s[i][j]-'a'] == -1)
                {
                    uu[s[i][j]-'a'] = i;
                    pos[s[i][j]-'a'] = j;
                }
                if(uu[s[i][j]-'a'] != i)
                    res = 0;
                else
                {
                    if(j-pos[s[i][j]-'a'] > 1)
                        res = 0;
                    pos[s[i][j]-'a'] = j;
                }
            }
        }
        
        cout << "Case #" << T << ": ";
        if(!res)
        {
            cout << 0 << "\n";
            continue;
        }
        memset(used, 0, sizeof used);
        ans = 0;
        last.resize(26);
        for(int i = 0 ; i < 26 ; ++i)
            last[i]  = -1;
        
        //f(0, 0);
        ans = 1;
        for(int i = 2 ; i <= n ; ++i)
            ans = (ans*i)%mod;
        for(int i = 0 ; i < v.size() ; ++i)
        {
            for(int j = 2 ; j <= v[i] ; ++j)
                P = (P*j)%mod;
        }
        
       
        cout << (ans*P)%mod << "\n";
    }
    return 0;
}