#include<bits/stdc++.h>
#define set(p) memset(p,-1,sizeof(p))
#define clr(p) memset(p,0,sizeof(p))
#define ll long long int
#define llu unsigned long long int
#define si(n)					scanf("%d",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n)                                   scanf("%s",n)
#define rep(i,a,n) for(i=(a);i<(n);i++)
#define pii pair<int,int>
#define pb(x) push_back(x)
#define v(x) vector<x>
using namespace std;

int gcd(int a,int b)
{
 int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}


long long int power(long long int x,long long int y)
{
    long long int temp,ty,my;
    //long long int mod;
    //mod=1000000007;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    ty=(temp)*(temp);
    if (y%2 == 0)
        {

                return ty;
        }
    else
        {
                my=(x)*(ty);
                return my;
        }
}



long long int mini(long long int a,long long int b)
{
        return a<b?a:b;
}



struct abhi
{
       ll val;
       ll pos;
};

struct abhi brr[100010];

bool cmp(struct abhi x,struct abhi y)
{
        return x.pos<y.pos;
}

char ss[100010];
ll a[100100];
ll b[100100];
ll exi[1000100];
ll exi_cp[1000100];
ll r2[1000100];
ll rem[1000100];
//int b[100000];
vector< pair<int,int> > abhi;


int main()
{

        freopen("C:\\Users\\ABHISHEK004\\Desktop\\a1.in","r",stdin);
        freopen("C:\\Users\\ABHISHEK004\\Desktop\\ab.out","w",stdout);
        ll t,m,i,n,d,v,r,c,w,j,k=0,p,kk=0;
        cin>>t;
        while(t--)
        {
            kk++;

            cin>>c>>d>>v;
            rep(i,0,d)
            {
                cin>>a[i];
            }
            ll ans=0;

            k=power(2,d);

            rep(i,0,v+1)
            exi[i]=0;

            rep(i,0,k)
            {
                b[i]=0;

                for(j=0;j<d;j++)
                {
                    if(i&(1<<j))
                    {
                        b[i]=b[i]+a[j];
                    }
                }
                exi[b[i]]=1;
            }

            ll fg=0;

            rep(i,0,v+1)
            rem[i]=0;

            rep(i,0,v+1)
            {
                if(exi[i]==0)
                {
                    fg=1;
                    rem[i]=1;
                }
            }

            ans=0;

            if(fg==0)
                ans=0;
            else
            {
                while(1){
                ans++;
                ll cn=0;
                ll mk;
                rep(i,0,v+1)
                {
                    if(rem[i]==1 && cn<1)
                    {

                        //cout<<i<<" rem\n";
                        cn++;
                        rem[i]=2;
                        mk=i;
                    }
                }

                rep(i,0,v+1)
                {
                    exi_cp[i]=0;
                }


                rep(i,0,v+1)
                {
                    if(exi[i]==1)
                    {
                        exi_cp[i+mk]=1;
                        //cout<<i+mk<<" i+k mark\n";
                    }
                }

                rep(i,0,v+1)
                {
                    if(exi_cp[i]==1)
                        exi[i]=1;
                }
                ll ff=0;
                rem[mk]=0;
                exi[0]=1;
                rep(i,0,v+1)
                {
                    if(exi[i]==1)
                        {
                            rem[i]=0;
                            //cout<<i<<" fina\n";
                        }
                    else
                    {
                        ff=1;
                        rem[i]=1;
                    }
                }

                if(ff==0)
                    break;

                }

            }


            cout<<"Case #"<<kk<<": "<<ans<<"\n";
        }

        return 0;
}



