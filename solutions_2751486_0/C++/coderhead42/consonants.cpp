/************************************************************************************************************

	AUTHOR : coderhead_42

	FILE NAME : consonants.cpp

	CREATION DATE : Sun 12 May 2013 02:35:56 PM IST

	LAST MODIFIED : Sun 12 May 2013 02:45:32 PM IST
			
*************************************************************************************************************/

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
#include <cmath>
#include <ctime>
#include <climits>

using namespace std;

typedef vector<int> VI;
typedef vector<int>::iterator VII;
typedef vector<vector <int> > VVI;
typedef vector<vector <int> >::iterator VVII;
typedef vector<string> VSTR;
typedef vector<string>::iterator VSTRI;
typedef string STR;
typedef string::iterator STRI;
typedef pair<int,int> PII;
typedef list<int> LI;
typedef list<int>::iterator LII;


typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define INF (int)1e9
#define LINF (long long)1e18
#define EPS 1e-9
#define PI 3.1415926
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())
#define LEN(X) ((int)(X.length()))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORi(i,a,b) for (i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a-1;i>=b;i--)
#define ROFi(i,a,b) for (i=a-1;i>=0;i--)
#define DIS(a)includesort(all(a)); a.erase(unique(all(a)),a.end())
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char c;scanf("%c",&c);c;})
#define SIC ({scanf("%*c");})
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define LS(a,x) ({int z=(lower_bound(ALL(a),x)-(a).begin());(z==0&&a[0]!=x)?-1:z;})
#define HS(a,x) ({int z=(upper_bound(ALL(a),x)-(a).begin());z;})
#define FILL(a,x) memset(a, x, sizeof(a))
#define SIEVE(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.PB(2);e.PB(3);FOR(x,1,b+1){FOR(y,1,b+1){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}FOR(r,5,b+1){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}FOR(c,5,a){if(d[c]){e.PB(c);}}e;})
#define LOG2(X) log(X)/log(2)
#define CASE ({printf("Case #%d: ",testcase+1);})
#define DEBUG 1

// BIT OPERATIONS

#define IFSET(S,X) ((sizeof(S)==4)&&(((S)&(1<<(X)))!=0))||((sizeof(S)==8)&&(((S)&(((int64)(1))<<(X)))!=0))
#define SET(S,X) ((sizeof(S)==4)&&((S)|=(1<<(X))))||((sizeof(S)==8)&&((S)|=(((int64)(1))<<(X))))
#define UNSET(S,X) ((sizeof(S)==4)&&((S)&=(~(1<<(X)))))||((sizeof(S)==8)&&((S)&=(~(((int64)(1))<<(X)))))
#define IS2(X) (X && !(X & (X-1)))
#define SWAPR2L(b,i,j,n) ({unsigned int x=((b>>i)^(b>>j))&((1U<<n)-1);unsigned int r=b^((x<<i)|(x<<j));r;})
#define REVERSEBIT(v) ({unsigned int r=v;int s=sizeof(v)*CHAR_BIT - 1;for(v>>=1;v;v>>=1){r<<=1;r|=v&1;s--}r<<=s;r;})
#define MOD2(x,y) (x&&((1U<<y)-1))
template<class T> inline string DISPLAYBIT(T n,int s,int e) {string a;while(s>=e){if(s<sizeof(n)*CHAR_BIT) IFSET(n,s)?a+='1':a+='0';s--;}return a;}
//#define LOWBIT(n) ((n^(n-1))&n)
//template<class T> inline int COUNTBIT(T n){return (n==0)?0:(1+COUNTBIT(n&(n-1)));}
template<class T> inline int COUNTBIT(T n){return (sizeof(n)==4)?__builtin_popcount(n):__builin_popcountl(n);}
template<class T> inline int LSB(T n){return (sizeof(n)==4)?__builtin_ffs(n)-1:__builtin_ffsl(n)-1;}
template<class T> inline int MSB(T n){return (sizeof(n)==4)?31-__builtin_clz(n):63-__builtin_clzl(n);}
//#define LSB(n) MSB((n^(n-1))&n)
//template<class T> inline unsigned int MSB1(T v){const unsigned int b[]={0x2,0xC,0xF0,0xFF00,0xFFFF0000};const unsigned int S[]={1,2,4,8,16,32};int i;register unsigned int r=0;if(sizeof(v)==8){if(v&0xFFFFFFFF00000000){v>>=S[5];r|=S[5];}}if(v&b[4]){v>>=S[4];r|=S[4];}if(v&b[3]){v>>=S[3];r|=S[3];}if(v&b[2]){v>>=S[2];r|=S[2];}if(v&b[1]){v>>=S[1];r|=S[1];}if(v&b[0]){v>>=S[0];r|=S[0];}return r;}
#define INTERLEAVE(x,y) ({int z; int64 z1;for(int i=0;i<sizeof(x)*CHAR_BIT;i++){z|=(x&1U<<i)<<i|(y&1U<<i)<<(i+1);z1|=(x&1U<<i)<<i|(y&1U<<i)<<(i+1);}(sizeof(x)==4)?z1:z;})
#define NEXT_PERM(a) ({unsigned int t=v|(v-1);unsigned int w=(t+1)|(((~t&-~t)-1)>>(__builtin_ctz(v)+1));w;})


// NUMBER THEORY FUNCTIONS

template<class T> inline T GCD(T a,T b){if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<class T> inline T LCM(T a,T b){if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<class T> inline T EUCLIDEAN(T a,T b,T &x,T &y){if(a<0){T d=EUCLIDEAN(-a,b,x,y);x=-x;return d;}if(b<0){T d=EUCLIDEAN(a,-b,x,y);y=-y;return d;}if(b==0){x=1;y=0;return a;}else{T d=EUCLIDEAN(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline vector<pair<int,int> > FACTORIZE(int n){if(n>1e7)return FACTORISE(n);vector<pair<int,int> >R;VI a(SIEVE(n));int i;if(a[LS(a,n)]==n){R.push_back(make_pair(n,1));return R;}int b=(int)sqrt(n);for(i=0;a[i]<=b;i++){if(n%a[i]==0){int d=0;for(;n%a[i]==0;d++,n/=a[i]);R.push_back(make_pair(a[i],d));}}for(;a[i]<n;i++){if(n%a[i]==0){R.push_back(make_pair(a[i],1));break;}}return R;}
template<class T> inline bool IZPRIME(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline bool ISPRIME(T n){if(n>1e7)return IZPRIME(n);VI a(SIEVE(n));int b=LS(a,n);return (b!=-1&&a[b]==n);}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORIZE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}

//MODULUS OPERATIONS

template<class T> inline T CHECKMOD(T n,T m) {return (n%m+m)%m;}
template<class T> inline T MULTIPLYMOD(T a,T b,T m) {return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));}
template<class T> inline T DIVIDEMOD(T a,T b,T m) {T x,y;EUCLIDEAN(b,m,x,y);return MULTIPLYMOD(a,x,m);}
template<class T> inline T POWERMOD(T p,int e,T m) {if(e==0)return 1%m;else if(e%2==0){T t=POWERMOD(p,e/2,m);return MULTIPLYMOD(t,t,m);}else return MULTIPLYMOD(POWERMOD(p,e-1,m),p,m);}

//MATRIX OPERTIONS

template<class T> inline void SHOWMATRIX(vector<vector<T> >& A) {for (int i=0;i<SZ(A);i++){for (int j=0;j<SZ(A[0]);j++)cout<<A[i][j]<<" ";cout<<endl;}}
template<class T> inline void COPYMATRIX(int m,int n,vector<vector<T> >& A,vector<vector<T> >& B) {B.clear();B.resize(n-m+1,vector<T>(n-m+1));for (int i=m,k=0;i<=n;i++,k++){for(int j=m,l=0;j<=n;j++,l++)B[k][l]=A[i][j];}}
template<class T> inline void IDENTITYMATRIX(int n,vector<vector<T> >& A) { A.clear();A.resize(n,vector<T>(n));for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
template<class T,class BinaryOperation> inline void CHECKMATRIX(vector<vector<T> > A,vector<vector<T> > B,vector<vector<T> >& C,BinaryOperation b) {int n=SZ(A);C.clear();C.resize(SZ(A),vector<T>(SZ(A)));for (int i=0;i<SZ(A);i++) for (int j=0;j<SZ(A[0]);j++) C[i][j]=b(A[i][j],B[i][j]);}
template<class T> inline void mulMatrix(vector<vector<T> > A,vector<vector<T> > B,vector<vector<T> >& C) { C.clear();C.resize(SZ(A),vector<T>(SZ(B[0])));for (int i=0;i<SZ(A);i++) for (int j=0;j<SZ(B[0]);j++) for (int k=0;k<SZ(B);k++) C[i][j]+=A[i][k]*B[k][j];}
template<class T> inline void TRANSMATRIX(vector<vector<T> >& B,vector<vector<T> >& A) {B.clear();B.resize(SZ(A[0]),vector<T>(SZ(A)));for(int i=0;i<SZ(B);i++){for(int j=0;j<SZ(B[0]);j++) B[i][j]=A[j][i];}}
template<class T,class BinaryOperation> inline void SCALARMATRIX(vector<vector<T> >& B,vector<vector<T> >& A,T c,BinaryOperation d) {B.clear();B.resize(SZ(A[0]),vector<T>(SZ(A)));for(int i=0;i<SZ(B);i++){for(int j=0;j<SZ(B[0]);j++) B[i][j]=d(A[j][i],c);}}

//TRANSLATOR

template<class T> inline string TOSTRING(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
template<class T> inline void TOVAR(string s,T &r){istringstream sin(s);sin>>r;}
template<class T> inline void STOV(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
template<class T> inline void VTOS(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}
template<class T> inline vector<T> ATOV(T a[]) {vector<T> v(a,a+sizeof(a)/sizeof(T));return v;}
//template<class T> inline void VTOA(vector<T> a,T &b) {int n=SZ(a);for (int i=0;i<n;i++)b[i]=a[i];}

//FRACTION

template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=GCD(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}

#define LL long long int


#define DEBUG 1

/****************************************************************************************************************************/

inline bool is_consonant(char a){
	if(a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u')
		return true;
	return false;
}

int process(STR a, int s,int e){
	int fcnt=0;
	int cnt=0;
	if(is_consonant(a[s])) { cnt=1;fcnt=1;}
	for(int i=s+1;i<=e;i++){
		if(is_consonant(a[i])&&is_consonant(a[i-1]))
			cnt++;
		else if(is_consonant(a[i])){
			fcnt=max(fcnt,cnt);
			cnt=1;
		}
	}
	fcnt=max(fcnt,cnt);
	return fcnt;
}


int main(){

#ifdef DEBUG
	double tmp_start = clock();
	fprintf(stderr, "Start\n");
#endif

int n=SI;
FOR(testcase,0,n){

STR a;
cin>>a;
int s=SI;
int cnt=0;
FOR(i,0,SZ(a)){
	ROF(j,SZ(a),i){
		if(process(a,i,j)>=s)
			cnt++;
	}
}
CASE;
printf("%d\n",cnt);

}

#ifdef DEBUG
	fprintf(stderr, "Total time = %.2lf sec\n", (double)(clock() - tmp_start) / CLOCKS_PER_SEC);
#endif

	return 0;
}
