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

int f[105][105];
int tt,E,R,N,c,v[10005],ec,cs,ans;

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    cin>>tt;
    for (int gb=1;gb<=tt;gb++)
    {
        cin>>E>>R>>N;
        for (int i=1;i<=N;i++) cin>>v[i];
        for (int i=0;i<=100;i++)
            for (int j=0;j<=100;j++)
                f[i][j]=-1;
        f[0][E]=0;
        for (int i=0;i<N;i++)
            for (int j=0;j<=E;j++)
                if (f[i][j]>=0)
                {
                    for (int k=0;k<=j;k++)
                    {
                        cs=min(j-k+R,E);
                        f[i+1][cs]=max(f[i+1][cs],f[i][j]+v[i+1]*k);
                    }
                }
        ans=0;
        for (int i=0;i<=E;i++) ans=max(ans,f[N][i]);
        cout<<"Case #"<<gb<<": "<<ans<<endl;
    }

    return 0;
}
