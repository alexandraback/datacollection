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
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        ll k,c,s,i,j;
        cin>>k>>c>>s;
        printf("Case #%d:",tt);
        for(i=0;i<s;i++)
        {
            ll x=i+1;
            for(j=1;j<c;j++)x=(x-1)*k+i+1;
            printf(" %I64d",x);
        }
        printf("\n");
    }
    return 0;
}
