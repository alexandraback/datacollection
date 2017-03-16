#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>

using namespace std;

#define SIZE(X) ((int)X.size())
#define LENGTH(X) ((int)X.length())
#define MP(A,B) make_pair(A,B)
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> void checkmin(T &a,T b){if (b<a) a=b;}
template<class T> void checkmax(T &a,T b){if (b>a) a=b;}
template<class T> T sqr(T x) {return x*x;}
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
typedef pair<int,int> ipair;
template<class T> void out(T A[],int n) { for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template<class T> void out(vector<T> A,int n=-1) {  if (n==-1) n=A.size();  for (int i=0;i<n;i++) cout<<A[i]<<" ";  cout<<endl;}
template<class T> T gcd(T a,T b){  if (a<0) return gcd(-a,b);  if (b<0) return gcd(a,-b);  return (b==0)?a:gcd(b,a%b);}
template<class T> T lcm(T a,T b){  return a*(b/gcd(a,b));}
int64 toInt64(string s){  istringstream sin(s);  int64 t;  sin>>t;  return t;}
int64 toInt(string s){  istringstream sin(s);  int t;  sin>>t;  return t;}
string toString(int64 v){  ostringstream sout;  sout<<v;  return sout.str();}
string toString(int v){  ostringstream sout;  sout<<v;  return sout.str();}


int typed,all;
double prob[1000040];
double tmp[1000040];

void input(){
	scanf("%d %d",&typed,&all);
	for (int i = 0; i < typed; i++)
	{
		scanf("%lf",prob+i);
	}
}

void work(){
	double tProb,mProb;
	double allUse[1024],v;
	mProb = tProb = 0;
	//1
	tmp[0] = 1;
	for (int i = 0; i < typed; i++)
	{
		tmp[0] *= prob[i];
	}
	allUse[0] = tmp[0] * (all - typed + 1) + (1 - tmp[0])*(all - typed + 1+all+1);
	//2»Ø³µ
	allUse[2] = typed + all + 1;
	tmp[0] = prob[0];
	for (int i = 1; i < typed; i++)
	{
		v = ((typed - i)*2+(all - typed)+1);
		allUse[0] = min(allUse[2],allUse[0]);
		allUse[2] = tmp[0] * v + (1-tmp[0])*(v+all+1);
		allUse[0] = min(allUse[2],allUse[0]);
		tmp[0]*= prob[i];
	}
	//3
	allUse[2] = 2 + all;
	allUse[0] = min(allUse[2],allUse[0]);
	printf("%.6lf\n",allUse[0]);
}

int main(){
	//freopen("d:/1.in","r",stdin);
//	freopen("d:/1.out","w",stdout);
	int nCase,t = 0;
	while (scanf("%d",&nCase) != EOF)
	{
		while (nCase--)
		{
			printf("Case #%d: ",++t);
			input();
			work();
		}
	}
	return 0;
}