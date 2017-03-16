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

map<int,set<vector<int> > > mp;
int n;
vector<int> v;
void Solve()
{
	v.clear();
	mp.clear();
	scanf("%d",&n);
	FOR(i,n)
	{
		int t;
		scanf("%d",&t);
		v.push_back(t);
	}
	for (int i=1;i<(1<<n);i++)
	{
		vector<int> t;
		int S=0;
		for (int j=0;j<n;j++)
		{
			if (i & (1 << j))
			{
				S+=v[j];
				t.push_back(v[j]);
			}
		}
		mp[S].insert(t);
	}
	
	bool ok = 0;
	vector<int> res[2];
	for (map<int,set<vector<int> > >::iterator it = mp.begin();it != mp.end();it++)
	{
		if (it->second.size() > 1)
		{
			set<vector<int> >::iterator itt = it->second.begin();
			res[0] = *itt;
			itt++;
			res[1] = *itt;
			ok = 1;
			break;
		}
	}
	if (ok)
	{
		FOR(i,res[0].size())
			printf("%d ",res[0][i]);
		printf("\n");
		FOR(i,res[1].size())
			printf("%d ",res[1][i]);
		printf("\n");
	}
	else
	{
		printf("Impossible\n");
	}
}
int main() 
{ 
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		printf("Case #%d:\n",i+1);
		Solve();
		cerr << i << endl;
	}
	return 0; 
}
