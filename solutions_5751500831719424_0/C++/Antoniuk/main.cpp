#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

string s[110];
string s1[110];

string f(string s)
{
    string res = "";
    for(int i = 0 ; i < s.size() ; ++i)
        if(i)
        {
            if(s[i] != s[i-1])
                res += s[i];
        }
        else
            res += s[i];
    
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int T = 0 ; T < t ; ++T)
    {
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; ++i)
        {
            cin >> s[i];
            s1[i] = f(s[i]);
        }
        
        cout << "Case #" << T+1 << ": ";
        
        sort(s1, s1+n);
        if(s1[0] != s1[n-1])
            cout << "Fegla Won\n";
        else
        {
            int ans = 0;
            int pos[n+1];
            for(int i = 0 ; i < n ; ++i)
                pos[i] = 0;
            
            for(int k = 0 ; k < s1[0].size() ; ++k)
            {
                int cnt[n+1];
                for(int i = 0 ; i < n ; ++i)
                    cnt[i] = 0;
                char ch = s1[0][k];
                for(int i = 0 ; i < n ; ++i)
                {
                    while(pos[i] < s[i].size() && s[i][pos[i]] == ch)
                    {
                        ++pos[i];
                        ++cnt[i];
                    }
                }
                sort(cnt, cnt+n);
                
                int mn = 100*1000;
                
                int S1, S2, P;
                S1 = S2 = 0;
                for(int i = 0 ; i < n ; ++i)
                    S2 += cnt[i];
                
                for(int i = 0 ; i < n ; ++i)
                {
                    P = 0;
                    S2 -= cnt[i];
                    
                    
                    P = (i*cnt[i] - S1);
                    P += (S2 - (n-1-i)*cnt[i]);
                    
                    S1 += cnt[i];
                    mn = min(mn, P);
                }
                
                ans += mn;
            }
            
            cout << ans << "\n";
        }
    }
    return 0;
}




