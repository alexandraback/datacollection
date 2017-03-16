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

int n;
int S;
vector<double> v; 
vector<double> sorted;
bool check(int x, double M)
{
	double sY = 1-M;
	bool q = 0;
	int i=0;
	for (;i<n;i++)
	{
		if (sorted[i] == v[x] && !q)
		{
			q = 1;
			continue;
		}
		double tY = ((v[x] - sorted[i]) + S*M)/S;
		if (tY > 1)
			return 1;
		tY = max(tY,0.0);
		if (tY < sY || fabs(sY-tY) < 1e-9)
			sY-=tY;
		else
			return 1;
	}
	return 0;
}
void Solve()
{
	scanf("%d",&n);
	v.clear();
	S = 0;
	FOR(i,n)
	{
		int t;
		scanf("%d",&t);
		v.push_back(t);
		S+=t;
	}
	sorted = v;
	sort(ALL(sorted));
	reverse(ALL(sorted));
	for (int i=0;i<n;i++)
	{
		double L=0.0,R=1;
		double M;
		int C = 100;
		while(C--)
		{
			M = (L+R)/2;
			if (check(i,M))
				R=M;
			else
				L=M;
		}
		printf(" %.7lf",R*100);
	}
	printf("\n");
}
int main() 
{ 
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int test=1;test<=T;test++)
	{
		printf("Case #%d:",test);
		Solve();
		cerr <<test << " done\n" << endl;
	}
	return 0; 
}
