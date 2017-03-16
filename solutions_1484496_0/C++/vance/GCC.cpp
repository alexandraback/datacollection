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
map<int,int>vst,hs;
int main()
{
    int t;
    int n,i,in[1000],sum,j;
    freopen("gcc.in","r",stdin);
    freopen("gcc.out","w",stdout);
    scanf("%d",&t);
    for(int cn=1;cn<=t;cn++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",in+i);
        sum=0;
        int ts;
        vst.clear();
        for(i=0;i<n;i++)
            sum+=in[i];
        for(i=0;i<(1<<n);i++)
        {
            ts=0;
            for(j=0;j<n;j++)if(i&(1<<j))
                ts+=in[j];
            if(!vst[ts])
            {
                vst[ts]=1;
                hs[ts]=i;
            }
            else
                break;
        }
        //printf("%d %d %d\n",ts,i,hs[ts]);
        printf("Case #%d:\n",cn);
        if(i==(1<<n))
            printf("Impossible\n");
        else
        {
            VI ud,nd;
            for(j=0;j<n;j++)if(i&(1<<j))
                ud.PB(in[j]);
            i=hs[ts];
            for(j=0;j<n;j++)if(i&(1<<j))
                nd.PB(in[j]);
            for(i=0;i<ud.size();i++)
                if(i==ud.size()-1)
                    printf("%d\n",ud[i]);
                else
                    printf("%d ",ud[i]);
            for(i=0;i<nd.size();i++)
                if(i==nd.size()-1)
                    printf("%d\n",nd[i]);
                else
                    printf("%d ",nd[i]);
        }
    }
    return 0;
}
