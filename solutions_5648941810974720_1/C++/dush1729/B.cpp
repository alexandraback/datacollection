#include<bits/stdc++.h>
using namespace std;
int yt=1;           //test variable
bool qf=false;      //fast io enabled/disabled

#define input       freopen("in.txt","r",stdin);
#define output      freopen("out.txt","w",stdout);
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);qf=true;

#define sc          scanf
#define pr          printf
#define whi         while
#define ll          long long
#define ull         unsigned long long
#define lld         I64d
#define mp          make_pair
#define ff          first
#define ss          second
#define vc          vector
#define pb          push_back
#define ite         iterator
#define str         string
#define bl          bool
#define tr          true
#define fl          false

#define endl        '\n'
#define ret         return
#define rsort       greater<int>()
#define nl          if(qf==tr) pr("\n");else cout<<"\n";
#define test        if(qf==tr) pr("TEST %d\n",yt++);else cout<<"TEST "<<yt++<<"\n";
#define gcd(a,b)    __gcd(a,b)
#define mod         1000000007

#define all(c)      c.begin(),c.end()
#define sz(c)       c.size()
#define clr(c)      c.clear()
#define fd(c,a)     c.find(a)
#define bg(c)       c.begin()
#define ed(c)       c.end()
#define ins(c,a)    c.insert(a)
#define rem(c,a)    c.erase(a)

#define si(n)       if(qf==fl) sc("%d",&n); else cin>>n;
#define sll(n)      if(qf==fl) sc("%lld",&n); else cin>>n;
#define pi(n)       if(qf==fl) pr("%d ",n); else cout<<n<<" ";
#define pll(n)      if(qf==fl) pr("%lld ",n); else cout<<n<<" ";

#define tc          int t;if(qf==fl) si(t) else cin>>t;whi(t--)
#define ct          continue;
#define debug       system("PAUSE");
int main()
{
    input
    output
    int bzbz=1;
    tc
    {
        str z;
        cin>>ws>>z;
        int i,j,n=sz(z);
        int a[28]={};
        for(i=0;i<n;i++) a[z[i]-'A']++;
        int ans[12]={};
        if(a['Z'-'A']>0) //ZERO(Z)
        {
            a['E'-'A']-=a['Z'-'A'];
            a['R'-'A']-=a['Z'-'A'];
            a['O'-'A']-=a['Z'-'A'];
            ans[0]=a['Z'-'A'];
            a['Z'-'A']=0;
        }
        if(a['X'-'A']>0) //SIX(X)
        {
            a['S'-'A']-=a['X'-'A'];
            a['I'-'A']-=a['X'-'A'];
            ans[6]=a['X'-'A'];
            a['X'-'A']=0;
        }
        if(a['G'-'A']>0) //EIGHT(G)
        {
            a['E'-'A']-=a['G'-'A'];
            a['I'-'A']-=a['G'-'A'];
            a['H'-'A']-=a['G'-'A'];
            a['T'-'A']-=a['G'-'A'];
            ans[8]=a['G'-'A'];
            a['G'-'A']=0;
        }
        if(a['U'-'A']>0) //FOUR(U)
        {
            a['F'-'A']-=a['U'-'A'];
            a['O'-'A']-=a['U'-'A'];
            a['R'-'A']-=a['U'-'A'];
            ans[4]=a['U'-'A'];
            a['U'-'A']=0;
        }
        if(a['W'-'A']>0) //TWO(W)
        {
            a['T'-'A']-=a['W'-'A'];
            a['O'-'A']-=a['W'-'A'];
            ans[2]=a['W'-'A'];
            a['W'-'A']=0;
        }
        if(a['O'-'A']>0) //ONE(O)
        {
            a['N'-'A']-=a['O'-'A'];
            a['E'-'A']-=a['O'-'A'];
            ans[1]=a['O'-'A'];
            a['O'-'A']=0;
        }
        if(a['R'-'A']>0) //THREE(R)
        {
            a['T'-'A']-=a['R'-'A'];
            a['H'-'A']-=a['R'-'A'];
            a['E'-'A']-=a['R'-'A'];
            a['E'-'A']-=a['R'-'A'];
            ans[3]=a['R'-'A'];
            a['R'-'A']=0;
        }
        if(a['F'-'A']>0) //FIVE(F)
        {
            a['I'-'A']-=a['F'-'A'];
            a['V'-'A']-=a['F'-'A'];
            a['E'-'A']-=a['F'-'A'];
            ans[5]=a['F'-'A'];
            a['F'-'A']=0;
        }
        if(a['S'-'A']>0) //SEVEN(S)
        {
            a['E'-'A']-=a['S'-'A'];
            a['V'-'A']-=a['S'-'A'];
            a['E'-'A']-=a['S'-'A'];
            a['N'-'A']-=a['S'-'A'];
            ans[7]=a['S'-'A'];
            a['S'-'A']=0;
        }
        ans[9]=a['I'-'A']; //NINE(I)
        pr("Case #%d: ",bzbz++);
        for(i=0;i<10;i++)
        {
            for(j=0;j<ans[i];j++) pr("%d",i);
        }
        nl
    }
    ret 0;
}
