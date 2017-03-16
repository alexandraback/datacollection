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
int c,d, v, dd[10];
int mmp[100];
void dfs(int dx, int sum)
{
    if (dx == d)
    {
        mmp[sum] = 1;
        return;
    }
    dfs(dx+1, sum);
    dfs(dx+1, sum+dd[dx]);
}
int ss[200];
int cal1()
{
    cin>>c>>d>>v;
    rp(i,d) cin>>dd[i];
    mst(mmp,0);
    dfs(0,0);
    int res = 0;
    mst(ss,0);
    rep(i,1,v+1)
    if (!mmp[i])
    {
        ++res;
        rep(j,i+1,v+1)
        {
            if (mmp[j])
            {
                ++ss[j-i];
            }
        }
    }
    vector<pair<int,int>> q;
    rep(i,1,v+1)
    if (ss[i])
        q.push_back(make_pair(ss[i],i));
    sort(q.begin(), q.end());
    int cnt = 0;
    for (int i = q.size()-1; i>=0; --i)
    {
        pair<int,int> a = q[i];
        cnt++;
        res -= a.first;
        if (res <= 0) break;
    }

    return cnt;
}
void solv1()
{
    freopen("C-small-attempt1.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    repd(_,1,t)
    {
        printf("Case #%d: ", _);
        printf("%d\n", cal1());
    }
}
int main()
{
    solv1();
    //solv2();
    return 0;
}
