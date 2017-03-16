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
#define rep(i,n) for(int i=0;i<n;i++)
#define A frist
#define B second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;

const int base = 700000;

int v[700000 * 2];
struct node
{
    int day;
    int st;
    int en;
    int h;

    node(int _d,int s,int t,int _h)
    {
        day = _d + base;
        st = s + base;
        en = t + base;
        h = _h;
        v[day] = 1;
    }
    node() {}
};

vector <node> p;
int cmp(node a,node b)
{
    return a.day < b.day;
}
#define sz 100
int d[sz],ni[sz],w[sz],s[sz],dd[sz],dp[sz],ds[sz];
int e[sz],he[700000 * 2];
int main()
{


        freopen("C.in","r",stdin);
        freopen("Cout.txt","w",stdout);

    int T;
    cin>>T;
    rep(cas,T)
    {
        int n;
        cin>>n;


        memset(v,0,sizeof(v));

        p.clear();
        rep(i,n)
        {
            cin>>d[i]>>ni[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];

            for(int j=0; j<ni[i]; j++)
            {
                p.pb(node(d[i]+j*dd[i],w[i]+j*dp[i],e[i]+j*dp[i],s[i]+j*ds[i]));
            }
        }

        sort(p.begin(),p.end(),cmp);

        rep(i,p.size())
        //cout << p[i].day << " " << p[i].st << " " << p[i].en << endl;
        memset(he,0,sizeof(he));
        int j=0;
        int ret = 0;
        for(int i=0; i<700000*2; i++)
        {
            if(v[i])
            {
                int sst = -1;
                int een = -1;
                for(; j<p.size(); j++)
                {
                    if(p[j].day == i)
                    {
                        if(sst == -1)sst = j;
                        een = j;
                        for(int k=p[j].st; k<p[j].en; k++)
                        {
                            if(he[k]<p[j].h)
                            {

                                ret++;
                                break;
                            }
                        }
                    }
                    else break;
                }
                for(int k=sst; k<=een; k++)
                    for(int l=p[k].st; l<p[k].en; l++)
                        he[l] = max(he[l],p[k].h);
            }
        }
        printf("Case #%d: ",cas+1);
        cout << ret << endl;

    }
}













