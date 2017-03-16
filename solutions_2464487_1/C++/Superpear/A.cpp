#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int tt;
LL r,t;

bool ok(LL s)
{
    LL ct=(s-1)*4+1,rc;
    if (((t*2)/s)>=(ct+1))
    {
        rc=t-(ct+1)*s/2;
        if (rc/s>=2*r)
            return true;
    }
    return false;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    cin>>tt;
    for (int gb=1;gb<=tt;gb++)
    {
        cin>>r>>t;
        LL left=1,right=1000000000000000LL,mid;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (ok(mid)) left=mid+1; else right=mid-1;
        }
        cout<<"Case #"<<gb<<": "<<right<<endl;
    }

    return 0;
}
