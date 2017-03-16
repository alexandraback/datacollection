#include<bits/stdc++.h>
#define pb push_back
#define tr(c,i) for(typeof((c).begin() )i = (c).begin(); i != (c).end(); i++)
#define mod 1000000007
#define ii  pair<int,int>

using namespace std;
typedef long long ll;



using namespace std;
/*struct node
{
    ll nm,tm;
}nd[2000010];

int cmp(const void *a,const void *b)
{
    node *va=(node *)a;
    node *vb=(node *)b;
    if(va->tm==vb->tm)
    {
        if(va->nm<vb->nm)
        return -1;
        else
        return 1;
    }
    else
    {
        if(va->nm<vb->nm)
        return -1;
        else
        return 1;
    }
    if(va->tm==vb->tm)
    return va->nm-vb->nm;
    else
    return va->tm-vb->tm;
}*/

/*ll g(ll a,ll b)
{
    if(b==0)
    return a;
    else
    return g(b,a%b);
}
ll lc(int a,int b)
{
    ll lcm=(a*b)/g(a,b);
    return lcm;
}*/


int main()
{
  int t,tst,i,j,k,n,m,r,c,w,hf,ans;

freopen("A-small-attempt2.in", "r", stdin);
freopen("xxxxOUT-small-attempt2.txt", "w", stdout);
scanf("%d",&t);
for(tst=1;tst<=t;tst++)
{
    scanf("%d%d%d",&r,&c,&w);
    if(c%2==0)
    hf=c/2;
    else
    hf=c/2+1;
    if(c==w)
    ans=w;
    else if(w>=hf)
    ans=w+1;
    else
    {
        j=c/w;
        ans=j-1;
        if(c%w!=0)
        ans++;
        ans+=w;
    }





     printf("Case #%d: %d\n",tst,ans);


}



    return 0;
}
