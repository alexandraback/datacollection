#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int lim;
string a,b;
string ansi,ansj;
ll ans,besti,bestj;

void solve(int pos, string ta, string tb, int flag)
{
    if(pos >= lim)
    {
        ll ni = atoll(ta.c_str());
        ll nj = atoll(tb.c_str());
        ll dif = labs(ni - nj);
        if(dif < ans || (dif == ans && ni < besti) || (dif == ans && ni == besti && nj < bestj))
        {
            ans = dif;
            besti = ni;
            bestj = nj;
            ansi = ta;
            ansj = tb;
        } 
        return;
    }

    if(a[pos] == b[pos])
    {
        if(a[pos] == '?')
        {
            if(flag == 0)
                solve(pos + 1, ta + "0", tb + "0", flag);
            if(flag == 1)
                solve(pos + 1, ta + "9", tb + "0", flag);
            else if(flag == 2)
                solve(pos + 1, ta + "0", tb + "9", flag);
        }
        else
        {
            string x = ta;
            x.push_back(a[pos]);
            string y = tb;
            y.push_back(b[pos]);
            solve(pos + 1, x, y, flag);
        }
    }
    else
    {
        if(a[pos] == '?' && b[pos] != '?')
        {
            string x = ta;
            x.push_back(b[pos]);
            string y = tb;
            y.push_back(b[pos]);
            solve(pos + 1, x, y, flag);
            if(flag == 0)
            {
                string x1 = ta;
                x1.push_back('0');
                string y1 = tb;
                y1.push_back(b[pos]);
                solve(pos + 1, x1, y1, flag);
            }
        }
        else if(a[pos] != '?' && b[pos] == '?')
        {
            string x = ta;
            x.push_back(a[pos]);
            string y = tb;
            y.push_back(a[pos]);
            solve(pos + 1, x, y, flag);
            if(flag == 0)
            {
                string x1 = ta;
                x1.push_back(a[pos]);
                string y1 = tb;
                y1.push_back('0');
                solve(pos + 1, x1, y1, flag);
            }
        }
        else
        {
            string x = ta;
            x.push_back(a[pos]);
            string y = tb;
            y.push_back(b[pos]);
            if(flag != 0)
                solve(pos + 1, x, y, flag);
            else if(a[pos] < b[pos])
                solve(pos + 1, x, y, 1);
            else if(a[pos] > b[pos])
                solve(pos + 1, x, y, 2);

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,ntest=1;
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        lim = a.size();
        ans = 9223372036854775807LL;
        solve(0, "", "", 0);
        cout << "Case #" << ntest++ << ": " << ansi << " " << ansj << '\n';
    }
    return 0;
}