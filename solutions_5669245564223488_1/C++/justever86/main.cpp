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
#define MODN		(1000000007LL)

typedef long long ll;

long long f[105];

void dd()
{
	f[0] = 1;
	f[1] = 1;
	rep(i,2,102)
	{
		f[i] = f[i - 1] * i;
		f[i] %= MODN;
	}
}

int solve(vector<string> v)
{
	int n = v.size();
	int cc[30][4];
	clr(cc);
	int mp[30][30];
	clr(mp);
	REP(i,n)
	{
		int l = v[i].length();
		int flag = 1;
		if (l != 1 && v[i][0] == v[i][l - 1])
		{
			return 0;
		}
		if (l != 1)
		{
			mp[v[i][0] - 'a'][v[i][l - 1] - 'a']++;
		}
		
		
		REP(j,l)
		{
			int flag = 0;

			per(k,j,0)
			{
				if (v[i][k] != v[i][j])
				{
					flag |= 1;
					break;
				}
			}

			rep(k,j + 1,l)
			{
				if (v[i][k] != v[i][j])
				{
					flag |= 2;
					break;
				}
			}

			int x = v[i][j] - 'a';
			if (flag == 0)
			{
				cc[x][0]++;
				if (cc[x][3] > 0)
				{
					return 0;
				}
				break;
			}
			else if (flag == 1)
			{
				if (j == l - 1)
				{
					cc[x][1]++;
					if (cc[x][1] > 1 ||
						cc[x][3] > 0)
					{
						return 0;
					}
				}
			}
			else if (flag == 2)
			{
				if (j == 0)
				{
					cc[x][2]++;
					if (cc[x][2] > 1 ||
						cc[x][3] > 0)
					{
						return 0;
					}
				}
				
			}
			else
			{
				cc[x][3]++;
				if (cc[x][0] > 0 ||
					cc[x][1] > 0 ||
					cc[x][2] > 0)
				{
					return 0;
				}
			}
		}
	}

	REP(i,26)
	{
		REP(j,26)
		{
			REP(k,26)
			{
				if (mp[j][i] > 0 && mp[i][k] > 0)
				{
					mp[j][k] = 1;
				}
			}
		}
	}

	REP(i,26)
	{
		REP(j,26)
		{
			if (mp[i][j] > 0 && mp[j][i] > 0)
			{
				return 0;
			}
		}
	}

	long long res = 1;
	int temp = 0;
	REP(i,26)
	{
		if (cc[i][2] == 1 &&
			cc[i][1] == 0)
		{
			temp++;
		}
		if (cc[i][0] != 0)
		{
			if (cc[i][1] == 0 && cc[i][2] == 0)
			{
				temp++;
			}

			res *= f[cc[i][0]];
			res %= MODN;
		}
	}
	res *= f[temp];
	res %= MODN;

	return res;
}

int solve2(vector<string> v)
{
	int n = v.size();

	vector<int> r;
	int cc = 1;
	REP(i,n)
	{
		r.push_back(i);
		cc *= i + 1;
	}
	int res = 0;
	while (cc)
	{
		cc--;

		string s = "";
		REP(i,n)
		{
			s += v[r[i]];
		}

		int l = s.length();
		int t[30];
		clr(t);
		int flag = 1;
		REP(i,l)
		{
			if (i == 0 || s[i] != s[i - 1])
			{
				t[s[i] - 'a']++;
				if (t[s[i] - 'a'] > 1)
				{
					flag = 0;
					break;
				}
			}
		}
		res += flag;

		next_permutation(r.begin(),r.end());
	}

	return res;
}

int main()
{
#if 1
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif

	int CASE;
	scanf("%d",&CASE);
	dd();
	
	for (int K = 1;K <= CASE;K++)
	{
		int n;
		scanf("%d",&n);

		vector<string> v;

		REP(i,n)
		{
			char s[105];
			scanf("%s",s);
			string t = "";
			int l = strlen(s);
			REP(j,l)
			{
				if (j == 0 || s[j] != s[j - 1])
				{
					t += s[j];
				}
			}
			v.push_back(t);
		}

		int res = solve(v);
		//int res2 = solve2(v);

		//printf("%d %d\n",res,res2);
		//if (res != res2)
		//{
			//break;
		//}

		printf("Case #%d: ",K);
		printf("%d\n",res);
	}

	return 0;
}
