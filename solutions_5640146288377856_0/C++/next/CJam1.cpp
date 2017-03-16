#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>

using namespace std;

#define ll long long
#define ld long double
#define pr pair<int,int>

#define fox(i,n) for (i=0; i<n; i++)
#define fox1(i,n) for (i=1; i<=n; i++)
#define foxI(i,a,b) for (i=a; i<=b; i++)
#define foxR(i,n) for (i=(n)-1; i>=0; i--)
#define foxR1(i,n) for (i=n; i>0; i--)
#define foxRI(i,a,b) for (i=b; i>=a; i--)
#define foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

ofstream ofile;
ifstream ifile("A-small-attempt4.in");

struct P
{
	int x;
	int y;
	int g;
};

bool comp(P a, P b)
{
	return a.g > b.g;
}

void solve()
{
	int r, c, w, i, count1 = 0, ans = 0;
	ifile>>r>>c>>w;
	//int ans = (w - 1) + r * (c - w + 1);
	i = w;
	while(i <= c)
	{
		++count1;
		i += w;
	}
	int tmp = count1 * r;
	if(count1 * w != c)
		ans = tmp + w;
	else
		ans = tmp + w - 1;
	//ans = count1 + w;
	ofile<<ans<<endl;
}

int main()
{
	ofile.open("output.out");
	int t, cases = 0;
	ifile>>t;
	while(t--)
	{
		ofile<<"Case #"<<++cases<<": ";
		solve();
	}
	return 0;
}