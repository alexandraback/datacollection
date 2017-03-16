#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;
const double INF=1e9;
const double eps=1e-6;
const double PI=acos(-1.0);
const int N=305;

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    cin>>T;
    for(int w=1;w<=T;++w)
    {
        int n,t;
        cin>>n>>t;
        int l=n,r=l+1;
        int sum=0;
        while(r*r-l*l<=t)
        {
            ++sum;
            t=t-(r*r-l*l);
            l+=2;
            r+=2;
        }
        printf("Case #%d: %d\n",w,sum);
    }
    return 0;
}
