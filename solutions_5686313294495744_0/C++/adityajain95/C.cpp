#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;

pair< string,string  > tp[1005];
string s,c;
set<string> fs,sc;

int main()
{
    freopen("3.in","r",stdin);
    freopen("C-out.txt","w",stdout);
    int tt,t,j,n,m,i,ans;
    cin>>tt;
    for(t=1;t<=tt;t++)
    {
        cin>>n;
        ans=0;
        for(i=0;i<n;i++)
        {
            cin>>s>>c;
            tp[i].f=s;
            tp[i].s=c;
        }
        for(i=1;i<(1<<n);i++)
        {
            fs.clear();
            sc.clear();
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    fs.insert(tp[j].f);
                    sc.insert(tp[j].s);
                }
            }
            bool ok=true;
            int cnt=0;
            for(j=0;j<n;j++)
            {
                if(i&(1<<j));
                else
                {
                    cnt++;
                    if(fs.find(tp[j].f)==fs.end()  ||  sc.find(tp[j].s)==sc.end())
                    {
                        ok=false;
                        break;
                    }
                }
            }
            if(ok)
            {
                //printf("%d %d\n",i,cnt);
                ans=max(ans,cnt);
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
    return 0;
}


