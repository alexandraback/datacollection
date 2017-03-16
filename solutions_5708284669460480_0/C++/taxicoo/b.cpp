#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back


vector<string> res;
vector<char> v;
vector<int> ans;
string st, ttt;
int maxx;

void rec(int n, int pos)
{
    if (pos == n)
    {
        res.pb(st);
        return;
    }
    for (int i=0; i<v.size(); ++i)
    {
        st[pos] = v[i];
        rec(n, pos+1);
    }
}

void solve(string tar)
{
    int lst = res[0].length()-tar.length();
    int temp;
    for (int i=0; i<res.size(); ++i)
    {
        temp=0;
        for (int j=0; j+tar.length()<=res[i].length(); ++j)
        {
            for (int k=0; k<tar.length(); ++k)
            {
                if ((k==tar.length()-1) && (res[i][j+k]==tar[k]))
                    ++temp;
                if (res[i][j+k] != tar[k])
                    break;
            }
        }
        maxx=max(maxx, temp);
        ans.pb(temp);
    }
}

int main()
{
    freopen("inputb.txt", "r", stdin);
    freopen("outputb.txt", "w", stdout);
    int T, k, l, s, up;
    string target, keys;
    double ret;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        up=0;
        maxx=0;
        st="";
        ttt="";
        v.clear();
        res.clear();
        ans.clear();
        cin >> k >> l >> s;
        cin >> keys;
        cin >> target;
        for (int i=0; i<k; ++i)
        {
            v.pb(keys[i]);
        }
        sort(v.begin(), v.end());
        for (int i=0; i<s; ++i)
            st+='A';
        rec(s, 0);
        solve(target);
        for (int i=0; i<ans.size(); ++i)
        {
            up+=(maxx-ans[i]);
        }
        ret = (double)(up) / (double)(res.size());
        printf("Case #%d: %.8f\n", t, ret);
    }



    return 0;
}
