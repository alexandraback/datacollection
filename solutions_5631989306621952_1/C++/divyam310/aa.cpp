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

string a;
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i,j;
    sd(t);
    for(int q=1;q<=t;q++)
    {
        cin>>a;
        int n=a.size();
        string b="";
        b+=a[0];
        int k=0;
        for(i=1;i<n;i++)
        {
            if(a[i]<b[0])
            {
                b+=a[i];
            }
            else
            {
                char x=b[i-1];
                for(int j=i+1;j>0;j--)
                {
                    b[j]=b[j-1];
                }
                b[0]=a[i];
                b+=x;
            }
            //cout<<b<<endl;
        }
        printf("Case #%d: ",q);
        cout<<b<<endl;
    }
}


