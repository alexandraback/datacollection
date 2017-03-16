#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
 
using namespace std;

#define MAX 1000008
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define pb push_back
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define itr(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> lli;
typedef pair<int,pii> i3;
 

char aa[20],bb[20];
bool ok;

int main() {
    read; write;
    int t;
    gi(t);
    int n,m,x,y,z,lim;
    string a,b,aaa,bbb;
    for(int tt = 1; tt <= t; tt++) {
        cin>>a>>b;
        m = 0;
        lim = 1;
        n = a.size();
        for (int i = 0; i<n; i++)
            lim*=10;
        for (int i = 0; i<lim; i++)
            for (int j = 0; j<lim; j++)
            {
                ok = true;
                if(n==1)
                {
                    sprintf(aa,"%01d",i);
                    sprintf(bb,"%01d",j);
                    aaa = aa;
                    bbb = bb;
                }
                else if(n==2)
                {
                    sprintf(aa,"%02d",i);
                    sprintf(bb,"%02d",j);
                    aaa = aa;
                    bbb = bb;
                }
                else if(n==3)
                {
                    sprintf(aa,"%03d",i);
                    sprintf(bb,"%03d",j);
                    aaa = aa;
                    bbb = bb;
                }
                for (int k = 0; k<n; k++)
                {
                    if(a[k]=='?') continue;
                    if(a[k]!=aaa[k])
                    {
                        ok = false;
                        break;
                    }
                }
                for (int k = 0; k<n; k++)
                {
                    if(b[k]=='?') continue;
                    if(b[k]!=bbb[k])
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                {
                    if(m==0)
                    {
                        m = 1;
                        x = abs(i-j);
                        y = i;
                        z = j;
                    }
                    else
                    {
                        if(abs(i-j)<x)
                        {
                            x = abs(i-j);
                            y = i;
                            z = j;
                        }
                    }
                }
            }
        cout<<"Case #"<< tt <<": ";
        if(n==1)
        {
            sprintf(aa,"%01d",y);
            sprintf(bb,"%01d",z);
            aaa = aa;
            bbb = bb;
        }
        else if(n==2)
        {
            sprintf(aa,"%02d",y);
            sprintf(bb,"%02d",z);
            aaa = aa;
            bbb = bb;
        }
        else if(n==3)
        {
            sprintf(aa,"%03d",y);
            sprintf(bb,"%03d",z);
            aaa = aa;
            bbb = bb;
        }
        cout<<aaa<<" "<<bbb<<"\n";
    }
	return 0;
}