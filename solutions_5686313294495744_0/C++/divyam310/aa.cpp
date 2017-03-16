#include<bits/stdc++.h>
using namespace std;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d %d",&x,&y);
#define slld(x) scanf("%lld",&x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007




string a,b;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);freopen("output.txt","w",stdout);

    int t;
    sd(t);
    for(int q=0;q<t;q++)
    {
        map<string,int> m,w;
        vector<string>x,y;
        int n;
        sd(n);

        for(int i=0;i<n;i++)
        {
            cin>>a;
            cin>>b;
            if(m.find(a)!=m.end())
            {
                m[a]++;
            }
            else
                m[a]=1;

            if(w.find(b)!=w.end())
            {
                w[b]++;
            }
            else
                w[b]=1;

            x.pb(a);
            y.pb(b);

        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(m[x[i]]==1||w[y[i]]==1)
                ans++;

        }
        printf("Case #%d: %d\n",q+1,n-ans);










    }





}



