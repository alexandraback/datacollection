#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#include <string.h>
using namespace std;
#define REP(i,n) for(int i=0,n_=(n);i<n_;i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOR(i,a,b) for (int i=a,b_=b;i<=(b);i++)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)(a).size()
#define SORT(a) sort(ALL(a))
#define INF 1073741823
#define DEB(x) cerr<<#x<<":"<<x<<"\n"
#define PB(b) push_back(b)
#define i64 long long
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

vector<int> SplitInt(string &s)
{
	vector<int>Res;int tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

vector<string> SplitStr(string &s)
{
	vector<string>Res;string tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

//////////////////////////////////////////////////////////////

int s[122222];
int n;
vector<double> resS;
double res[12222],sum;
bool test(double x)
{
	double y=0;
	vector<double>v;
	int mins=0;
	double sone=0;
	REP(i,n)
	{
		if(s[i]>=x)
		{
			v.PB(0);
			if (s[i]==x)
				mins++;
		}
		else
		{
			double y=(x-s[i])/sum;
			v.PB(y);
			
			mins++;
			sone+=y;
		}
	}
//	printf("%.9lf\n",sone);
//	DEB(mins);
	resS=v;
	if (fabs(sone-1)>1e-6)
		return false;
//	DEB("asdd");
	if(mins>=2)
		return true;
//	DEB("asd");
	return false;
}
double bs(double ini,double fin,int d)
{
	if (d>64)
		return (ini+fin)/2;
	
	double x=(ini+fin)/2;
//	DEB(d);
	if(test(x))
	{
//		DEB("yes");
		return bs(x,fin,d+1);
	}
		return bs(ini,x,d+1);
}
int main ()
{
	int c,k;

	scanf ("%d",&c);
	FOR(cas,1,c)
	{
		sum=0;
		
		int z=0;
		scanf("%d",&n);
		REP(i,n)
		{
			scanf ("%d",&s[i]);
			sum+=s[i];
			if (s[i]==0)
				z++;
		}
//		DEB(test(51.0000000));
////		continue;
//		double r=bs(0,sum*2,0);
//		DEB(r);
//		//printf("%lf---",a);
		printf ("Case #%d: ",cas);
		double r=sum*2/(double)n;
		test(r);
		REP(i,n)
		{
			printf ("%.6lf",resS[i]*100);
			if (i<n-1)
				printf(" ");
		}
		printf ("\n");
	}
	return 0;
}

