#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <utility>
#include <cassert>
#include <math.h>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#pragma warning(disable: 4996)

struct pint{int x,y;};
bool operator<(const pint&a,const pint&b)
{if(a.x!=b.x)return a.x<b.x;return a.y<b.y;}

bool operator==(const pint&a,const pint&b)
{return (a.x==b.x && a.y==b.y);}

typedef long long ll;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned char uchar;
typedef pair<int,int> ipair;
typedef vector<ipair> vp;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

#define _CRT_SECURE_NO_WARNINGS

#define Foru(i,a,b) for (i=(a),_b(b); i <= _b; ++i)
#define Fordu(i,a,b) for (i=(a),_b(b); i >= _b; --i)
#define repu(i,n) for (i=(0); i < (n); ++i)
#define repdu(i,n) for (i=((n)-1); i >= 0; --i)
#define fstru(i,str) for(i=(0);str[i]!=0; i++)


#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define repd(i,n) for (int i((n)-1); i >= 0; --i)
#define fstr(i,str) for(int i(0);str[i]!=0; i++)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()
#define st first
#define nd second

char* stoa(string s){char *str=new char(sizeof(s.length()+1));	strcpy(str,s.c_str());return str;}
/*string convToBase(ll n,int base,string str="")
{
	if(str=="" || str.length()<base)rep(i,base)	if(i<=9)str.push_back((char)(48+i));else str.push_back((char)(65+i-10));
	string conv;for(conv;n>0;n/=base)conv.push_back(str[n%base]);return strrev(stoa(conv));
}


pair<string,ll> baseToBase(string given,int givenBase,int finalBase,string givenPool="",string newPool="")
{
	ll num=0;	if(givenPool!="")rep(i,given.length())num=num*givenBase+ (find(All(givenPool),given[i])-givenPool.begin());
	else rep(i,given.length()) if(isdigit(given[i])) num=num*givenBase+ given[i]-47;
	else if(isupper(given[i]))num=num*givenBase+ given[i]-65+10;else if(islower(given[i]))num=num*givenBase+ given[i]-97+10;
	return MP(string(convToBase(num,finalBase,newPool)),num);
}*/

const long double pi=acos(-1.0L);//NOTES:pi
const double eps=1e-11;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
//Numberic Functions
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide(
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
/*template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}*/
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
  {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
//Matrix Operations
const int MaxMatrixSize=40;//NOTES:MaxMatrixSize
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j];cout<<endl;}}
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline void identityMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:identityMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
template<class T> inline void addMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];}
template<class T> inline void subMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];}
template<class T> inline void mulMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulMatrix(
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];}
template<class T> inline void addModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addModMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]+B[i][j],m);}
template<class T> inline void subModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subModMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]-B[i][j],m);}
template<class T> inline T multiplyMod(T a,T b,T m) {return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));}//NOTES:multiplyMod(
template<class T> inline void mulModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulModMatrix(
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]=(C[i][j]+multiplyMod(A[i][k],B[k][j],m))%m;}
template<class T> inline T powerMod(T p,int e,T m)//NOTES:powerMod(
  {if(e==0)return 1%m;else if(e%2==0){T t=powerMod(p,e/2,m);return multiplyMod(t,t,m);}else return multiplyMod(powerMod(p,e-1,m),p,m);}
//Point&Line
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}//NOTES:dist(
double distR(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}//NOTES:distR(
template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}//NOTES:cross(
int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)//NOTES:crossOper(
  {double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);if (fabs(t)<=eps) return 0;return (t<0)?-1:1;}
bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)//NOTES:isIntersect(
  {return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;}
bool isMiddle(double s,double m,double t){return fabs(s-m)<=eps || fabs(t-m)<=eps || (s<m)!=(t<m);}//NOTES:isMiddle(
//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase(
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase(
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase(
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase(
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}//NOTES:toString(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
int64 toInt64(string s){int64 r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt64(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}//NOTES:stoa(
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}//NOTES:atos(
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}//NOTES:atov(
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}//NOTES:vtoa(
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}//NOTES:vtos(
//Fraction
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
template<class T> bool operator<(Fraction<T> p,Fraction<T> q){return p.a*q.b<p.b*q.a;}
//ENDTEMPLATE_BY_ACRUSH_TOPCODER
//#define FOREACH(it, X) for(sstr::iterator it = X.begin(); it != X.end(); ++it)
ll revNo(ll a){ll n=0;for(;a>0;a/=10)n=n*10+a%10;return n;}


enum Sign{negi=-1,posi=1};
class bigNum
{
public:
	typedef unsigned char dt;
	
	bigNum():size_(0),sign_(posi)
	{
		d=new dt[MD];
		memset(d,0,sizeof(dt)*MD);
	}
	bigNum(const bigNum &a)
	{
		d=new dt[MD];
		memcpy(d,a.d,sizeof(dt)*MD);
		sign_=a.sign();
		size_=a.size();
	}
	bigNum(ll a):size_(0),sign_(posi)
	{
		d=new dt[MD];
		memset(d,0,sizeof(dt)*MD);
		if(a!=0)
		{
			if(a<0)
			{
				sign_=negi;
				a*=-1;
			}
			while(a!=0)
			{
				d[size_++]=a%MN;
				a/=MN;
			}
		}
	}
	bigNum operator=(const bigNum &a) 
	{
		sign_=a.sign_;
		size_=a.size_;
		memcpy(d,a.d,sizeof(dt)*MD);
		return *this;
	}
	int toInt()const
	{
		int n=0;
		repd(i,size_)
		{
			n*=MN;
			n+=d[i];
		}
		return n;
	}

	dt& operator[](int n) const
	{
		assert(n<MD);
		return d[n];
	}
	bool operator<(const bigNum& a)const
	{
		if(this->sign_!=a.sign_)
			return sign_==negi;
		if(size_!=a.size_)
			return size_<a.size_?(sign_==posi):(sign_==negi);

		repd(i,size())
			if(d[i]!=a[i])
				return d[i]<a[i]?(sign_==posi):(sign_==negi);
		return false;

	}
	bool operator==(const bigNum& a)const
	{
		if(this->sign_!=a.sign_ || size_!=a.size_)
			return false;
		repd(i,max(size(),a.size()))
			if(d[i]!=a[i])
				return false;
		return true;
	}
	bool operator!=(const bigNum& a)const
	{
		return !operator==(a);
	}

	bool operator<=(const bigNum& a)const
	{
		if(this->sign_!=a.sign_)
			return sign_==negi;

		if(size_!=a.size_)
			return size_<a.size_?(sign_==posi):(sign_==negi);

		repd(i,max(size(),a.size()))
			if(d[i]!=a[i])
				return d[i]<a[i]?(sign_==posi):(sign_==negi);
		return true;
	}
	bool operator>=(const bigNum& a)const
	{
		return !this->operator<(a);
	}
	bool operator>(const bigNum& a)const
	{
		return !this->operator<=(a);
	}
	bigNum operator+=(const bigNum& a)
	{
		*this=*this+a;
		return *this;
	}
	bigNum operator-=(const bigNum& a)
	{
		*this=*this-a;
		return *this;
	}
	bigNum operator-(const bigNum& a) const
	{
		if(sign_!=a.sign_)
			return operator+(-a);
		

		bigNum sub;
		if( sign_==posi && operator<(a) || sign_==negi && operator>(a))
			return -(a-*this);

		sub.sign_=sign_;
		int c=0;
		int digs=max(size(),a.size());
		int last=-1;
		rep(i,digs)
		{
			int diff=d[i]-a[i]-c;
			c=0;
			if(diff<0)
			{
				diff+=MN;
				c=1;
			}
			
			sub[i]=diff;
			if(diff!=0)last=i;
		}
		assert(c==0);
		sub.size_=last+1;
		return sub;
	}
	bigNum operator-()const
	{
		bigNum tmp;
		tmp.size_=size_;
		tmp.sign_=Sign(sign_*-1);
		memcpy(tmp.d,d,sizeof(dt)*MD);
		return tmp;
	}
	bigNum operator+(const bigNum& a) const
	{
		if(sign_!=a.sign_)
		{
			if(sign_==negi)
				return a-(-*this);
			else
				return operator-(-a);
		}

		bigNum sum;
		sum.sign_=sign_;
		int c=0;
		int digs=max(size(),a.size());
		rep(i,digs)
		{
			int s=d[i]+a[i]+c;
			c=s/MN;
			s=s%MN;
			sum[i]=s;
		}
		if(c!=0)
		{
			sum[digs]=c;
			sum.size_=digs+1;
		}
		else
			sum.size_=digs;
		return sum;
	}
	
	bigNum operator/(const bigNum& a)const

	{
		bigNum temp(*this);
		bigNum count=0;
		while(temp>=a)
		{
			temp-=a;
			count=count+1;
		}
		return count;
	}
	

	bigNum half()const
	{
		bigNum half;
		int c=0;
		repd(i,size_)
		{
			half[i]=(d[i]+c)/2;
			if(d[i]%2)
				c=10;
			else
				c=0;
		}
		half.size_=size_;
		if(half[half.size_-1]==0)
			half.size_--;
		return half;
	}

	bigNum operator*(const bigNum& a) const
	{
		if(*this<a)
			return a*(*this);
		bigNum prod;
		prod.size_=0;
		prod.sign_=posi;

		if(a.size_==1 && a[0]==1)
		{
			prod=*this;
			prod.sign_=Sign(sign_*a.sign_);
		}
		else if(a.size_!=0)
		{
			bigNum tt=a.half();
			bigNum temp=*this*(tt);
			if(a[0]%2)
				prod=temp+temp+*this;
			else
				prod=temp+temp;
		}
		/*if(sign_!=a.sign_)
		{
			if(sign_==negi)
				return a-(-*this);
			else
				return operator-(-a);
		}
		if(a.size_>size_)
			return a*(*this);

		bigNum prod=0;
		
		repd(i,a.size())
		{
			if()
			memmove(prod.d+)
			prod*=MD;
			bigNum tmp=*this*(a[i]);
			prod+=tmp;
		}

		a.size_=0;
		
		prod.sign_=a.size_>0?(Sign(sign_*a.sign_)):posi;*/
		return prod;
	}
	~bigNum()
	{
		delete d;
	}
	int size() const
	{
		return size_; 
	}
	Sign sign() const
	{
		return sign_; 
	}
	static const int MN=10;//should be a power of 10
	
	dt* d;
private:
	static const int MD=40;
	
	Sign sign_;
	unsigned int size_;
};
ostream& operator<<(ostream& sout,const bigNum& n)
{
	if(bigNum::MN==10)
		repd(i,n.size())
			sout<<(int)n.d[i];
	else
		assert("Not coded");
	return sout;
}

int pList[200000],tot=0;
const ll maxPrime=1000000;

void setPrimes()
{
	For(i,2,maxPrime)
	{
		bool s=true;
		rep(j,tot)
			if(i%pList[j]==0)
			{
				s=false;
				break;
			}
			else if(i<pList[j]*pList[j])
				break;
		if(s)
			pList[tot++]=i;
	}
}
bool isPrime(ll n)
{
	if(n<=maxPrime)
		return binary_search(pList,pList+tot,n);
	else if(n<=maxPrime*maxPrime)
	{
		rep(i,tot)
			if(n%pList[i]==0)
				return false;
	}
	else
		assert(false);
	return true;
}

bool isAnagram(string a,string b)
{
	if(a.size()!=b.size())
		return false;
	sort(All(a));
	sort(All(b));
	fstr(i,a)
		if(a[i]!=b[i])
			return false;
	return true;
}

int digs(int n)
{
	int ret=0;
	for(int i=n;i>0;i/=10)
		ret++;
	//reverse(ret.begin(),ret.end());
	//sort(ret.begin(),ret.end());
	return ret;
}

//const int N=7;
ll fac(int n)
{
	ll v=1;
	For(i,2,n)
		v*=i;
	return v;
}
ll ncr(int n,int r)
{
	if(r>n)
		return 0;
	ll ret;
	ret=fac(n)/(fac(r)*fac(n-r));
	return ret;
}

int hcf( int a, int b )
{
	if(a<0)a*=-1;
	if(b<0)b*=-1;

	if(!a && !b) return 1;
	while ( a && b )
	{
		if ( a > b )
			a %= b;
		else
			b %= a;
	}

	return ( a > b ) ? a : b;
}
/*template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{
	  vector<pair<T,int> > R;
	  for (T in=0;n>1;)
	  {
		  int i=pList[in];
		  if (n%i==0)
		  {
			  int C=0;
			  for (;n%i==0;C++,n/=i);
			  R.push_back(make_pair(i,C));
		  }
		  in++;
		  if (pList[in]>n/pList[in]) break;
	  }
	  if (n>1) 
		  R.push_back(make_pair(n,1));return R;
}*/

bool isSquare(ll n)
{
    int h = n & 0xF; 
    if (h > 9)
        return 0; 

    //  Boolean short-circuit evaluation
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
        ll t =  sqrt( n*1.0) + 0.5;
            return t*t == n;
    }
    return false;
}
bool isCube(ll n)
{
	ll r=pow(n*1.0,1.0/3.0)+0.5;
	return r*r*r==n;
}
/*vi points[10000];

int N;
int paths[10000];
bool sol(int pt )
{
	rep(i,points[pt].size())
	{
		int newPt=points[pt][i];
		paths[newPt]++;
		if(paths[newPt]>=2)
			return true;
		if(sol(newPt))
			return true;
	}
	return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	ofstream fout("out.txt");
	int ca;
	cin>>ca;

	For(cc,1,ca)
	{
		cin>>N;
		rep(i,N)
		{
			points[i].clear();
			int mi;
			cin>>mi;
			rep(j,mi)
			{
				int tmp;
				cin>>tmp;
				points[i].push_back(tmp-1);
			}
		}
		bool dis=false;
		rep(i,N)
		{
			Fill(paths,0);
			if(sol(i))
			{
				dis=true;
				break;
			}
		}

		fout<<"Case #"<<cc<<": "<<(dis?"Yes":"No")<<endl;
	}

	return 0;
	
}*/
vi points[10000];

int N;
int paths[10000];
bool sol(int pt )
{
	rep(i,points[pt].size())
	{
		int newPt=points[pt][i];
		paths[newPt]++;
		if(paths[newPt]>=2)
			return true;
		if(sol(newPt))
			return true;
	}
	return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	ofstream fout("out.txt");
	int ca;
	cin>>ca;

	For(cc,1,ca)
	{
		cin>>N;
		rep(i,N)
		{
			points[i].clear();
			int mi;
			cin>>mi;
			rep(j,mi)
			{
				int tmp;
				cin>>tmp;
				points[i].push_back(tmp-1);
			}
		}
		bool dis=false;
		rep(i,N)
		{
			Fill(paths,0);
			if(sol(i))
			{
				dis=true;
				break;
			}
		}

		fout<<"Case #"<<cc<<": "<<(dis?"Yes":"No")<<endl;
	}

	return 0;
}