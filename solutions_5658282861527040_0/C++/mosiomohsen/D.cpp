#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

#define CLR(a,x) memset(a,x,sizeof a)
#define LL long long
#define ALL(v) v.begin(),v.end()
#define FR(i,n) for(LL i=0;i<(LL)n;i++)
#define FAB(i,a,b) for(LL i=(LL)a;i<(LL)b;i++)
#define FBA(i,b,a) for(LL i=(LL)b;i>=(LL)a;i--)
#define IIN(x) scanf("%d",&x)
#define IIN2(x,y) scanf("%d%d",&x,&y)
#define LIN(x) scanf("%I64d",&x)
#define LIN2(x,y) scanf("%I64d%I64d",&x,&y)
#define EXIT(n) {cout<<n<<endl;return 0;}
#define PII pair<int,int>
#define PPI pair<PII,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define PDI pair<double,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PI 3.141592653589793238
#define VI vector<int>
#define VLL vector<long>
#define VPL vector<PLL>
#define VS vector<string>
#define SI set<int>
#define SLL set<LL>
#define SPL set<PLL>
#define SS set<string>
#define MII map<int,int>
#define MLL map<LL,LL>
#define MPL map<PLL,LL>
#define MSI map<string,int>
#define MSL map<string,LL>
#define MIS map<int,string>
#define INF 10000000000000
#define MOD 1000000007
#define MAX 10*1000+10

int q,tc;
int a,b,k,res;
vector<PII> v[MAX];

void input()
{
	cin>>a>>b>>k;
	FR(i,MAX) v[i].clear();
}

void solve()
{
	res=0;
	FR(i,a)FR(j,b) v[i&j].push_back(PII(i,j));
	FR(i,k) res+=v[i].size();
}

void output()
{
	printf("Case #%d: %d\n",q,res);

}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>tc;
	for(q=1;q<=tc;q++)
	{
		input();
		solve();
		output();
	}

	return 0;
}