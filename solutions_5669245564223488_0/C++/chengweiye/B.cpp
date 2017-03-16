#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0

#define NUM 101
const long long MOD = 1000000007;
int dir[NUM][NUM];
int mask[NUM];
int mask2[NUM];
int con[4];
int ff;
int ee;
int N;
bool ok;
bool go(int index)
{
	if (mask[index])
	{
		return false;
	}
	if (mask2[index])
	{
		ok = false;
		return false;
	}
	mask[index] = true;
	mask2[index] = true;
	bool res = true;
	for (int i = 0; i < N; i++)
	{
		if (dir[index][i]!=0)
		{
			if (!go(i))
			{
				res = false;
			}
		}
	}
	return res;;
}
bool calc(string t, char c, int index)
{
	int len = t.length();
	bool first = false;
	bool last = false;
	bool middle = false;
	bool truemid = false;
	char pre = '\0';
	for (int i = 0; i < len; i++)
	{
		if ((t.c_str()[i] >= 'a') && (t.c_str()[i] <= 'z'))
		{
			char cur = t.c_str()[i];
			if (pre == '\0')
			{
				if (cur == c)
				{
					first = true;
				}
				pre = cur;
			}
			if ((pre != c) && (cur == c))
			{
				if (first || truemid)
				{
					ok = false;
					return false;
				}
				middle = true;
			}
			if ((pre == c) && (cur != c))
			{
				if (middle)
				{
					truemid = true;
				}
			}
			pre = cur;
		}
		else
		{
			continue;
		}
	}
	if (pre == c)
	{
		last = true;
	}
	if (first&&last)
	{
		con[3]++;
	}
	else if (truemid)
	{
		con[2]++;
	}
	else if (first)
	{
		con[0]++;
		ff = index;
	}
	else if (last)
	{
		con[1]++;
		ee = index;
	}
	return true;
}
int main()
{
	FILE *fin;
	FILE *fout;
	//files
	freopen_s(&fin,"in.txt", "r", stdin);
	if (!DEBUG)
		freopen_s(&fout,"out.txt", "w", stdout);
	//vars
	int tt, TT;
	//testcase loop
	string t;
	cin >> t;
	TT = atoi(t.c_str());
	For(tt, TT)
	{
		//init
		printf("Case #%d: ", tt + 1);
		for (int i = 0; i < NUM;i++)
		for (int j = 0; j < NUM; j++)
		{
			dir[i][j] = 0;
		}
		cin >> t;
		N = atoi(t.c_str());
		vector<string> vs;
		vs.clear();
		for (int i = 0; i < N; i++)
		{
			cin >> t;
			vs.push_back(t);
		}
		int same[26];
		for (int i = 0; i < 26; i++)
		{
			same[i] = 0;
		}
		ok = true;
		int component = 0;
		for (char c = 'a'; c <= 'z'; c++)
		{
			for (int i = 0; i < 4; i++)
			{
				con[i] = 0;
			}
			for (int i = 0; i < vs.size(); i++)
			{
				calc(vs[i], c,i);
			}
			if (!ok)
			{
				break;
			}
			if (con[2]>1)
			{
				ok = false;
			}
			if ((con[2] != 0) && ((con[0] + con[1] + con[3]) != 0))
			{
				ok = false;
			}
			if ((con[0] > 1) || (con[1] > 1))
			{
				ok = false;
			}
			if ((con[0] == 1) && (con[1] == 1))
			{
				dir[ee][ff] = 1;
			}
			if (((con[0] + con[1]) > 0) && (con[3] > 0))
			{
				component--;
			}
			if (con[3] > 1)
			{
				component -= con[3] - 1;
			}
			same[c-'a'] = con[3];
		}
		if (ok)
		{
			for (int i = 0; i < N; i++)
			{
				mask[i] = 0;
			}
			for (int i = 0; i < N; i++)
			{
				if (mask[i] == 0)
				{
					for (int i = 0; i < N; i++)
					{
						mask2[i] = 0;
					}
					if (go(i))
					{
						component++;
					}
				}
			}

		}
		if (!ok)
		{
			printf("0\n");
		}
		else
		{
			long long res = 1;
			for (int i = 1; i <= component; i++)
			{
				res = res*i;
				res %= MOD;
			}
			for (int i = 0; i < 26; i++)
			{
				long long ttx = 1;
				for (int j = 1; j <= same[i]; j++)
				{
					res = res*j;
					res %= MOD;
				}
			}
			printf("%lld\n", res);

		}

	}
	return(0);
}