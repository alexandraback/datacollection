#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <memory.h>
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
using namespace std; 

const int inf = 1000*1000*1000; 
#define CL(x,a) memset(x,a,sizeof(x)); 
#define ALL(v) (v).begin(),(v).end() 
#define PII pair<int,int> 
#define PDI pair<double,int> 
#define MP(a,b) make_pair(a,b) 
#define FOR(i,n) for(int i=0;i<n;i++) 
typedef long long LL; 
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef vector< vector<PII > > vvpii; 

double D;
int n,m;
double T[2048];
double x[2048];
double acc[512];

double getNextCarPosition(double time)
{
	int L=0,R=n;
	while(R-L>1)
	{
		int M = (L+R)/2;
		if (T[M] <= time)
			L = M;
		else
			R = M;
	}
	if (L == n-1)
		return x[n-1]+1;
	return x[L] + (time-T[L])*(x[L+1]-x[L])/(T[L+1] - T[L]);
}
double getTimeOfIntersect(double L,double R,double pos, double acceleration, double velocity, double lastTime)
{
	double M;
	int C = 300;
	while(C--)
	{
		M = (L+R)/2;
		double t = M - lastTime;
		double carPos = pos +t*velocity + acceleration*t*t/2.0;
		if (getNextCarPosition(M) < carPos || carPos > D)
			R = M;
		else
			L = M;
	}
	return L-lastTime;
}
double calc(double acceleration)
{
	double res = 0;
	double velocity = 0;
	double time = 0;
	double pos = 0;
	for (int i=0;i+1<n;i++)
	{
		if (pos >= D || fabs(pos-D) < 1e-9)
			break;
		double inter = getTimeOfIntersect(time,T[i+1],pos,acceleration,velocity,time);
		res+=inter;
		double npos = pos + velocity*inter + acceleration*inter*inter/2.0;
		double maxSpeed = (x[i+1] - x[i]) / (T[i+1] - T[i]);
		double gettedSpeed = velocity + acceleration * inter;
		double nextPos;
		if (fabs(npos - getNextCarPosition(inter + time)) > 1e-9)
			nextPos = npos;
		else
			nextPos = min(D,x[i+1]);
		//if (fabs(nextPos - npos) > 1e-7)
			res+=(nextPos - npos)/maxSpeed;
		if (fabs(npos - getNextCarPosition(inter + time)) > 1e-9)
			velocity = velocity + acceleration*inter;
		else
			velocity = maxSpeed;
		pos = nextPos;
		time+=inter+(nextPos - npos)/maxSpeed;
	}
	return res;
}
void Solve()
{
	scanf("%lf%d%d",&D,&n,&m);
	FOR(i,n)
	{
		scanf("%lf%lf",&T[i],&x[i]);
	}
	T[n] = T[n-1] + 1e+30;
	x[n] = x[n-1] + 1e+60;
	n++;
	FOR(i,m)
	{
		scanf("%lf",&acc[i]);
	}
	FOR(i,m)
	{
		double res = calc(acc[i]);
		printf("%.9lf\n",res);
	}
}

int main() 
{ 
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	FOR(i,T)
	{
		printf("Case #%d:\n",i+1);
		Solve();
	}
	return 0; 
}
