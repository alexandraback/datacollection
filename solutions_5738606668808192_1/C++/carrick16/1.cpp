
//**************************************************template*****************************************/
//#pragma comment(linker, "/STACK:16777216")
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll MOD=1000000007;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define pl(x)                   printf("%lld\n",x);
#define pi 3.14159265358979323846  //float type
#define MAX 100000  //for rmq
#define SQRTMAX 317   //for rmq
//#define gc getchar_unlocked
#define INF                 999999999999999999

/*#define swap(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

inline int r()
{
    int n=0;
    char c=gc();
    while(c<'0'||c>'9')c=gc();
    while(c>='0'&&c<='9')
    {
        n=n*10+c-'0';
        c=gc();
    }
    return n;
}

 inline void write(ll x){

         register char buffor[35];
         register int i=0;
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
            while(i>=0) putchar_unlocked(buffor[i--]);
            putchar_unlocked('\n');
       }
       */
#define 	SZ(A) 		((int)A.size())
#define 	LEN(A) 		((int)A.length())
#define 	MS(A) 		memset(A, 0, sizeof(A))
#define 	MSV(A,a) 	memset(A, a, sizeof(A))
#define 	mp(x,y)		make_pair((x),(y))
#define 	pb(x) 		push_back(x)
#define		F 			first
#define 	S 			second

#define 	EPS 		1e-12

#define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
#define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;



#define 	chkbit(s, b) 	(s & (1<<b))
#define 	setbit(s, b) 	(s |= (1<<b))
#define 	clrbit(s, b) 	(s &= ~(1<<b))

//#define 	swap(x,y)  		{x=x+y-(y=x);}
#define 	FOUND(A, x) 	(A.find(x) != A.end())





 ll power(ll a, ll b, ll m) {
    ll r = 1;
    while(b) {
        if(b & 1) r = r * a % m;
        a = (a * a)% m;
        b >>= 1;
    }
    return r;
}
 ll power(ll a, ll b) {
     ll r = 1;
    while(b) {
        if(b & 1) r = r * a ;
        a = a * a;
        b >>= 1;
    }
    return r;
}

ll gcd(ll a,ll b){
      return b==0?a:gcd(b,a%b);
}
 //......long long int
ll lcm(ll a,ll b){
      return (a/gcd(a,b))*b;
}
 //......long long int with mod
ll modularInverse(ll a,ll m){
      return power(a,m-2,m);


}

int ceill(int a,int b)
{
    return ((a+b-1)/b);
}

 int mini(int a,int b) { return a<b? a : b; }
 int maxi(int a,int b) { return a>b? a : b; }


typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;


/*........................................................END OF TEMPLATES...................................................................
....*/



#define N 32

ll ans[N+1];
char str[40];

void convert(ll val)
{
  ll ne=val;
  str[32]='\0';
  int l=31;
  while(ne)
  {
    str[l--]=(ne%10)+48;
    ne=ne/10;
  }
  str[l+1]=48;


  str[0]=49;
  while(l>0)
  str[l--]=48;
}

ll check(ll value)
{
    ll sq=sqrt(value);
    ll i;
    for(i=3;i<=sq;i++)
    {
        if(value%i ==0)
        {
            return i;
        }
    }

    return -1;
}

int cas=0;
int main()
{ ll i,j,k,t,n,te;
    t=1;
  //  #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
      freopen("2.txt","w",stdout);
   // #endif
    sl(t)

    while(t--)
    {  cas++;

       printf("Case #%d:\n",cas);
       sl(n)
       sl(k)

      // pow[0]=1;
       int co=0;
       FOR(i,0,1<<n-2)
       {   //pl(i)
           trace1(co)
           //trace1()
            int flag=0;
            if(co==k)
                break;
                ll val;
            FOR(j,2,11)
          { ll mul=1;
            val=1;

           FOR(num,0,n-2)
           {   mul=mul*j;
               if(i&(1<<num))
               {
                   val=val+mul;
               }
           }
           mul=mul*j;
           val=val+mul;

           ll v=check(val);
           if(v==-1)
           {
               flag=1;
           }
           else
           {
               ans[j]=v;
           }

           if(flag==1)
            break;

          }
          if(flag==0)
          {
           co++;

          //trace1(val)
          convert(val);
          printf("%s ",str);
          //pl(val)
          FOR(ji,2,11)
          {
              printf("%lld ",ans[ji]);
          }
          printf("\n");
          }

       }
    }



    return 0;
}
