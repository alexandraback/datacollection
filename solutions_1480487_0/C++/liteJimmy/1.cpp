#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

double dd[3000];
int minPos;
double sum;
int nLen;

bool check(double v){
	double v1 = v * sum,v2 = 0;
	v1 += dd[minPos];
	
	for (int i = 0; i < nLen; i++)
	{
		if (minPos == i)
		{
			continue;
		}
		if (v1 > dd[i])
		{
			v2 += (v1 - dd[i])/sum;
		}
	}
	if (v2 + v > 1)
	{
		return false;
	}
	else return true;
}

double erfen(double l,double r){
	if (l + 1e-9 > r)
	{
		return l;
	}
	else {
		double m = (l+r)/2;
		if (check(m))
		{
			l = m;
		}
		else r = m - 1e-9;
		return erfen(l,r);
	}
}

void work(){
	double ans = erfen(0,1);
	double needV = ans*sum+dd[minPos];
	for (int i = 0; i < nLen; i++)
	{
		if (needV > dd[i])
		{
			printf(" %.6lf",(needV-dd[i])/sum*100);
		}
		else printf(" %.6lf",0);
	}
	printf("\n");
}

int main(){
	int nCase;
	double minV = 0;
	freopen("d:/A-small-attempt1.in","r",stdin);
	freopen("d:/A-small-attempt1.out","w",stdout);
	while (scanf("%d",&nCase) != EOF)
	{
		for (int i = 1; i <= nCase; i++)
		{
			scanf("%d",&nLen);
			sum = 0;
			minPos = 0;
			minV = 1e100;
			for (int j = 0; j < nLen; j++)
			{
				scanf("%lf",dd+j);
				sum += dd[j];
				if (minV > dd[j])
				{
					minV = dd[j];
					minPos = j;
				}
			}

			printf("Case #%d:",i);
			work();
		
		
		}
	}
	return 0;
}