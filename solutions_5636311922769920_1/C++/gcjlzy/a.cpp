#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e5+1;
int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        ll k,c,s,i,j,x=1;
        cin>>k>>c>>s;
        printf("Case #%d:",tt);
        if(k>c*s){printf(" IMPOSSIBLE\n");continue;}
        for(i=1;i<=c*(k/c+(k%c>0));i++)
        {
            x=(x-1)*k+i%(k+1)+i/(k+1);
            if(i%c==0)
            {
                printf(" %I64d",x);
                x=1;
            }
        }
        printf("\n");
    }
    return 0;
}
