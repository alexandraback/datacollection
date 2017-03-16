#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <time.h>
#include <iomanip>

#define pi 3.1415926535897932
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) ((x)*(x))
#define fill(m,v) memset(m,v,sizeof(m))
#define sci(x) scanf("%d",&x)
#define scd(x) scanf("%lf",&x)
#define pri(x) printf("%d",x)
#define prd(x) printf("%lf",x)
#define oo 2000000000
#define fi first
#define se second
#define tr(container, iterator) for(typeof(container.begin()) iterator=container.begin(); it != container.end(); it++)
#define all(x) x.begin(), x.end()
#define y0 stupid_cmath
#define y1 very_stupid_cmath
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

template <class T>
istream & operator>> (istream & in, vector <T> & v)
{
    for(size_t i_=0;i_<v.size();++i_)
        in>>v[i_];
    return in;
}

template <class T>
ostream & operator<< (ostream & out, vector <T> & v)
{
    for(size_t i_=0;i_<v.size();++i_)
        out<<v[i_]<<' ';
    out<<endl;
    return out;
}


ll j,k,m,i,n;
ll a[501];
ll b[501];
ll c[1000500];
int main()
{
    ios_base::sync_with_stdio(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int h=0,t;
    cin>>t;
    while (t--)
    {
        h++;
        cin>>n;
        memset(b,0,n * sizeof b[0]);
        for(i=0;i<n;++i) cin>>a[i];
        cout<<"Case #"<<h<<":\n";
        int fl=0;
        for(i=1;i<(1<<n);++i)
        {
            int x= i;
            j=0;
            int s=0;
            memset(b,0,n * sizeof b[0]);
            while (x)
            {
                if (x%2) {s+=a[j]; b[j]=1;}
                j++;
                x/=2;
            }
            vi c;
            for(j=0;j<n;++j)
                if (!b[j]) c.pb(a[j]);
            int d = c.size();
            //cout<<c;
           // cout<<s<<'\n';
           for(j=1;j<(1<<d);++j)
            {
                int y = j,t=0;
                vi v(d);
                k=0;
                while (y)
                {
                    if (y%2) {t+=c[k]; v[k]=1;}
                    k++;
                    y/=2;
                }
                if (t==s)
                {
                    fl=1;
                    for(j=0;j<n;++j)
                            if(b[j]) cout<<a[j]<<' ';
                    cout<<endl;
                    for(j=0;j<d;++j)
                        if (v[j]) cout<<c[j]<<' ';
                    cout<<endl;
                    break;
                }
            }
            if (fl) break;
        }
        if (!fl) cout<<"Impossible\n";
    }
    return 0;
}
