#include <bits/stdc++.h>

using namespace std;

long long inf = 1e18;

pair<long long, pair<long long, pair<long long, string> > > ans;

void go(string &s, int now)
{
    if(now==s.size())
    {
        long long n1, n2;
        int S = s.size();
        string s1 = s.substr(0, S/2);
        string s2 = s.substr(S/2, S/2);
        n1 = atoll(s1.c_str());
        n2 = atoll(s2.c_str());
        ans = min(ans, make_pair(abs(n1-n2), make_pair(n1, make_pair(n2, s))));
        return;
    }
    //Generate all
    if(s[now] == '?')
    {
        for(char c='0'; c<='9'; c++)
        {
            s[now] = c;
            go(s, now+1);
            s[now] = '?';
        }
    }
    else
    {
        go(s, now+1);
    }
}
int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        //CHECK if with or without endline!!!
        printf("Case #%d: ", kras);
        string coders, jammers;
        cin >> coders >> jammers;

        string conc=coders;
        conc += jammers;

        ans = make_pair(inf, make_pair(inf, make_pair(inf, "ABC")));
        go(conc, 0);
        string samen = ans.second.second.second;
        int S = samen.size();
        string op1 = samen.substr(0, S/2);
        string op2 = samen.substr(S/2, S/2);

        cout << op1 << " " << op2 << endl;
    }
    return 0;
}
