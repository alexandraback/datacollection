#include<iostream>
#include<cstdio>
using namespace std;

#define ll long long
#define inf 1<<30
#define Mod 10000007
#define dbg printf("%c",a);
#define sz(a) (a).size()
int n,m;int ans;
int coin[10],sum;
int main()
{
    int i,j,k,T,cs=0;
    freopen("C-small-attempt1.in","r",stdin);
    freopen("cout.txt","w",stdout);
    cin>>T;
    //while(scanf("%d",&n)==1)
    while(T--)
    {
        int c,d,v;
        cin>>c>>d>>v;
        for(i=1;i<=d;i++)
        {
            cin>>coin[i];
        }
        sum=0;j=1;ans=0;
        for(i=1;i<=v;i++)
        {
            if(sum>=i);
            else
            {
                if(i<coin[j])
                {
                    ans++;
                    sum+=sum+1;
                }
                else sum+=coin[j++];
            }
        }
        printf("Case #%d: %d\n",++cs,ans);
    }

    return 0;
}

