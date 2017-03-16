#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;
#define sz 300005
#define inf 0x7fffffff
long long f[20];

long long ff(long long n)
{
    long long ret = 0;
    int flag = 0;
    if(n%10==0)
    {
        n--;
        flag = 1;
        //ret++;
    }
    //cout << n << endl;
    int len = 0;
    long long m = n;
    vector <int> b;
    while(m)
    {
        b.pb(m%10);
        m/=10;
        len++;
    }
    for (int i=(b.size()-1)/2; i>=0; i--)
        ret = ret *10 + b[i];

    int cnt = 0;
    long long ret1 = 0;
    for (int i=(b.size()-1)/2 + 1; i<b.size(); i++)
    {
        if(b[i]==0)cnt++;
        ret1 = ret1 *10+ b[i];
        //cout << b[i] << "fd" <<endl;
    }
    //cout << ret << " " << ret1 <<endl;
    int flag1 = 0;
    for (int i=b.size()-1; i>(b.size()-1)/2; i--)
    {
        if(i<b.size()-1 && b[i]!=0)flag1 = 1;

    }
    //cout << ret << " ?" <<endl;
    //cout << b[b.size()-1] << " " << cnt << endl;
    if(b[b.size()-1]!=1 || flag1)
        ret += ret1;
    //cout << ret << " " << f[len] <<endl;
    ret += f[len];
    //cout << ret << endl;
    ret += flag;
    return ret;
}
void init()
{
    f[1] = 1;
    f[2] = 10;
    long long ret = 100;
    for (int i=3; i<20; i++)
    {
        f[i] = ff(ret);
        ret *=10;
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    init();

    int T;
    cin>>T;
    rep(cas,T)
    {
        long long n;
        cin>>n;
        //cout << n <<endl;

        long long ret = 0;
        if(n<=10)
        {
            ret = n;
        }
        else
        {
            ret = ff(n);

        }

        cout << "Case #" <<cas +1 << ": " << ret <<endl;


    }
}
