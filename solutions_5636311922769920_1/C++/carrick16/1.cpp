
//**************************************************template*****************************************/
//#pragma comment(linker, "/STACK:16777216")
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll MOD=1000000007;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
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

ll ceill(ll a,ll b)
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



#define N 100005

int a[N];

int cas=0;
int main()
{ ll i,j,k,t,n,te,c,s;
    t=1;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
      freopen("2.txt","w",stdout);
    #endif
    sl(t)

    while(t--)
    {  cas++;
      sl(k)
      sl(c)
      sl(s)
      ll req=ceill(k,c);
     // trace1(req)
      if(req>s)
      {
          printf("Case #%d: IMPOSSIBLE\n",cas);
      }

      else
      {


       if(k<=s)
       {


       printf("Case #%d: ",cas);
       FOR(i,0,s)
       printf("%lld ",i+1);

       printf("\n");
       }
       else
       {
            printf("Case #%d: ",cas);

           ll need=0;
           FOR(i,1,req+1)
           {      need++;
                ll val=need;
               ll lev=1;
               while(lev<c)
               {  // trace1(need)
                   lev++;
                   if(need<k)
                   val=((val-1)*k)+need+1;
                   else
                    val=(val-1)*k+1;
                   need++;

                  // trace1(val)
               }


               printf("%lld ",val);

           }
            printf("\n");
       }
      }
    }



    return 0;
}
