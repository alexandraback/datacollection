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

char s[19],t[19];

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
		scanf("%s %s",s,t);
		int x1 = strlen(s);
		int x2 = strlen(t);

		string ls = "";
		string lt = "";
		int lr = 1000;

		for (int i = 0;i < 1000;i++)
		{
			char s1[20];
			char s2[20];
			sprintf(s2,"%%0%dd",x1);
			sprintf(s1,s2,i);

			int sf = 1;
			for (int r = 0;r < x1;r++)
			{
				if (s[r] == '?' || s[r] == s1[r])
				{

				}
				else
				{
					sf = 0;
					break;
				}
			}
			if (!sf || strlen(s1) != x1)
			{
				continue;
			}

			for (int j = 0;j < 1000;j++)
			{
				char t1[20];
				char t2[20];
				sprintf(t2,"%%0%dd",x2);
				sprintf(t1,t2,j);

				int tf = 1;
				for (int r = 0;r < x2;r++)
				{
					if (t[r] == '?' || t[r] == t1[r])
					{

					}
					else
					{
						tf = 0;
						break;
					}
				}
				if (!tf || strlen(t1) != x2)
				{
					continue;
				}

				int del = abs(i - j);
				if (del < lr)
				{
					lr = del;
					ls = s1;
					lt = t1;
				}
			}
		}

		printf("Case #%d: ",CASE);
		printf("%s %s\n",ls.c_str(),lt.c_str());
	}

	return 0;
}
