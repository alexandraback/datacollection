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


int j,k,m,i,n;

int main()
{
    ios_base::sync_with_stdio(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int h=0, t;
    cin>>t;
    while (t--)
    {
        h++;
        cin>>n>>m;
        vector <pair <ll, ll> > a(n);
        vector <pair <ll, ll> > b(m);
        vector <pair <ll, ll> > det(m);
        for(i=0;i<n;++i) cin>>a[i].fi>>a[i].se;
        for(i=0;i<m;++i) cin>>b[i].fi>>b[i].se;
        vector < vi > c(n);
        for(i=0;i<m;++i)
            for(j=0;j<n;j++)
                if (b[i].se==a[j].se)
                    c[j].pb(i);
        vi fl(m);
        ll s=0,res=0,v=0,l=0;
        for(i=0;i<m;++i) det[i]=b[i];
        for(i=-1;i<(int)c[0].size();++i)
        {
            for(int ii=0;ii<m;++ii) b[ii]=det[ii];

            if (i>=0)
                if (b[c[0][i]].fi+s>=a[0].fi) {b[c[0][i]].fi=s+b[c[0][i]].fi-a[0].fi;s = a[0].fi; }
                else s+=b[c[0][i]].fi,b[c[0][i]].fi=0;
            if (n>1)
            {
                v=0;
                for(j=-1;j<(int)c[1].size();++j)
                    {   if ((j>=0 && i>=0 && c[1][j]>=c[0][i]) || (j>=0 && i==-1))
                        {
                            //cout<<"!"<<b[c[1][j]].fi<<" "<<v<<' '<<a[1].fi<<' ';
                            if (b[c[1][j]].fi+v>=a[1].fi) {b[c[1][j]].fi=v+b[c[1][j]].fi-a[1].fi; v = a[1].fi;}
                            else v+=b[c[1][j]].fi,b[c[1][j]].fi=0;
                            //cout<<v<<endl;
                        }
                        if (n>2)
                        {
                            l=0;
                            for(k=-1;k<(int)c[2].size();++k)
                            {
                                if ((k>=0 && j>=0 && c[2][k]>=c[1][j]) || (j==-1  && k>=0 && i>=0 && c[2][k]>=c[0][i]) || (k>=0 && i==j && i==-1))
                                {
                         //           cout<<b[c[2][k]].fi+l<<" "<<a[2].fi<<endl;
                                    if (b[c[2][k]].fi+l>=a[2].fi) {l = a[2].fi;}
                                    else l+=b[c[2][k]].fi;
                                }
                  //             cout<<s<<" "<<v<<" "<<l<<"       "<<i<<" "<<j<<' '<<k<<"       "<<c[0][i]<<" "<<c[1][j]<<' '<<c[2][k]<<endl;
                                res = max(res,s+v+l);
                            }
                        }
                        else res = max(res,s+v);
                    }
            }
            else res = max(res,s);
        }
        cout<<"Case #"<<h<<": "<<res<<endl;
        //printf("Case #%d: ",h);
    }
    return 0;
}
