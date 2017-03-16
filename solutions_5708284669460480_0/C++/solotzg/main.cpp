#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rp(i,b) for(int i=(0), __tzg_##i=(b);i<__tzg_##i;++i)
#define rep(i,a,b) for(int i=(a), __tzg_##i=(b);i<__tzg_##i;++i)
#define repd(i,a,b) for(int i=(a), __tzg_##i=(b);i<=__tzg_##i;++i)
#define mst(a,b) memset(a,b,sizeof(a))
const int MAXN = 1005;
const ll mod = 1000000007;
string dd, bb;
int sz;
double oo, nima[500];
double yu;
int cao[500];
void dfs(int cnt, int all, string s)
{
    if (cnt == all)
    {
        int loc = 0, cd = 0;
        while ((loc = s.find(bb, loc)) != string::npos)
        {
            ++cd;
            ++loc;
        }
        yu = max(yu, (double)cd);
        double rr = 1.0;
        rp(i,s.size())
        {
            rr *= nima[s[i]];
        }
        oo += rr*cd;
        return;
    }
    rp(i,sz)
    {
        dfs(cnt+1, all, s+dd[i]);
    }
}
double cal1()
{
    int k, l, s;
    string a, b;
    cin>>k>>l>>s>>a>>b;
    //cout<<k<<endl<<l<<endl<<s<<endl<<a<<endl<<b<<endl;
    mst(cao, 0);
    rp(i,k) ++ cao[a[i]];
    rp(i,l) if (!cao[b[i]]) return 0.0;
    rp(i, 500)
    {
        if (cao[i])
        {
            nima[i] = cao[i]*1.0 / a.size();
        }
    }
    sort(a.begin(), a.end());
    sz = unique(a.begin(), a.end()) - a.begin();
    dd = a;
    bb = b;
    oo = 0.0;
    yu = 0.0;
    dfs(0,s,"");
    return yu-oo;
}
void solv1()
{
    freopen("B-small-attempt1.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    repd(_,1,t)
    {
        printf("Case #%d: ", _);
        printf("%.7lf\n", cal1());
    }
}
int main()
{
    solv1();
    //solv2();
    return 0;
}
