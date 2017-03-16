#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <map>

using namespace std;

const double eps = 1e-9;
const int N=105;
char c[N][N];
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1; ca<=T; ++ca)
    {
        printf("Case #%d: ",ca);
        set<double>a,b;
        int n;
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            double dtmp;
            cin>>dtmp;
            a.insert(dtmp);
        }
        for(int i=0; i<n; ++i)
        {
            double dtmp;
            cin>>dtmp;
            b.insert(dtmp);
        }

        int k1=0,k2=0;
        set<double>v(b.begin(),b.end());
        for(set<double>::iterator it=a.begin();it!=a.end();++it)
        {
            set<double>::iterator ii=v.upper_bound(*it);
            if(ii==v.end())
            {
                ++k1;
                continue;
            }else
            {
                v.erase(ii);
            }

        }
        v.clear();
        v.insert(a.begin(),a.end());
        for(set<double>::iterator it=b.begin();it!=b.end();++it)
        {
            set<double>::iterator ii=v.upper_bound(*it);
            if(ii==v.end())
            {
                continue;
            }else
            {
                ++k2;
                v.erase(ii);
            }

        }
        cout<<k2<<" "<<k1<<endl;

    }
    return 0;
}
