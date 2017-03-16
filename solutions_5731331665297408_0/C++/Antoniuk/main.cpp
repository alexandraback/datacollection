#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int n, m;
int a, b;
string s[10];
string res;
int ord[10];
int g[10][10];

bool can(int v, int st, vector<int> stack)
{
    if(v == n)
        return 1;
    if(st < 0)
        return 0;
    
    for(int i = st ; i >= 0 ; --i)
    {
        if(g[stack[i]][ord[v]] == 1)
        {
            int mem = stack[i+1];
            stack[i+1] = ord[v];
            if(can(v+1, i+1, stack))
                return 1;
            stack[i+1] = mem;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int T = 0 ; T < t ; ++T)
    {
        cin >> n >> m;
        res = "";
        for(int i = 0 ; i < n ; ++i)
        {
            cin >> s[i];
            res += s[i];
            ord[i] = i;
        }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        
        
        vector<int> stack(n+10);
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                g[i][j] = 0;
        
        for(int i = 0 ; i < m ; ++i)
        {
            cin >> a >> b;
            --a, --b;
            g[a][b] = g[b][a] = 1;
        }
        
        do
        {
            string tmp_res = "";
            for(int i = 0 ; i < n ; ++i)
                tmp_res += s[ord[i]];
            
            if(tmp_res < res)
            {
                stack[0] = ord[0];
                if(can(1,0,stack))
                    res = tmp_res;
            }
        }
        while(next_permutation(ord, ord+n));
        
        cout << "Case #" << T+1 << ": ";
       
        cout << res << "\n";
    }
    return 0;
}




