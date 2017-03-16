#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    cin >> tc;
    for(int kras=1; kras<=tc; kras++)
    {
        printf("Case #%d: ", kras);
        string s;
        cin >> s;
        int ans1=0;
        if(s[s.size()-1] == '+')
        {
            ans1 = -1;
        }
        for(int i=s.size()-1; i>=0; i--)
        {
            if(i==s.size()-1 || s[i] != s[i+1])
            {
                ans1++;
            }
        }
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '+')
            {
                s[i]='-';
            }
            else
            {
                s[i]='+';
            }
        }
        int ans2=1;
        if(s[s.size()-1] == '+')
        {
            ans2=0;
        }
        for(int i=s.size()-1; i>=0; i--)
        {
            if(i==s.size()-1 || s[i] != s[i+1])
            {
                ans2++;
            }
        }

        int ans = min(ans1, ans2);
        printf("%d\n", ans);
    }
    return 0;
}
