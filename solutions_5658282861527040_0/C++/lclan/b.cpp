#include <bits/stdc++.h>
#define mpr std::make_pair
typedef long long ll;
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int main()
{
    freopen("out.txt","w",stdout);
    int i,j,k;
    int t,r;
    int n,a,b;
    r=1;
    bool f;
    cin>>t;
    int ans;
    while(t--)
    {
        ans=0;
        cin>>a>>b>>n;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i&j ) <n)
                {
                    ans++;
                }
            }
        }
        cout<<"Case #"<<r<<": ";
        r++;
        cout<<ans<<endl;
    }
}
