#include <iostream>
#include <cstdio>
#include<string.h>
#include<string>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1000000000+7;
double eps=1e-9;
const int inf=0x3f3f3f3f;
const int maxn=100+10;
const int maxm=2000000+10;
int numA[15],numB[15],numK[15];
ll A,B,K;
ll _pow(int a,int x)
{
    ll ans=1;
    while(x)
    {
        if(x%2==1) ans=ans*a;
        a=a*a;
        x/=2;
    }
    return ans;
}
ll f(int pos,bool limit1,bool limit2,bool limit3)
{
    if(pos==-1)
    {
        if(limit1||limit2||limit3) return 0;
        return 1;
    }
    ll ans=0;
    if(!limit1&&!limit2&&!limit3) return _pow(4,pos+1);
    //dang K xuan 0
    ans+=f(pos-1,limit1&&numK[pos]==0,limit2&&numA[pos]==0,limit3&&numB[pos]==0);
    if(!limit2||(limit2&&numA[pos]==1))
    {
        ans+=f(pos-1,limit1&&numK[pos]==0,limit2&&numA[pos]==1,limit3&&numB[pos]==0);
    }
    if(!limit3||(limit3&&numB[pos]==1))
    {
          ans+=f(pos-1,limit1&&numK[pos]==0,limit2&&numA[pos]==0,limit3&&numB[pos]==1);
    }
    //dang K xuan 1
    if(!limit1||(limit1&&numK[pos]==1))
    {
        if((!limit2||(limit2&&numA[pos]==1))&&(!limit3||(limit3&&numB[pos]==1)))
        {
            ans+=f(pos-1,limit1&&numK[pos]==1,limit2&&numA[pos]==1,limit3&&numB[pos]==1);
        }
    }
    return ans;

}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        tcase++;
        printf("Case #%d: ",tcase);
        scanf("%lld%lld%lld",&A,&B,&K);
        int pos=0;
        for(int i=0;i<32;i++)
        {
            if(A==0&&B==0&&K==0)
            {
                pos=i-1;
                break;
            }
            numA[i]=A%2;
            numB[i]=B%2;
            numK[i]=K%2;
            A/=2;
            B/=2;
            K/=2;

        }
        ll ans=f(pos,1,1,1);
        printf("%lld\n",ans);
    }
    return 0;
}
