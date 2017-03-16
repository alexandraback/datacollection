#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#define DBLE 1e-8
#define PI 3.1415926535898
#define INF (1000000000000000000LL)
#define MAXN 1010
#define MP(x,y) (make_pair((x),(y)))
#define FI first
#define SE second
using namespace std;
int main()
{
    //freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);
    //freopen("J:\\MyDocument\\Code\\output.txt","w",stdout);
    int ncase;
    long long ans,l,rr,mid;
    double t,r;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        cin>>r>>t;
        rr=INF,l=0;
        while(l<rr)
        {
            mid=(l+rr+1)/2;
            if((2*r-1+2*mid)*mid<t+DBLE)
                l=mid;
            else    rr=mid-1;
        }
        printf("Case #%d: ",h);
        cout<<l<<'\n';
    }
    return 0;
}

