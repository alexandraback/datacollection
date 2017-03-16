#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a>b);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        string s, t;
        cin >> s;
        int i, p, ans = 0;
        cout << "Case #" << tc << ": ";
        while(1)
        {
            p = -1;
            for(i = 0; s[i] != '\0'; ++i)
            {
                if(s[i] == '-')
                    p = i;
            }
            if(p == -1)
                break;
            for(i = 0; s[i] != '-'; ++i)
                s[i] = '-';
            if(i)
                ans++;
            t = s.substr(0, p + 1);
            for(i = 0; i <= p; ++i)
            {
                if(t[p - i] == '-')
                    s[i] = '+';
                else
                    s[i] = '-';
            }
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
