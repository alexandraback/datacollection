//
//  main.cpp
//  QualQA
//
//  Created by Bigmac on 2014/4/11.
//  Copyright (c) 2014年 Google CodeJam. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
FILE *fi = NULL;
FILE *fo = NULL;
#define out(x) {cerr << #x"=" << x << endl;}
#define out_stop(x) {cerr << #x"=" << x << endl; cin.ignore(1); exit(1);}
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(decltype(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
/*
 //BEGINTEMPLATE_BY_ACRUSH_TOPCODER
 #define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
 #define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
 #define MP(X,Y) make_pair(X,Y)//NOTES:MP(
 typedef long long int64;//NOTES:int64
 typedef unsigned long long uint64;//NOTES:uint64
 #define two(X) (1<<(X))//NOTES:two(
 #define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
 #define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
 #define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
 const double pi=acos(-1.0);//NOTES:pi
 const double eps=1e-11;//NOTES:eps
 template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
 template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
 template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
 typedef pair<int,int> ipair;//NOTES:ipair
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
 template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
 {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
 i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
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
 //ENDTEMPLATE_BY_ACRUSH_TOPCODER
 */

void openIOFile(int argc, char **argv)
{
	const char *filename_in = "input.in";
	if(argc > 1)
	{
		filename_in = argv[1];
	}
	string filename(filename_in);
	size_t pos = filename.find(".in");
	string filename_out = filename.substr(0,pos);
	filename_out.append(".out");
	fi = fopen(filename_in, "rt");
	if(fi == NULL)
	{
		out_stop("cannot open input.");
	}
	fo = fopen(filename_out.c_str(), "wt");
	if(fo == NULL)
	{
		out_stop("cannot open output.");
	}
}
void closeIOFile()
{
	fclose(fi);
	fclose(fo);
}
int readInt()
{
	int in_v;
	if(fscanf(fi, "%d", &in_v) != 1){out_stop("Failed Reading Input");}
	return in_v;
}
long long readHugeInt()
{
	long long in_v;
	if(fscanf(fi, "%lld", &in_v) != 1){out_stop("Failed Reading Input");}
	return in_v;
}
double readDouble()
{
	double in_v;
	if(fscanf(fi, "%lf", &in_v) != 1){out_stop("Failed Reading Input");}
	return in_v;
}
char readChar()
{
	char in_v = 0x00;
	while(in_v == ' ' || in_v == 0x0d || in_v == 0x0a || in_v == 0x00)
	{
		if(fscanf(fi, "%c", &in_v) != 1){out_stop("Failed Reading Input");}
		if(in_v != 0x0d && in_v != 0x0a && in_v != 0x00 && in_v != ' ')
		{
			return in_v;
		}
	}
	return in_v;
}
string readString()
{
	char in_v[2000];
	in_v[0] = 0x00;
	while(in_v[0] == ' ' || in_v[0] == 0x0d || in_v[0] == 0x0a || in_v[0] == 0x00)
	{
		if(fscanf(fi, "%s", in_v) != 1){out_stop("Failed Reading Input");}
		if(in_v[0] != 0x0d && in_v[0] != 0x0a && in_v[0] != 0x00)
		{
			return in_v;
		}
	}
	return in_v;
}
//2014 Qual QA
int main(int argc, char **argv)
{
	openIOFile(argc,argv);
	int in_t = readInt();
	for(int it_t = 1; it_t <= in_t; it_t++)
	{
		//init input
		//finish init input
		int l_val = readInt();
		long long x_val = readHugeInt();
		int l[15000];
		int val_1 = 1;
		int val_i = 2;
		int val_j = 3;
		int val_k = 4;
		int val__1 = -1;
		int val__i = -2;
		int val__j = -3;
		int val__k = -4;
		auto mul = [=](int a, int b) -> int {
			int a_val = abs(a);
			int b_val = abs(b);
			int a_sign = ((a>=0)? 1: -1) * ((b>=0)? 1: -1);
			switch(a_val * 10 + b_val)
			{
				case 11:return a_sign * val_1;
				case 12:return a_sign * val_i;
				case 13:return a_sign * val_j;
				case 14:return a_sign * val_k;
				case 21:return a_sign * val_i;
				case 22:return a_sign * val__1;
				case 23:return a_sign * val_k;
				case 24:return a_sign * val__j;
				case 31:return a_sign * val_j;
				case 32:return a_sign * val__k;
				case 33:return a_sign * val__1;
				case 34:return a_sign * val_i;
				case 41:return a_sign * val_k;
				case 42:return a_sign * val_j;
				case 43:return a_sign * val__i;
				case 44:return a_sign * val__1;
				default:
				assert(0);
			}
		};
		int block_val = val_1;
		FOR(a,0,l_val)
		{
			switch(readChar())
			{
				case 'i':
				l[a] = val_i;
				break;
				case 'j':
				l[a] = val_j;
				break;
				case 'k':
				l[a] = val_k;
				break;
				default:
				assert(0);
			}
			block_val = mul(block_val, l[a]);
		}
		int total_val = 1;
		bool en_pow1 = x_val > 1;
		bool en_pow2 = x_val > 2;
		bool en_pow3 = x_val > 3;
		int mv_pow1 = block_val;
		int mv_pow2 = mul(mv_pow1, block_val);
		int mv_pow3 = mul(mv_pow2, block_val);
		for(long long a = 0; a < (x_val % 4); a++)
		{
			total_val = mul(total_val, block_val);
		}
		char buf[100];
		int val_ijk = mul(mul(val_i, val_j),val_k);
		if(total_val == val_ijk)
		{
			//find i
			int pos_i = INT_MAX / 3;
			bool find_i = true;
			int cur_ival = val_1;
			bool find_i0 = false;
			bool find_i1 = false;
			bool find_i2 = false;
			bool find_i3 = false;
			int pos_i1 = INT_MAX;
			int pos_i2 = INT_MAX;
			int pos_i3 = INT_MAX;
			for(int p=0; p<l_val;p++)
			{
				cur_ival = mul(cur_ival, l[p]);
				if(cur_ival == val_i)
				{
					pos_i = p;
					find_i0 = true;
					break;
				}
				if(en_pow1 && (!find_i1) && mul(mv_pow1, cur_ival) == val_i)
				{
					find_i1 = true;
					pos_i1 = p + l_val;
				}
				if(en_pow2 && (!find_i2) && mul(mv_pow2, cur_ival) == val_i)
				{
					find_i2 = true;
					pos_i2 = p + l_val * 2;
				}
				if(en_pow3 && (!find_i3) && mul(mv_pow3, cur_ival) == val_i)
				{
					find_i3 = true;
					pos_i3 = p + l_val * 3;
				}
			}
			if(find_i0)
			{
			}
			else if(find_i1)
			{
				pos_i = pos_i1;
			}
			else if(find_i2)
			{
				pos_i = pos_i2;
			}
			else if(find_i3)
			{
				pos_i = pos_i3;
			}
			else
			{
				find_i = false;
				pos_i = INT_MAX / 3;
			}
			//find k
			int pos_k = INT_MAX/3 ;
			int cur_kval = val_1;
			bool find_k = true;
			bool find_k0 = false;
			bool find_k1 = false;
			bool find_k2 = false;
			bool find_k3 = false;
			int pos_k1 = INT_MAX;
			int pos_k2 = INT_MAX;
			int pos_k3 = INT_MAX;
			for(int p=0; p<l_val;p++)
			{
				cur_kval = mul(l[l_val - 1 - p], cur_kval);
				if(cur_kval == val_k)
				{
					pos_k = p;
					find_k0 = true;
					break;
				}
				if(en_pow1 && (!find_k1) && mul(cur_kval, mv_pow1) == val_k)
				{
					find_k1 = true;
					pos_k1 = p + l_val;
				}
				if(en_pow2 && (!find_k2) && mul(cur_kval, mv_pow2) == val_k)
				{
					find_k2 = true;
					pos_k2 = p + l_val * 2;
				}
				if(en_pow3 && (!find_k3) && mul(cur_kval, mv_pow3) == val_k)
				{
					find_k3 = true;
					pos_k3 = p + l_val * 3;
				}
			}
			if(find_k0)
			{
			}
			else if(find_k1)
			{
				pos_k = pos_k1;
			}
			else if(find_k2)
			{
				pos_k = pos_k2;
			}
			else if(find_k3)
			{
				pos_k = pos_k3;
			}
			else
			{
				find_k = false;
				pos_k = INT_MAX / 3;
			}
			if(find_i && find_k && ((long long)(pos_i + pos_k) < l_val * x_val))
			{
				sprintf(buf, "YES");
			}
			else
			{
				sprintf(buf, "NO");
			}
		}
		else
		{
			sprintf(buf, "NO");
		}
		
		//===========================================solve function  end ================================//
		const char* sol = buf;
		//		fprintf(fo, "Case #%d: %lld", it_t, sol);
		
		fprintf(fo, "Case #%d: %s", it_t, sol);
		fprintf(fo, "\n");
	}
	closeIOFile();
}