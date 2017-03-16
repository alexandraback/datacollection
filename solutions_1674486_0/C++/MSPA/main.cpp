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
int a[1005][1005];
int b[1005];
int fl;

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
        cin>>n;
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                a[i][j]=0;
        for(i=0;i<n;++i)
        {
            cin>>m;
            for(j=0;j<m;++j)
            {
                cin>>k;
                k--;
                a[i][k]=1;
            }
        }
        fl=0;
        for(i=0;i<n;++i)
        {
            memset(b,0,n * sizeof b[0]);
            queue <int> q;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for(j=0;j<n;++j)
                    if(a[x][j])
                    {
                        if (b[j]) {fl=1; break;}
                        b[j]++;
                        q.push(j);
                    }
                if (fl) break;
            }
            if (fl) break;
        }
        cout<<"Case #"<<h<<": ";
        if (fl) cout<<"Yes\n";
        else cout<<"No\n";
        //printf("Case #%d: ",h);
    }
    return 0;
}
