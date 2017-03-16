#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

string s, t, c, j;
int minDiff, c_val, j_val;

void solve(int pos, string s, string t)
{
    if(pos < 0)
    {
        int x=0,y=0,d=1;

        for(int i = s.size()-1; i >= 0; i--)
        {
            x += (((int)s[i]-'0') * d);
            y += (((int)t[i]-'0') * d);
            d *= 10;
        }

        if(abs(x-y) < minDiff)
        {
            minDiff = abs(x-y);
            c = s; j = t;
            c_val = x; j_val = y;
            return ;
        }

        if(abs(x-y) == minDiff)
        {
            if(x < c_val)
            {
                c_val = x;
                j_val = y;
                c = s; j = t;
                return ;
            }
            else if(x == c_val)
            {
                if(y < j_val)
                {
                    j_val = y;
                    c = s; j = t;
                    return ;
                }
            }
        }

        return ;
    }

    if(s[pos] != '?' && t[pos] != '?')
    {
        solve(pos-1, s, t);
        return ;
    }

    if(s[pos] == '?' && t[pos] == '?')
    {
        for(char i = '0'; i <= '9'; i++)
        {
            for(char k = '0'; k <= '9'; k++)
            {
                s[pos] = i; t[pos] = k;
                solve(pos-1, s, t);
            }
        }
        return ;
    }

    for(char i = '0'; i <= '9'; i++)
    {
        if(s[pos] == '?')
        {
            s[pos] = i;
            solve(pos-1, s, t);
            s[pos] = '?';
        }
        else
        {
            t[pos] = i;
            solve(pos-1, s, t);
            t[pos] = '?';
        }
    }
}

int main()
{
    //READ("B-small-attempt0.in");
    //WRITE("B-small-attempt0.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, i, k, cnt, n;

    cin >> cases;

    while(cases--)
    {
        cin >> s >> t;

        n = s.size();
        minDiff = 1000000;

        solve(s.size()-1, s, t);

        cout << "Case #" << ++caseno << ": " << c << " " << j << NL;
    }

    return 0;
}




