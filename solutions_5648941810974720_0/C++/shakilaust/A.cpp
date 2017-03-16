//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.
 Don't let your dreams be dreams.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::

*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("1.txt", "r", stdin)
#define FO freopen ("2.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

string number[] = { "ZERO", "TWO" , "FOUR" , "SIX" , "EIGHT" , "ONE", "THREE", "FIVE",  "SEVEN",  "NINE"};
int seq[] { 0 , 2 , 4 , 6 , 8 , 1 , 3 , 5 , 7 , 9 };
string input;
vector < int > ans ;
int has[ 30 ];

int main()
{
   // I will always use scanf and printf
    FI;
    FO;
   int cs , t = II ;
   for( cs = 1 ; cs <= t ; cs++ )
   {
       ans.clear();

       ms( has , 0 );
       cin >> input ;
       int sz = input.size();
      // printf("sz :: %d\n",sz);
       rep( i , sz ) has[input[i]-'A']++;
       int notun = 1 ;
       int freq[30] = {0};
        printf("Case #%d: ",cs);
        int f = 1 ;
       for( int i = 0 ; i <= 9 ; )
       {

           int nsz = number[i].size();
           if( notun == 1 )
           rep( j , nsz ) freq[number[i][j]-'A']++;

           int possible = 1 ;
           for( int j = 0 ; j < 26 && possible ; j++ )
           {
               if( freq[j] > 0 )
               {
                   if( freq[j] > has[j] ) possible = 0 ;
               }
           }
           if( possible == 1 )
           {
               rep( j , nsz ) has[number[i][j]-'A']--;
               ans.pb(seq[i]);
               notun = 0 ;

           }
           else
           {
               i++;
               notun = 1 ;
               ms( freq , 0 );
           }
       }
       sort( ans.begin() ,ans.end() );

       int asz = ans.size();
       rep( i , asz ) printf("%d",ans[i]);

       puts("");

      /* for( int i = 0 ; i < 26 ; i++ )
       {
           if( has[i] > 0 ) printf(" Yes :: %c \n"  , i + 'A' );
       } */
   }

    return 0;
}
