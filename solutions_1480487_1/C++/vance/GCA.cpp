#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define eps 1e-10
int main()
{
    int t,n,i;
    int in[1000],vst[1000],m;
    double out[1000],sum,r;
    freopen("gcal.in","r",stdin);
    freopen("gca.out","w",stdout);
    scanf("%d",&t);
    for(int cn=1;cn<=t;cn++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",in+i);
        sum = 0;r=0;
        for(i=0;i<n;i++)
            sum+=in[i];
        memset(vst,0,sizeof(vst));
        m=0;
        for(i=0;i<n;i++)
            if(in[i]-sum*2/n>eps)
            {
                vst[i]=1;
                out[i]=0.0;
                m++;
                r+=in[i];
            }
        for(i=0;i<n;i++)if(!vst[i])
        {
            out[i]=max(((sum*2-r)/(n-m)-in[i])/sum*100,0.0);
        }
        printf("Case #%d: ",cn);
        for(i=0;i<n;i++)
            if(i==n-1)
                printf("%f\n",out[i]);
            else
                printf("%f ",out[i]);
    }
    return 0;
}
