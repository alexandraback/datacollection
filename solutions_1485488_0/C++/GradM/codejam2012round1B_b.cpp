#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>
#include <functional>
#include <set>
#include <cmath>
#include <stack>
#include <fstream>
#include <cassert>
#ifdef HOME_PC
#include <ctime>
#endif
using namespace std;

#pragma comment(linker,"/stack:16000000")
#pragma warning (disable : 4996)

#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)(v.size()))
#define mset(A,x) memset((A),(x),sizeof(A))
#define FOR(i,start,N) for(int i=(start);i<(N);++i)
#define FORSZ(i,start,v) FOR(i,start,SZ(v))
#define REPSZ(i,v) FORSZ(i,0,v)
#define FORE(i,start,N) FOR(i,start,N+1)
#define make_unique(v) v.resize(unique(ALL(v))-v.begin())
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define adebug(A,N) FOR(i,0,N) cout<<#A<<"["<<i<<"] = "<<A[i]<<endl;
#define adebug2d(a,n,m) FOR(i,0,n) { FOR(j,0,m) { cout<<a[i][j]<<" ";} cout<<endl;}
#define vdebug(v) REPSZ(i,v) cout<<#v<<"["<<i<<"] = "<<v[i]<<endl;
#define selfx(x,f,a) x = f(x,a)
#define sqr(x) ((x)*(x))


typedef pair<int,int> pii;
typedef long long i64;
typedef vector<int> VI; typedef vector< vector<int> > VVI;
typedef vector<string> VS;

const int inf = 1<<25;
const double eps = 1e-9;

const int MAXN = 111;

struct State
{
	int i, j;
	double time;
	State(double time,int i,int j ):time(time),i(i),j(j) {}
	bool operator<(const State& other) const 
	{
		if(time != other.time)
			return time < other.time;
		return pii(i,j) < pii(other.i,other.j);
	}
};

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

int main()
{
#ifdef HOME_PC
	freopen ("B-small-attempt0(1).in","r",stdin);
	//freopen ("in.txt","r",stdin);
	freopen ("output.txt","w",stdout);
#else
	//freopen ("input.txt","r",stdin);
	//freopen ("output.txt","w",stdout);
#endif
	int numTests = 0;
	cin>>numTests;
	FORE(testCase,1,numTests)
	{
		int n,m,h;
		cin>>h>>n>>m;
		int C[MAXN][MAXN], F[MAXN][MAXN];
		mset(C,0); mset(F,0);
		FOR(i,0,n) FOR(j,0,m)
			cin>>C[i][j];
		FOR(i,0,n) FOR(j,0,m)
			cin>>F[i][j];

		
		double fastestTime[MAXN][MAXN];
		FOR(i,0,MAXN) FOR(j,0,MAXN)
			fastestTime[i][j] = 1e50;
	

		fastestTime[0][0] = 0;

		set<State> Q;
		Q.insert(State(0,0,0));
		while(!Q.empty())
		{
			State current = *Q.begin();
			Q.erase(Q.begin());
			int ci = current.i;
			int cj = current.j;
			double t = fastestTime[ci][cj];
			double absoluteWaterLevel = h - t * 10;

			FOR(k,0,4)
			{
				int ni = ci + di[k];
				int nj = cj + dj[k];
				if(ni < 0 || nj < 0 || ni >= n || nj >= m)
					continue;
				// calculate
				int minExHeight = F[ci][cj];
				int maxExHeight = C[ci][cj] - 50;
				int minEnterHeight = F[ni][nj];
				int maxEnterHeight = C[ni][nj] - 50;

				int minTransitionHeight = max(minExHeight, minEnterHeight);
				int maxTransitionHeight = min(maxExHeight, maxEnterHeight);

				if(minTransitionHeight > maxTransitionHeight)
					continue;

				double waitTime = max(0., (absoluteWaterLevel - maxTransitionHeight)/10.);
				double absoluteWaterLevelNow = min<double>(absoluteWaterLevel, maxTransitionHeight);
				double transitionTime = 0;
				if(absoluteWaterLevelNow - F[ci][cj] >= 20-eps)
					transitionTime = 1;
				else
					transitionTime = 10;

				double totalTime = t == 0. && fabs(waitTime) < eps ? 0 : t + waitTime + transitionTime;
				if(totalTime < fastestTime[ni][nj])
				{
					State newState(totalTime, ni, nj);
					Q.erase(State(fastestTime[ni][nj], ni, nj));
					Q.insert(newState);
					fastestTime[ni][nj] = totalTime;
				}
			}
		}
		double ans = fastestTime[n-1][m-1];
		printf("Case #%d: %.10lf\n",testCase,ans);
	}
	
#ifdef HOME_PC
	cerr<<endl<<"Execution time = "<<clock()<<" ms"<<endl;
#endif
	return 0;
}
