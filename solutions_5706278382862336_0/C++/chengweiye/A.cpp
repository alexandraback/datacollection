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

void getPQ(string t, long long *P, long long *Q)
{
	int len = t.length();
	*P = 0;
	*Q = 0;
	bool first = true;
	for (int i = 0; i < len; i++)
	{
		if ((t.c_str()[i] >= '0') && (t.c_str()[i] <= '9'))
		{
			long long num = t.c_str()[i] - '0';
			if (first)
			{
				*P *= 10;
				*P += num;
			}
			else
			{
				*Q *= 10;
				*Q += num;
			}
		}
		else
		{
			first = false;
		}
	}
}
long long getcommon(long long P, long long Q)
{

	if (Q < P)
	{
		return getcommon(Q, P);
	}
	if (P == 0)
	{
		return Q;
	}
	return getcommon(Q%P, P);
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
		cin >> t;
		long long P, Q;
		getPQ(t, &P, &Q);
		long long common = getcommon(P, Q);
		P /= common;
		Q /= common;
		int ttx = 0;
		int res = 0;
		bool first = true;
		while (Q >= 2)
		{
			if ((Q % 2) == 0)
			{
				ttx++;
				Q /= 2;
				if (P >= Q)
				{
					if (first)
					{
						res = ttx;
						first = false;
					}
					
				}
			}
			else
			{
				break;
			}
		}
		if (Q==1)
		{
			printf("%d\n",res);
		}
		else
		{
			printf("impossible\n");
		}
		
	}
	return(0);
}