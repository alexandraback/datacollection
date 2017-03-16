#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int t,a,n,l[105],ans;
int main()
{
    freopen("in1","r",stdin);
    freopen("out1","w",stdout);
    scanf("%d",&t);
    for(int I=1;I<=t;++I)
    {
        scanf("%d%d",&a,&n);
        for(int i=0;i<n;++i) scanf("%d",&l[i]);
        sort(l,l+n); ans=n;
        for(int i=0;i<=n&&a>1;++i)
        {
            int c=0,s=a;
            for(int j=0;j<n-i;++j)
            {
                while(s<=l[j]) {++c; s+=s-1;}
                s+=l[j];
            }
            ans=min(ans,c+i);
        }
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
