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
vc <str> cs[7],js[7];
void run(str a)
{
    int i,j,k,n=sz(a);
    str b="";
    for(i=0;i<n;i++)
    {
        if(a[i]!='?')
        {
            str temp;
            if(i!=0)
            {
                for(j=0;j<sz(cs[i-1]);j++)
                {
                    temp=cs[i-1][j];
                    temp+=a[i];
                    cs[i].pb(temp);
                }
            }
            else
            {
                temp="";
                temp+=a[i];
                cs[i].pb(temp);
            }
        }
        else
        {
            if(i!=0)
            {
                for(j=0;j<sz(cs[i-1]);j++)
                {
                    for(k=0;k<10;k++)
                    {
                        cs[i].pb(cs[i-1][j]+(char)(k+'0'));
                    }
                }
            }
            else
            {
                for(k=0;k<10;k++)
                {
                    str temp="";
                    temp+=(char)('0'+k);
                    cs[i].pb(temp);
                }
            }
        }
    }
}
void run2(str a)
{
    int i,j,k,n=sz(a);
    str b="";
    for(i=0;i<n;i++)
    {
        if(a[i]!='?')
        {
            str temp;
            if(i!=0)
            {
                for(j=0;j<sz(js[i-1]);j++)
                {
                    temp=js[i-1][j];
                    temp+=a[i];
                    js[i].pb(temp);
                }
            }
            else
            {
                temp="";
                temp+=a[i];
                js[i].pb(temp);
            }
        }
        else
        {
            if(i!=0)
            {
                for(j=0;j<sz(js[i-1]);j++)
                {
                    for(k=0;k<10;k++)
                    {
                        js[i].pb(js[i-1][j]+(char)(k+'0'));
                    }
                }
            }
            else
            {
                for(k=0;k<10;k++)
                {
                    str temp="";
                    temp+=(char)('0'+k);
                    js[i].pb(temp);
                }
            }
        }
    }
}
int main()
{
    input
    output
    int bzbz=1;
    tc
    {
        str c,j;
        int i;
        cin>>ws>>c;
        cin>>ws>>j;
        for(i=0;i<7;i++) cs[i].clear(),js[i].clear();
        run(c);
        run2(j);
        int loop1,loop2,loop3;
        int num1,num2,len=sz(c);
        int diff,mndiff=INT_MAX;
        int mncode=INT_MAX,mnocean=INT_MAX;
        for(loop1=0;loop1<sz(cs[len-1]);loop1++)
        {
            num1=0;
            for(i=0;i<len;i++) num1=num1*10+(cs[len-1][loop1][i]-'0');
            for(loop2=0;loop2<sz(js[len-1]);loop2++)
            {
                num2=0;
                for(i=0;i<len;i++) num2=num2*10+(js[len-1][loop2][i]-'0');
                diff=abs(num1-num2);
                if(mndiff>diff)
                {
                    mndiff=diff;
                    mncode=num1;
                    mnocean=num2;
                }
                else if(mndiff==diff)
                {
                    if(mncode>num1)
                    {
                        mncode=num1;
                        mnocean=num2;
                    }
                    else if(mncode==num1)
                    {
                        if(mnocean>num2)
                        {
                            mnocean=num2;
                        }
                    }
                }
            }
        }
        pr("Case #%d: ",bzbz++);
        int aka=log10(mncode)+1;
        if(mncode==0)
        {
            for(i=0;i<sz(c);i++) pr("0");
            pr(" ");
        }
        else if(aka==sz(c)) pr("%d ",mncode);
        else if(aka==sz(c)-1) pr("0%d ",mncode);
        else if(aka==sz(c)-2) pr("00%d ",mncode);
        else if(aka==sz(c)-3) pr("000%d ",mncode);
        aka=log10(mnocean)+1;
        if(mnocean==0)
        {
            for(i=0;i<sz(c);i++) pr("0");
            pr("\n");
        }
        else if(aka==sz(j)) pr("%d\n",mnocean);
        else if(aka==sz(j)-1) pr("0%d\n",mnocean);
        else if(aka==sz(j)-2) pr("00%d\n",mnocean);
        else if(aka==sz(j)-3) pr("000%d\n",mnocean);
    }
    ret 0;
}
