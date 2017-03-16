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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i ++)
#define REP(i,n) FOR(i, 0, n)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back

string fsmall = "B-small-attempt1.in";
string flarge = "B-large.in";
ofstream fout;
ifstream fin;

double d;
int n,A;
double a[255],t[2005],x[2005];

double getTimes(double ac)
{
	double ans = 0;

	double x0 = 0,x1 = 0;
	double xx = 0;
	double tt = 0;
	double v0 = 0, v1 = 0;
	if (x[0] >= d)
	{
		return (sqrt(v0*v0+2*ac*(d-x0))-v0)/ac;
	}
	for (int i = 1; i < n ; i++)
	{
		tt = t[i] - t[i-1];
		xx = x[i];
		if (xx >= d)
		{
			tt = tt*(d-x[i-1])/(xx-x[i-1]);
			xx = d;
		}
		x0 = x0 + v0*tt + 0.5*ac*tt*tt;
		v0 = ac*tt;
		if (x0 > xx)
		{
			x0 = xx;
			v0 = (x[i]-x[i-1])/tt;
		}
		ans += tt;

		if (x0 >= d)
		{
			break;
		}
	}
	if (x0 < d)
	{
		ans += (sqrt(v0*v0+2*ac*(d-x0))-v0)/ac;
	}
	return ans;
}

void func()
{
	fin>>d>>n>>A;
	REP(i,n)
		fin>>t[i]>>x[i];
	REP(i,A)
		fin>>a[i];

	fout<<setiosflags(ios::fixed)<<setprecision(10);
	REP(i,A)
		fout<<endl<<getTimes(a[i]);
	return ;
}

int main()
{
	int n;
	fin.open(flarge.c_str());
	fout.open("out.txt");
	fin>>n;
	REP(i,n)
	{
		fout<<"Case #"<<i+1<<":";

		func();

		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;

}