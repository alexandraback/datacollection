#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cassert>
#define CLRM(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define GI(x) scanf("%d", &x);
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FOR(i, start, end) for(int i = start; i < end; i++)
#define PB push_back
#define MP make_pair
#define VI vector<int> 
#define VVI vector<vector<int> >
#define PII pair<int,int>
#define SZ(x) (int)x.size()
#define LL long long
#define PLL pair<LL,LL>
#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
#define LMAX 1000000000000000000LL
#define IMAX 1000000000
using namespace std;
struct state
{
	LL bcount, bpos;
	LL tcount, tpos;
};
struct comp
{
	bool operator() (const struct state& lhs, const struct state& rhs)
	{
		if(lhs.bpos < rhs.bpos)
			return true;
		if(lhs.tpos < rhs.tpos)
			return true;
		if(lhs.bcount< rhs.bcount)
			return true;
		if(lhs.tcount< rhs.tcount)
			return true;
		return false;
	}
};
			
#define MAXN 110
int N, M;
map<struct state, LL, comp> dp;
PLL box[MAXN], toy[MAXN];

LL solve(struct state s)
{
	if(s.bpos == N || s.tpos == M)
		return 0;
	if(dp.find(s) != dp.end())
	{
		return dp[s];
	}
	//cout<<"Counts : " <<s.bcount<<" "<<s.tcount<<endl;
	LL ret = 0;
	struct state nxt = s;
	if(box[s.bpos].second != toy[s.tpos].second)
	{
		nxt = s;
		nxt.tpos = s.tpos+1;nxt.tcount=toy[nxt.tpos].first;
		ret = max(ret, solve(nxt));
		nxt = s;
		nxt.bpos = s.bpos+1;nxt.bcount=box[nxt.bpos].first;
		ret = max(ret, solve(nxt));
	}
	else
	{
		LL take = MIN(s.bcount, s.tcount);
		nxt = s;
		nxt.tcount -= take;
		nxt.bcount -= take;
		if(nxt.tcount == 0)
		{
			nxt.tpos = s.tpos+1;
			nxt.tcount = toy[nxt.tpos].first;
		}
		if(nxt.bcount == 0)
		{
			nxt.bpos = s.bpos+1;
			nxt.bcount = box[nxt.bpos].first;
		}
		ret = max(ret, solve(nxt) + take);
	}
	dp[s] = ret;
	return ret;
}
			
int main()
{
	int tes;
	GI(tes);
	FORN(c, tes)
	{
		dp.clear();
		GI(N); GI(M);
		FORN(i, N)
		{
			LL a, b;
			cin >> a >> b;
			box[i] = make_pair(a, b);
		}
		FORN(i, M)
		{
			LL a, b;
			cin >> a >> b;
			toy[i] = make_pair(a, b);
		}
		struct state start;
		start.bcount = box[0].first;
		start.bpos = 0;
		start.tpos = 0;
		start.tcount = toy[0].first;
		LL ans = solve(start);
		printf("Case #%d: ", c+1);
		cout<<ans<<endl;
	}
	return 0;
}




