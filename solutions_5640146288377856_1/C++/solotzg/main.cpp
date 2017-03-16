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
void solv1()
{
    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    repd(_,1,t)
    {
        printf("Case #%d: ", _);
        int a, b, c, res = 0;
        cin>>a>>b>>c;
        if (b < (c*2))
        {
            printf("");
        }
        while (b > c)
        {
            b -= c;
            ++res;
        }
        res += c;
        cout<<res<<endl;
    }
}
void solv2()
{
    freopen("A-large.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    repd(_,1,t)
    {
        printf("Case #%d: ", _);
        int a, b, c, res = 0;
        cin>>a>>b>>c;
        rp(i,a)
        {
            int bb = b;
            while (bb > c)
            {
                bb -= c;
                ++res;
            }
            if (bb == c)
                ++res;
        }
        res += c-1;
        if (b % c != 0)
            ++res;
        cout<<res<<endl;
    }
}
int main()
{
    //solv1();
    solv2();
    return 0;
}
