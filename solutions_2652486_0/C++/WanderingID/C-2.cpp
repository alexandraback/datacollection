#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <utility>
#include <cstdlib>
#include <cassert>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define EPS 1e-9

using namespace std;

typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef unsigned long long ll;

ll cal(ll n, ll r)
{
    return 2*n*n-n+2*r*n;
}

ll min(ll a, ll b)
{
    return a<b?a:b;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C-output.txt","w",stdout);
    int T;
    vi prm(3);
    prm[0]=2;
    prm[1]=3;
    prm[2]=5;
    cin>>T;
    rep(tt,T)
    {
        printf("Case #%d:\n",tt+1);
        int r,n,m,k;
        cin>>r>>n>>m>>k;
        rep(rr,r)
        {
            vi p(k);
            rep(i,k)cin>>p[i];
            int ma=2,mb=3,mc=5;
            double pos=0;
            rer(a,2,5)
            {
                rer(b,2,5)
                {
                    rer(c,2,5)
                    {
                        vi tmp(4,0);
                        bool f=true;
                        rep(i,k)
                        {
                            if(p[i]==a*b||p[i]==b*c||p[i]==c*a)tmp[2]++;
                            else if(p[i]==a||p[i]==b||p[i]==c)tmp[1]++;
                            else if(p[i]==a*b*c)tmp[3]++;
                            else if(p[i]!=1)f=false;
                        }
                        if(f)
                        {
                            double pp=0;
                            pp+=pow(tmp[0]-1.0/8,2)+pow(tmp[1]-3.0/8,2)+pow(tmp[2]-3.0/8,2)+pow(tmp[3]-1.0/8,2);
                            pp+=0.0000001;
                            pp=1/pp;
                            if(pp>pos)
                            {
                                pos=pp;
                                ma=a;
                                mb=b;
                                mc=c;
                            }
                        }
                    }
                }
            }
            cout<<ma<<mb<<mc<<endl;
        }
    }
}
