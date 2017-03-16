/**
                                                ooooooo
                                                o         ooooooo   ooooooo   o ooooo  ooooooo
                                                ooooooo    oooooo    oooooo    o    o  o
                                                      o    o    o    o    o    o    o  o
                                                ooooooo    ooooooo   ooooooo   o    o  ooooooo
*/

#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define loop3(i,n,k) for(i=n;i<=k;i++)
#define loopr(i,n,k) for(i=n;i>=k;i--)
#define pvn(n) cout<<n<<"\n"
#define pvw(n) cout<<n<<" "
#define pvpn(n,x) cout<< std::fixed;cout<< std::setprecision(x)<<n<<"\n"
#define pvpw(n,x) cout<< std::fixed;cout<< std::setprecision(x)<<n<<" "
#define pw cout<<" "
#define pn cout<<"\n"
#define TZ(n) __builtin_ctz(n)
#define LZ(n) __builtin_clz(n)
#define CSB(n) __builtin_popcount(n)

#define MAX 1000000007
#define pi  3.1415926535
#define exp  2.7182818284

typedef long long int LL;
typedef long int L;
typedef double D;
typedef unsigned long long int ULL;
typedef vector<LL> VLL;
typedef vector<L> VL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<float> VF;
typedef vector<double> VD;
typedef pair<LL,LL> PLL;

const LL INF=1000000000;
LL dp[1000001];
LL revers(LL n)
{
    LL k=0;
    while(n>0)
    {
        k=k*10+(n%10);
        n=n/10;
    }
    return k;
}
//LL cal(LL n)
//{
//    if(n<=0)
//        return INT_MAX;
//    if(n>=1&&n<=12)
//        return n;
//    if(dp[n]==-1)
//    {
//        LL i,j=INT_MAX,k=revers(n);
//        i=cal(n-1);
//        if((n%10!=0)&&k<n)
//        {
//            j=cal(k);
//        }
//         dp[n]=min(i,j)+1;
//         return dp[n];
//    }
//    else
//        return dp[n];
//}
int main()
{
    std::ios::sync_with_stdio(false);
    LL i,j,t,l=0,n,m,x;
    cin>>t;
    while(t--)
    {
        l++;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        dp[1]=1;
        for(i=2;i<=n;i++)
        {
            if(revers(i)<i&&(i%10!=0))
            {
                dp[i]=min(dp[i-1],dp[revers(i)])+1;
            }
            else
                dp[i]=dp[i-1]+1;
        }
        cout<<"Case #"<<l<<": ";
        pvn(dp[n]);
    }
    return 0;
}
