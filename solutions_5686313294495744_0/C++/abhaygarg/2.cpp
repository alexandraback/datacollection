#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define all(v) v.begin(),v.end()
#define inf 1000000000
string fname[101],sname[1011];
map<string,int>myf,mys;
int main()
{
    freopen("2.in","r",stdin);
    freopen("2-out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,c,ans=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            cin>>fname[i]>>sname[i];
        for(i=0; i<(1<<n); i++)
        {
            myf.clear();
            mys.clear();
            c=0;
            for(j=0; j<n; j++)
            {
                if((i>>j)&1)
                {
                    c++;
                    myf[fname[j]]=1;
                    mys[sname[j]]=1;
                }
            }
            for(j=0;j<n;j++)
            {
                if((i>>j)&1)
                    continue;
                if(myf[fname[j]]!=1||mys[sname[j]]!=1)
                    break;
            }
            if(j==n)
                ans=max(ans,n-c);
        }
        printf("Case #%d: %d\n",cs,ans);
        cs++;
    }
    return 0;
}

