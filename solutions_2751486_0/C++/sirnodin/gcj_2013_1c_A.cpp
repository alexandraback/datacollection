
/*////{{{*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

////NAME:REP
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
////CODE_END
////NAME:FOR
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
////CODE_END
////NAME:DEC
#define DEC(i,n) for (int i=(n); i>=0; --i)
////CODE_END
////NAME:DECFOR
#define DECFOR(i,n,k) for (int i=(n); i>=(int)(k); --i)
////CODE_END
////NAME:FORIT
#define FORIT(i,c) for (typeof((c).begin())i=(c).begin();i!=(c).end();++i)
////CODE_END
////NAME:SORT
#define SORT(c) sort((c).begin(),(c).end())
////CODE_END
////NAME:RSORT
#define RSORT(c) sort((c).rbegin(),(c).rend())
////CODE_END
////NAME:SIZE
#define SIZE(X) ((int)(X.size()))
////CODE_END
////NAME:LENGTH
#define LENGTH(X) ((int)(X.length()))
////CODE_END
////NAME:MP
#define MP(X,Y) make_pair(X,Y)
////CODE_END
////NAME:TWO
#define TWO(X) (1<<(X))
////CODE_END
////NAME:TWOL
////USING:int64
#define TWOL(X) (((int64)(1))<<(X))
////CODE_END
////NAME:CONTAIN
#define CONTAIN(S,X) (((S)&two(X))!=0)
////CODE_END
////NAME:CONTAINL
#define CONTAINL(S,X) (((S)&twoL(X))!=0)
////CODE_END
////NAME:int64
typedef long long int64;
////CODE_END
////NAME:uint64
typedef unsigned long long uint64;
////CODE_END
////NAME:ipair
typedef pair<int,int> ipair;
////CODE_END
////NAME:PI
const double PI=acos(-1.0);
////CODE_END
////NAME:EPS
const double EPS=1e-11;
////CODE_END
////NAME:checkmin
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
////CODE_END
////NAME:checkmax
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
////CODE_END
////NAME:sqr
template<class T> inline T sqr(T x){return x*x;}
////CODE_END
////NAME:lowbit
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
////CODE_END
////NAME:countbit
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
////CODE_END
/*////Numberic Functions_OK*/
////NAME:gcd
template<class T> inline T gcd(T a,T b)
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
////CODE_END
////NAME:lcm
////USING:gcd
template<class T> inline T lcm(T a,T b)
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
////CODE_END
////NAME:euclide
template<class T> inline T euclide(T a,T b,T &x,T &y)
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
////CODE_END
////NAME:factorize
template<class T> inline vector<pair<T,int> > factorize(T n)
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
////CODE_END
////NAME:isPrimeNumber
template<class T> inline bool isPrimeNumber(T n)
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
////CODE_END
////NAME:eularFunction
////USING:factorize
template<class T> inline T eularFunction(T n)
  {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
////CODE_END
/*////Matrix Operations*/
////NAME:MaxMatrixSize
const int MaxMatrixSize=40;//NOTES:MaxMatrixSize
////CODE_END
////NAME:showMatrix
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j];cout<<endl;}}
////CODE_END
////NAME:checkMod
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
////CODE_END
////NAME:identityMatrix
template<class T> inline void identityMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:identityMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
////CODE_END
////NAME:addMatrix
template<class T> inline void addMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];}
////CODE_END
////NAME:subMatrix
template<class T> inline void subMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];}
////CODE_END
////NAME:mulMatrix
template<class T> inline void mulMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulMatrix(
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];}
////CODE_END
////NAME:addModMatrix
template<class T> inline void addModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addModMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]+B[i][j],m);}
////CODE_END
////NAME:subModMatrix
template<class T> inline void subModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subModMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]-B[i][j],m);}
////CODE_END
////NAME:multiplyMod
template<class T> inline T multiplyMod(T a,T b,T m) {return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));}//NOTES:multiplyMod(
////CODE_END
////NAME:mulModMatrix
template<class T> inline void mulModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulModMatrix(
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]=(C[i][j]+multiplyMod(A[i][k],B[k][j],m))%m;}
////CODE_END
////NAME:powerMod
template<class T> inline T powerMod(T p,int e,T m)//NOTES:powerMod(
  {if(e==0)return 1%m;else if(e%2==0){T t=powerMod(p,e/2,m);return multiplyMod(t,t,m);}else return multiplyMod(powerMod(p,e-1,m),p,m);}
////CODE_END
/*////Point&Line_OK*/
////NAME:dist
////USING:sqr
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
////CODE_END
////NAME:distR
////USING:sqr
double distR(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}
////CODE_END
////NAME:cross
template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}
////CODE_END
////NAME:crossOper
////USING:EPS
int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)
  {double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);if (fabs(t)<=EPS) return 0;return (t<0)?-1:1;}
////CODE_END
////NAME:isIntersect
////USING:crossOper
bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
  {return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;}
////CODE_END
////NAME:isMiddle
////USING:EPS
bool isMiddle(double s,double m,double t){return fabs(s-m)<=EPS || fabs(t-m)<=EPS || (s<m)!=(t<m);}
////CODE_END
/*////Translator_OK*/
////NAME:toString
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
////CODE_END
////NAME:toInt
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
////CODE_END
////NAME:toInt64
////USING:int64
int64 toInt64(string s){int64 r=0;istringstream sin(s);sin>>r;return r;}
////CODE_END
////NAME:toDouble
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}
////CODE_END
////NAME:stoa
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}//NOTES:stoa(
////CODE_END
////NAME:atos
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}//NOTES:atos(
////CODE_END
////NAME:atov
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}//NOTES:atov(
////CODE_END
////NAME:vtoa
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}//NOTES:vtoa(
////CODE_END
////NAME:stov
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
////CODE_END
////NAME:vtos
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}//NOTES:vtos(
////CODE_END
/*////Fraction*/
////NAME:Fraction
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
  template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
  template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
  template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
  template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
  template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
  template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
////CODE_END

////CHECK_START
/*////}}}*/

class Problem
{
private:
    static const int MAX=1000002;
    int T;
    int CASE;
    int L;
    long ans;
    string name;
    vector<long> S;
    vector<long> E;

public:
	Problem()
	{
        cin>>T;
        while(CASE++<T)
        {
            cin>>name>>L;
            S.clear();
            E.clear();
            ans=0;

            first_loop();
            solve();

            printf("Case #%d: %ld\n",CASE,ans);
        }
	}

    bool is_c(char c)
    {
        return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
    }

    void first_loop()
    {
        int n=name.size();
        int l=0;
        REP(i,n)
        {
            if(is_c(name[i]))
            {
                l++;
            }
            else
            {
                if(l>=L)
                {
                    S.push_back(i-l);
                    E.push_back(i-1);
                }
                l=0;
            }
        }
        if(l>=L)
        {
            S.push_back(n-l);
            E.push_back(n-1);
        }
    }

	void solve()
	{
        int ls=0;
        int n=name.size();
        REP(p,S.size())
        {
            int s=S[p];
            int e=E[p];

            ans+=(s-ls+1)*(n-s-L+1);
            if(s<=e-L)
                ans+=(n-s-L+n-e)*(e-s-L+1)/2;
            ls=e+2-L;
        }
	}
};

int main()
{
	Problem problem;
	//system("pause");
	return 0;
}

/*////{{{*/
////CHECK_END
/*////}}}*/

