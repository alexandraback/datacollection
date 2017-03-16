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
    int t,h=0;
    cin>>t;
    while (t--)
    {
        h++;
        cin>>n;
        vi a( n);
        cin>>a;
        vector <double> b(n);
        int s=0,d;
        for(i=0;i<n;++i) s+=a[i];
        d=s;
        while (s)
        {
            j=0; k=0;
            for(i=0;i<n;++i)
                if (a[j]+b[j]>a[i]+b[i]) j=i;
            for(i=0;i<n;++i)
               if (a[j]+b[j]==a[i]+b[i]) k++;
            double t = a[j]+b[j];
            if (k<=s)
            {
                for(i=0;i<n;++i)
                if (t==a[i]+b[i]) b[i]++;
                s-=k;
            }
            else {
                for(i=0;i<n;++i)
                if (t==a[i]+b[i]) b[i]+=1.0*s/k;
                s=0;
            }
        }
        // cout<<b;
        printf("Case #%d: ",h);
        for(i=0;i<n;++i)
            printf("%.6lf ",b[i]*100./d);
        printf("\n");
    }
    return 0;
}
