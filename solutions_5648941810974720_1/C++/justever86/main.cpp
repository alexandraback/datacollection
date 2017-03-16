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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

#define	sqr(a)		((a)*(a))
#define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
#define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
#define	PER(i,n)	per(i,n,0)
#define	REP(i,n)	rep(i,0,n)
#define	clr(a)		memset((a),0,sizeof (a))
#define	SZ(a)		((int)((a).size()))
#define	ALL(x)		x.begin(),x.end()
#define	mabs(a)		((a)>0?(a):(-(a)))
#define	inf			(0x7fffffff)
#define	eps			1e-6

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;

#define TEST_LOCAL 1

char s[2001];
int c[10][26];
int r[26];
char ss[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void init()
{
	clr(c);
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;ss[i][j];j++)
		{
			c[i][ss[i][j] - 'A']++;
		}
	}
}

bool dfs(int x,vector<int>& res)
{
	if (x == 10)
	{
		for (int i = 0;i < 26;i++)
		{
			if (r[i] != 0)
			{
				return false;
			}
		}
		return true;
	}

	int begin = 0;

	if (x == 0)
	{
		begin = r['Z' - 'A'];
	}
	if (x == 2)
	{
		begin = r['W' - 'A'];
	}
	if (x == 4)
	{
		begin = r['R' - 'A'];
	}
	if (x == 5)
	{
		begin = r['F' - 'A'];
	}
	if (x == 6)
	{
		begin = r['X' - 'A'];
	}
	if (x == 7)
	{
		begin = r['V' - 'A'];
	}
	if (x == 8)
	{
		begin = r['G' - 'A'];
	}
	if (x == 9)
	{
		begin = r['I' - 'A'];
	}

	for (int i = begin;;i++)
	{
		int flag = 1;
		for (int j = 0;j < 26;j++)
		{
			if (r[j] < i * c[x][j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
		res.push_back(i);

		for (int j = 0;j < 26;j++)
		{
			r[j] -= i * c[x][j];
		}

		bool tt = dfs(x + 1,res);
		if (tt)
		{
			return true;
		}

		for (int j = 0;j < 26;j++)
		{
			r[j] += i * c[x][j];
		}
		res.pop_back();
	}
	return false;
}

int main()
{
#if TEST_LOCAL
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif

	int T;
	scanf("%d",&T);

	rep(CASE,1,T + 1)
	{
		scanf("%s",s);
		init();
		clr(r);
		for (int i = 0;s[i];i++)
		{
			r[s[i] - 'A']++;
		}
		vector<int> res;

		bool bb = dfs(0,res);
		if (!bb)
		{
			return 0;
		}

		printf("Case #%d: ",CASE);
		string rt = "";
		for (int i = 0;i < 10;i++)
		{
			for (int j = 0;j < res[i];j++)
			{
				rt += i + '0';
			}
		}
		printf("%s\n",rt.c_str());
	}

	return 0;
}
