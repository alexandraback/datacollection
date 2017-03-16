/* Author   : FameofLight */
#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long int64;
typedef pair<int,int> ii;
typedef vector<string> vs;
#define size(x) (int)((x).size())
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)
#define Forr(i,y,x) for(int i=y;i>=x;i--)
#define Forn(i,y,x) for(int i=y;i<=x;i++)
#define Fill(a, v) memset(a, v, sizeof(a))
#define inRange(x,l,u) ((x)>=(l) && (x)<=(u))
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define Unique(c) sort(all(c)), (c).resize(unique(all(c)) - (c).begin());
#define Foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int inf=(1<<28);
const double eps=1e-9;
const double pi=acos(-1.0);

/* Bitmasking Common Operator Follows */
#define two(X) (1<<(X))
#define setBit(S,X) (S|=two(X))
#define contain(S,X) ((S&two(X))>0)
#define resetBit(S,X) (S&=(~two(X)))

#define twoL(X) (((ll)1)<<(X))
#define setBitL(S,X) (S|=twoL(X))
#define containL(S,X) ((S&twoL(X))>0)
#define resetBitL(S,X) (S&=(~twoL(X)))

template<class T> T lowbit(const T &n) { return (n^(n-1))&n; }
template<class T> int countbit(const T &n) { return (n==0)?0:(countbit(n&(n-1))+1); }

template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T abs(T x){return x<0 ? -x : x;}
template<class T> inline void checkmin(T &a,const T &b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a,const T &b) { if (b>a) a=b; }
double distR(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}
int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)
  {double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);if (fabs(t)<=eps) return 0;return (t<0)?-1:1;}
bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
  {return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;}



/* Numeric Function */
bool isMiddle(ll m,ll l,ll h){if(m>=l && m<h)return true; return false;}//Exclusive
bool isMiddlei(ll m,ll l,ll h){if(m>=l && m<=h)return true; return false;}//Inclusive
bool isMiddle(double s,double m,double t){return fabs(s-m)<=eps || fabs(t-m)<=eps || (s<m)!=(t<m);}
template<class T> inline T gcd2(T a,T b,T &x,T &y){if(a<0){T d=gcd2(-a,b,x,y);x=-x;return d;}if(b<0)
{T d=gcd2(a,-b,x,y);y=-y;return d;}if(b==0){x=1;y=0;return a;}else{T d=gcd2(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b){if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline vector<pair<T,int> > factorize(T n){vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0)
{int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}
template<class T> inline T multiplyMod(T a,T b,T m) {return (T)((((ll)(a)*(ll)(b)%(ll)(m))+(ll)(m))%(ll)(m));}
template<class T> inline bool isPrime(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T powerMod(T p,int e,T m){if(e==0)return 1%m;else if(e%2==0){T t=powerMod(p,e/2,m);return multiplyMod(t,t,m);}else return multiplyMod(powerMod(p,e-1,m),p,m);}

/* Matrix Class */
const int MaxMatrixSize=40;
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j]<<',';cout<<endl;}}
template<class T> inline void identityMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
template<class T> inline void addMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];}
template<class T> inline void subMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];}
template<class T> inline void mulMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];}
template<class T> inline void addModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]+B[i][j],m);}
template<class T> inline void subModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]-B[i][j],m);}
template<class T> inline void mulModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]=(C[i][j]+multiplyMod(A[i][k],B[k][j],m))%m;}
template<class T> inline void powerMatrix(int n,T p,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize])
{if(p==0){identityMatrix(n,C);return;}T B[MaxMatrixSize][MaxMatrixSize];powerMatrix(n,p/2,B,_A);mulMatrix(n,C,B,B);if(p%2){memcpy(B,C,sizeof(B)); mulMatrix(n,C,B,_A);}}
template<class T> inline void powerModMatrix(int n,T p,T m,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize])
{if(p==0){identityMatrix(n,C); return;}T B[MaxMatrixSize][MaxMatrixSize];powerModMatrix(n,p/2,m,B,_A);mulModMatrix(n,m,C,B,B);if(p%2){memcpy(B,C,sizeof(B)); mulModMatrix(n,m,C,B,_A);}}

/*Fraction Class */
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};
template<class T> bool operator<(Fraction<T> p,Fraction<T> q){return p.a*q.b < p.b*q.a;}
template<class T> bool operator==(Fraction<T> p,Fraction<T> q){return p.a*q.b == p.b*q.a;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}

/* Common Coversion */
template<class T> int toInt(T n){stringstream ost;ost<<n;int ret;ost>>ret;return ret;}
template<class T> ll toInt64(T n){stringstream ost;ost<<n;ll ret;ost>>ret;return ret;}
template<class T> string toString(T n){stringstream ost;ost<<n;ost.flush();return ost.str();}
template<class T> double toDouble(T n){stringstream ost;ost<<n;double ret;ost>>ret;return ret;}
template<class T> static void split(const string &s, vector<T> &out){istringstream in(s);out.clear();copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));}

/* Input Output */
char buffer[10009];
inline void getString(){scanf("%s",&buffer);}
inline void getStringN(){scanf("%[^\n]",buffer);}
inline int getInt(){static int ret;scanf("%d",&ret);return ret;}
inline int64 getInt64(){static int64 ret;scanf("%lld",&ret);return ret;}
inline double getDouble(){static double ret;scanf("%lf",&ret);return ret;}

/*Debugging */
#define out(x) cout << #x << " = " << x << endl;
#define outArray(x,n) cout<<"{";For(i,n)cout<<x[i]<<", ";cout<<"}"<<endl;
#define outAny(x) cout<<"{";Foreach(it,x)cout << *it << ", " ;cout<<"}"<<endl;
template<typename T,typename TT>ostream &operator<<(ostream &s,pair<T,TT> t){return s<<'('<<t.first<<','<<t.second<<')';}

/* Don't Code Until You are sure of your Idea , God Bless You ! */

int64 num[ 1009 ];

int found[ 10000000 ];

int main()
{
    #ifdef FAMEOFLIGHT_HOME
        freopen("problemB.in","r",stdin);
        freopen("problemB.out","w",stdout);
    #endif
    
    int t,n;
    scanf("%d",&t);
    
    for( int testId =1 ; testId <= t; testId++ )
    {
         scanf("%d",&n);
         
         int64 sum = 0;
         for( int i = 0; i < n; i++ )
         {
              scanf("%lld",&num[i] );
              sum+= num[i];
         }
         int set1 = -1 , set2 = -1;
         
         memset( found , -1 , sizeof( found ) );
         
         int64 tsum = 0;
         for( int i = 0; i < two( n ); i++ )
         {
              tsum = 0;
              for( int j = 0; j < n; j++ )
              {
                   if( i & two( j ) )
                       tsum += num[j];
              }
              
              if( found[tsum] != -1 )
              {
                  set1 = found[tsum];
                  set2 = i;
                  break;
              }
              found[tsum] = i;
         }
         
         if( set1 == -1 )
         {
             printf("Case #%d:Impossible\n" , testId );
         }
         else
         {
             printf("Case #%d:\n",testId);
             for( int j = 0; j < n; j++ )
                  if( set1 & two(j) )
                      printf("%d ", num[j]);
             putchar(10);
             for( int j = 0; j < n; j++ )
                  if( set2 & two(j) )
                      printf("%d ", num[j]);
             putchar(10);
         }
    }
    
    return 0;
}
