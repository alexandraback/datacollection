#include<bits/stdc++.h>
#define mx 1000005
#define pb push_back
#define ll long long
using namespace std;
ll rev(ll x)
{
    vector<ll>a;
    while(x!=0)
    {
        a.pb(x%10);
        x=x/10;
    }
    ll xx=0;
    for(int i=0;i<a.size();i++)
    {
        xx=(xx*10)+a[i];
    }
    return xx;
}
struct node
{
  ll no;
  ll l;
  node(ll i,ll j)
  {
      no=i;l=j;
  }

};
bool taken[mx];
int main()
{
    //printf("%lld\n",rev(2301));return 0;
freopen("A-small-attempt1.in","r",stdin);

freopen("out1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
    ll n;
    scanf("%lld",&n);
    //ll c=1;
    ll st=1;

    queue<node>q;
    q.push(node(1,1));
    memset(taken,0,sizeof taken);
    taken[1]=1;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        if(u.no>mx)continue;
        if(u.no==n){st=u.l;break;}
        else
        {
if(taken[u.no+1]==0){
    taken[u.no+1]=1;
            q.push(node(u.no+1,u.l+1));
}
if(taken[rev(u.no)]==0){
taken[rev(u.no)]=1;
            q.push(node(rev(u.no),u.l+1));}


        }


    }

    //ll c=ans.size();
   // if(n==1)c--;
    printf("Case #%d: %lld\n",cas,st);
    }

}
