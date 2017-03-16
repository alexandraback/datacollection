#include<bits/stdc++.h>
#define scf scanf
#define ptf printf
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define scd second
#define m_p make_pair
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

char str[1000];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,sum,ans,n;
    scf("%d",&T);
    forp(tcnt,0,T)
    {
        sum=ans=0;
        scf("%d%s",&n,str);
        forp(i,0,n+1)
        {
            if(sum<i)
            {
                ans+=i-sum;
                sum=i;
            }
            sum+=str[i]-'0';
        }
        ptf("Case #%d: %d\n",tcnt+1,ans);
    }

    return 0;
}
