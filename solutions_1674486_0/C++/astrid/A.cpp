#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <cassert>
#include <assert.h>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cctype>
#include <gmp.h>
#include <gmpxx.h>
//#include <ext/hash_set>
//#include <ext/hash_map>

using namespace std;
// using namespace __gnu_cxx;

//////////////////////////////////////////////////////////////////////////////////////////////////

// Constantes
const double pi=acos(-1.0);
const double eps=1e-11;

// Divers
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T min(T &a,T b){if(a<=b) return a; else return b;}
template<class T> inline T max(T &a,T b){if(a>=b) return a; else return b;}
template<class T> inline void setMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void setMax(T &a,T b){if(b>a) a=b;}
template<class T> inline void echange(T* t, int i, int j){T s = t[i]; t[i] = t[j]; t[j] = s;}

// Fonction de comparaison pour le tri
template<class T> inline bool comp(T a, T b) {return a>b;}
template<class T> inline bool comp_p(T a, T b) {return a.first<b.first;}
template<class T> inline bool comp_p_dec(T a, T b) {return a.first>b.first;}

// Analyse/conversion d'un caractère/chaine
bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}

char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}
int toDigit(char c) {return (int)(c-'0');}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

char read_char(ifstream& in) {char c; in >> c; in.unget();return c;}
char read_char_shift(ifstream& in) {char c; in >> c; return c;}

// Conversion string(s) - tableau(a) - vector(v)
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

// Recuperation de la date/heure
int hh_mm(ifstream& in) {char h1, h2, m1, m2, c; in >> h1 >> h2 >> c >> m1 >> m2; 
  return (10*toDigit(h1)+toDigit(h2))*60+(10*toDigit(m1)+toDigit(m2));}

int hh_mm_ss(ifstream& in) {char h1, h2, m1, m2, s1, s2, c1, c2; in >> h1 >> h2 >> c1 >> m1 >> m2 >> c2 >> s1 >> s2; 
  return (10*toDigit(h1)+toDigit(h2))*3600+(10*toDigit(m1)+toDigit(m2))*60+(10*toDigit(s1)+toDigit(s2));}

int jj_mm_aaaa(ifstream& in) {char j1, j2, m1, m2, a1, a2, a3, a4, c1, c2; in >> j1 >> j2 >> c1 >> m1 >> m2 >> c2 >> a1 >> a2 >> a3 >> a4; 
  return (10*toDigit(j1)+toDigit(j2))+(10*toDigit(m1)+toDigit(m2))*32+(1000*toDigit(a1)+100*toDigit(a2)+10*toDigit(a3)+toDigit(a4))*32*12;}


// Arithmétique
template<class T> inline T pgcd(T a,T b)
  {if(a<0)return pgcd(-a,b);if(b<0)return pgcd(a,-b);return (b==0)?a:pgcd(b,a%b);}

template<class T> inline T ppcm(T a,T b)
{if(a<0)return ppcm(-a,b);if(b<0)return ppcm(a,-b);return a*(b/pgcd(a,b));}

template<class T> inline T euclide(T a,T b,T &x,T &y)
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

inline bool isPrimeNumber(int n)
  {if(n<=1)return false;for (int i=2;i*i<=n;i++) if (n%i==0) return false;return true;}

vector<pair<int,int> > factorize(int n) {
  vector<pair<int,int> > R;
  for (int i=2;n>1;){
    if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
    i++;
    if (i>n/i) i=n;} 
  if (n>1) R.push_back(make_pair(n,1));return R;}


/**/template<class T> inline T eularFunction(T n)
  {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}

// Fractions
struct Fraction{int a,b;Fraction(int a=0,int b=1);string toString();};

Fraction::Fraction(int a,int b){int d=pgcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}

string Fraction::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}

Fraction operator+(Fraction p,Fraction q){return Fraction(p.a*q.b+q.a*p.b,p.b*q.b);}
Fraction operator-(Fraction p,Fraction q){return Fraction(p.a*q.b-q.a*p.b,p.b*q.b);}
Fraction operator*(Fraction p,Fraction q){return Fraction(p.a*q.a,p.b*q.b);}
Fraction operator/(Fraction p,Fraction q){return Fraction(p.a*q.b,p.b*q.a);}

// Géométrie

double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}

double distR(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}

/**/template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}

/**/int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)
  {double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);if (fabs(t)<=eps) return 0;return (t<0)?-1:1;}

/**/bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
  {return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;}

bool isBetween(double s,double m,double t){return fabs(s-m)<=eps || fabs(t-m)<=eps || (s<m)!=(t<m);}

// Affichage tableau/matrice

#define MAXL 10
#define MAXC 10

template<class T> void showTab(T* tab, int n) 
{for(int i=0; i<n; i++){cout << tab[i]<< endl;}}

template<class T> void showTabC(T tab[MAXL], int n) 
{for(int i=0; i<n; i++){cout << tab[i]<< endl;}}

template<class T> void showMat(T** tab, int n, int m) 
{for(int i=0; i<n; i++) {for(int j=0; j<m; j++) {cout << tab[i][j] << endl;}}}

template<class T> void showMatC(T tab[MAXL][MAXC], int n, int m) 
{for(int i=0; i<n; i++) {for(int j=0; j<m; j++) {cout << tab[i][j] << endl;}}}

//////////////////////////////////////////////////////////////////////////////////////////////////

//typedef mpz_class mpz; // compilationg++ truc.cpp -lgmpxx -lgmp
bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }
//////////////////////////////////////////////////////////////////////////

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> int2;
typedef pair<float, float> float2;
typedef pair<ull, ull> ull2;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(s,i) for ( __typeof((s).begin()) i = ((s).begin())   ; i != (s).end(); ++i)  
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define del(s,x) do {__typeof((s).begin()) abcde=(s).find(x); if(abcde !=(s).end()) s.erase(abcde); } while(0);
#define del2(s,x) do {__typeof((s).begin()) abcde=find(all(s),x); if(abcde !=(s).end()) s.erase(abcde); } while(0);

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

//////////////////////////////////////////////////////////////////////////

bool dfs(vector<vector<int> > &t, vector<bool> &visited, int root) {
  if(visited[root] == true)
    return false;
  visited[root] = true;
  FOR(i,0,t[root].size()) {
    bool ok = dfs(t, visited, t[root][i]);
    if(!ok)
      return false;
  }
  return true;
}

int main (int argc, char* argv[]) {

  ifstream in (argv[1]);
  ofstream out ("problem.out");
  string line;
  int nbTests;
  out.precision(12);

  in >> nbTests;
  getline(in, line);

  for (int test=0; test<nbTests; test++) {
    int n, mi;
    in >> n;
    /*if(n<=5)
      cout << "n=" << n << endl;*/
    vector<vector<int> > t(n);
    vector<bool> visited(n,false);
    FOR(i,0,n) {
      in >> mi;
      t[i] = vector<int>(mi);
      /*      if(n<=5)
	      cout << "mi=" << mi << " ";*/
      FOR(j,0,mi) {
	in >> t[i][j];
	t[i][j]--;
	/*if(n <= 5)
	  cout << t[i][j] << " ";*/
      }
      /*      if(n <=5)
	cout << endl;*/
    }
    /*if(n <= 5) 
      cout << "--------------" << endl;*/
    
    bool ok = true; //true == no diamond
    FOR(i,0,n) {
      visited = vector<bool>(n,false);
      ok = ok && dfs(t,visited,i);
      if(!ok) 
	break;
    }
    if(ok)
      out << "Case #" << test+1 << ": No" << endl;
    else
      out << "Case #" << test+1 << ": Yes" << endl;
    
  }
}

