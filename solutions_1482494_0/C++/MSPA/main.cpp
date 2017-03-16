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
int t;
    cin>>t;
    int h=0;
    while (t--)
    {
        h++;
         cin>>n;
        vector <pair <int, int> > a(n);
        vi b(n,0);
        vi c(n,0);
        int bn=0;
        for(i=0;i<n;++i)    cin>>a[i].fi>>a[i].se;
        k=0;
        printf("Case #%d: ",h);
        int fl=0,kol=0;
        while (bn<n)
        {
            j=-1;
            kol++;
            for(i=0;i<n;++i)
                if (!c[i] && a[i].se<=k) {j=i; break;}
            if (j!=-1)
            {
                if (b[j])k++;
                else k+=2;
                c[j]=1;
                b[j]=1;
                bn++;
                continue;
            }
            j=-1;
            for(i=0;i<n;i++)
                if (!b[i] && a[i].fi<=k && (j==-1 || a[j].se<a[i].se)) {j=i;}
            if (j!=-1)
            {
                k++;
                b[j] = 1;
                continue;
            }
            fl=1;
            printf("Too Bad\n");
            break;
        }
        if (!fl) printf("%d\n",kol);
    }
    return 0;
}
