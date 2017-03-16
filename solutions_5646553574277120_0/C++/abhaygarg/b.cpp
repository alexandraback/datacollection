#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define mod 1000000007LL
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int c=1,i,j,k,l,n,m,t,ans,r,c1,w,d,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&c1,&d,&v);
        set<int>s;
        for(i=0;i<d;i++)
        {
            scanf("%d",&j);
            s.insert(j);
        }
        int n=0;
        ans=0;
        set<int>::iterator it=s.begin();
        //printf("fsfsf");
        while(it!=s.end())
        {
            if(n+1<(*it))
            {
                ans++;
                n=n+n+1;
            }
            else
                {n=n+(*it);
            it++;}
            //printf("%d %d\n",n,ans);
        }
        if(n>=v)
            printf("Case #%d: %d\n",c,ans);
        else
        {
            while(n<v)
            {
                n=n+n+1;
                ans++;
            }
            printf("Case #%d: %d\n",c,ans);
        }
        c++;
    }
    return 0;
}

