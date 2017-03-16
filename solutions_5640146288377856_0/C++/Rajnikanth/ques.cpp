#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<iomanip>
#include<queue>
#include<map>
#define fl(i,s,n) for(i=s;i<n;i++)
#define flr(i,s,n) for(i=s;i>n;i--)
#define ls(i,s) for(i=0;s[i]!='\0';i++)
#define gi(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define checkline(x) while(x!='\0' && x!='\n')
#define pn printf('\n')
#define ps printf(' ')
#define f_in freopen("input.txt","r",stdin)
#define f_out freopen("output.txt","w",stdout)
#define in(i,j,k) ((j<=i) && (i<k))
#define ull unsigned long long int
#define lli long long int
#define ceil(x,n) (x+n-1)/n
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
int main()
{
    f_in;
    f_out;
    lli t,i,c,r,w,ans,z,q;
    cin>>t;
    fl(i,1,t+1)
    {
        cout<<"Case #"<<i<<": ";
        cin>>r>>c>>w;
        if(w==c)
            {
                cout<<w<<endl;
                continue;
            }
        if(w>(c/2))
        {
            cout<<w+1<<endl;
            continue;
        }
        z = c/w;
        q = c%w;
        if(q==0)
            cout<<z+w-1<<endl;
        else
            cout<<z+w<<endl;
    }
    return 0;
}
