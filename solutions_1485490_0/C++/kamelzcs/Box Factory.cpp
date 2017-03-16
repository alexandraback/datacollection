#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<LL> VLL;
int N,M;
vector<PII> box,toy;
int ans=0;
void dfs(int x,int usedX,int y,int usedY,int total)
{
	if(x>=N||y>=M) 
	{
		ans=max(ans,total);
		return;
	}
	if(box[x].second==toy[y].second)
	{
		int added=min(box[x].first-usedX,toy[y].first-usedY);
		if(added) dfs(x,usedX+added,y,usedY+added,total+added);
	}
	
	dfs(x+1,0,y,usedY,total);
	dfs(x,usedX,y+1,0,total);
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;++tt)
	{
		ans=0;
		box.clear();
		toy.clear();
		printf("Case #%d: ",tt);
		cin>>N>>M;
		for(int i=1;i<=N;++i)
		{
			int num,kind;
			cin>>num>>kind;
			box.push_back(make_pair(num,kind));
		}
		for(int j=1;j<=M;++j)
		{
			int num,kind;
			cin>>num>>kind;
			toy.push_back(make_pair(num,kind));
		}
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}