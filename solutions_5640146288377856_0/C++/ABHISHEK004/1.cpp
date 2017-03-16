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
    long long int mod;
    mod=1000000007;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    ty=(temp%mod)*(temp%mod);
    if (y%2 == 0)
        {

                return ty%mod;
        }
    else
        {
                my=(x%mod)*(ty%mod);
                return my%mod;
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
//int b[100000];
vector< pair<int,int> > abhi;


int main()
{

        freopen("C:\\Users\\ABHISHEK004\\Desktop\\aa.in","r",stdin);
        freopen("C:\\Users\\ABHISHEK004\\Desktop\\ab.out","w",stdout);
        ll t,m,i,n,r,c,w,j,k=0,p,kk=0;
        cin>>t;
        while(t--)
        {
            kk++;

            cin>>r>>c>>w;
            ll ans=0;

            k=c/w;
            if(c%w==0)
                ans=k+w-1;
            else
                ans=k+w;



            cout<<"Case #"<<kk<<": "<<ans<<"\n";
        }

        return 0;
}



