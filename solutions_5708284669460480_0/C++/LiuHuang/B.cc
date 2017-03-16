#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
const int N = 233;
const int inf = 0x3f3f3f3f;
typedef long long ll;
#define SZ(v) ((int)(v).size())
#define SZ(v) ((int)(v).size())
#define pb push_back
#define ALL(v) (v).begin(), (v).end()
#define Fill(a,b) memset(a,b,sizeof(a))
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
int K, L , S;
string a, b;
bool have(string a , char c)
{
    for (char x : a)
        if (x==c)
        return true;
    return false;
}
int f(string a, string b)
{
    int n = SZ(a), m = SZ(b);
    int c = 0;
    for (int i=0;i<=n-m;i++)
    {
        if (a.substr(i, m) == b)
            c++;
    }
    return c;
}
int tot = 0;
string str;
int cnt = 0;
void dfs(int u )
{
    if (u==S) {
        tot +=  f(str, b);
        cnt++;
        return ;
    }
    for (char x : a) {
        str[u] = x;
        dfs(u + 1);
    }
}
int main()
{
    int re,ca=1;cin>>re;
    for (;ca<=re;ca++)
    {
        cin>>K>>L>>S;
        cin>>a>>b;

        printf("Case #%d: ", ca);
        bool ok = true;
        for (char x : b)
        {
            if (!have(a, x))
                ok = false;
        }
        if (!ok) {
            cout<<"0.0\n";
            continue;
        }
        int maxv;
        int len  = 0;
        for (int i=1;i<L;i++)
        {
            if (b.substr(0, i) == b.substr(L - i))
            {
                len = i;
            }
        }
        maxv = (S - len) / (L - len);
        int c = 0;
        cnt = tot = 0;
        str = "";
        str.resize(S);

        dfs(0);
        double qw = 1.0 * tot / double(cnt);
        qw = maxv - qw;
        printf("%.8f\n", qw);
    }
}
