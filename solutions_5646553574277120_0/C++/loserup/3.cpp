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
int vis[40];
vector <int> p;
int da[40];
int V,C;
int t[40];
int ret;
int a[40];
void dfs(int s, int dep, int num)
{
    if(num>=ret)return;
    if(dep == 5)
    {

        vector <int> p1;
        rep(i,V+1)if(vis[i])p1.pb(i);
        rep(i,num)p1.pb(a[i]);

        int n = p1.size();
/*
        for (int i=0;i<p1.size();i++)
            cout << p1[i] << " ";
        cout << endl;
*/
        //cout << V <<endl;
        memset(t,0,sizeof(t));
        rep(i,(1<<n))
        {
            //cout << ">>> " << i << endl;
            int sum = 0;
            rep(j,n)
            {
                if(i&(1<<j))
                {
                    sum+=p1[j];
                }
            }
            //cout << sum << " ?? " << endl;
            if(sum<=V)
                t[sum]=1;
        }

        int flag = 0;

        for (int i=1;i<=V;i++)
        {
            //cout << t[i] << " ";
            if(t[i]==0)flag = 1;
        }
        if(flag == 0)
        {
            ret = min(ret, num);
        }
    }
    else
    {

     dfs(s,dep+1,num);
        for (int i=s;i<p.size();i++)
        {
            a[num]=p[i];
            dfs(i+1, dep+1, num+1);
        }
    }

}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);

    int T,c,d,v,a;
    cin>>T;
    rep(cas,T)
    {
        cin>>c>>d>>v;
        V = v;
        C = c;
        memset(vis,0,sizeof(vis));
        rep(i,d)
        {
            cin>>a;
            vis[a] = 1;
        }
        p.clear();
        for (int i=1;i<=v;i++)
            if(!vis[i])p.pb(i);


        ret = 5;
        dfs(0, 0, 0);
        cout << "Case #"<< cas+1 <<": " << ret << endl;
    }
}
