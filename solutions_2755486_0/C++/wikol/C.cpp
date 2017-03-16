#include <cstdio>
#include <algorithm>
#include <vector>
#define FOREACH(i,c) for(__typeof(c.end()) i = c.begin();i!=c.end();++i)

using namespace std;

int T[2000000];
int MID = 1000000;

struct Attack
{
	int t,w,e,s;
	Attack(int t, int w, int e, int s)
	{
		this->t = t;
		this->w = w;
		this->e = e;
		this->s = s;
	}
};
bool operator<(const Attack &a, const Attack &b)
{
	if(a.t == b.t)
		return a.s < b.s;
	return a.t < b.t;
}
vector<Attack> A;
void clear()
{
	A.clear();
	for(int i = 0;i<2000000;i++)
		T[i] = 0;
}
int update(Attack a)
{
	int toRet = 0;
	for(int i = MID+a.w;i<MID+a.e;i++)
	{
		if(T[i] < a.s)
			toRet = 1;
		T[i] = max(T[i],a.s);
	}
	return toRet;
}
void read()
{
	clear();
	int N;
	scanf("%d", &N);
	for(int i = 0;i<N;i++)
	{
		int d,n,w,e,s,dd,dp,ds;
		scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
		for(int j = 0;j<n;j++)
			A.push_back(Attack(d + j*dd, w + j*dp, e + j*dp, s + j*ds));
	}
	sort(A.begin(), A.end());
}
void solve(int tc)
{
	int res = 0;
	FOREACH(i, A)
		res += update(*i);
	printf("Case #%d: %d\n", tc,res);
}
int main()
{
	int Z;
	scanf("%d", &Z);
	for(int i = 1;i<=Z;i++)
	{
		read();
		solve(i);
	}
	return 0;
}
