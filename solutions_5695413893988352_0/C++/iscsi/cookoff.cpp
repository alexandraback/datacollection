#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stack>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define pb push_back

LL calc(const string& s)
{
	int N = s.size();
	LL res = 0;
	REP(i,N)
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

int main(int argv, char** argc) {
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("B-small-attempt3.out", "w", stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	char cc1[23], cc2[23];
	FOR(tc, 1, T + 1)
	{
		scanf("%s %s", cc1, cc2);
		int N = strlen(cc1);
		string c1(cc1), c2(cc2);
		int fd = -1;
		REP(i, N)
		{
			if (c1[i] != c2[i] && c1[i] != '?' && c2[i] != '?')
			{
				fd = i;
				break;
			}
		}
		if (fd == -1)
		{
			REP(i, N) if(c1[i]=='?')
			{
				if (c2[i] == '?')
					c2[i] = '0';
				c1[i] = c2[i];
			}
			printf("Case #%d: %s %s\n", tc, c1.c_str(), c1.c_str());
			continue;
		}
		bool swaped = 0;
		if(c1[fd]<c2[fd])
		{
			swaped = 1;
			REP(i, N)
			{
				swap(c1[i], c2[i]);
			}
		}
		
		string oc1(c1), oc2(c2);
		//c1[fd]>c2[fd]
		//1.eset
		//c1 > c2
		REP(i, fd)
		{
			if (c1[i] == '?')
			{
				if (c2[i] == '?')
					c2[i] = '0';
				c1[i] = c2[i];
			}
			if (c2[i] == '?')
				c2[i] = c1[i];
		}
		FOR(i,fd + 1, N)
		{
			if (c1[i] == '?')
				c1[i] = '0';
			if (c2[i] == '?')
				c2[i] = '9';
		}
		LL a1 = calc(c1), a2 = calc(c2);
		string ca1 = c1, ca2 = c2;
		//2.eset c1<c2
		c1 = oc1, c2 = oc2;
		bool found = 0;
		for (int i = fd - 1; i > -1;--i)
		{
			if (c1[i] == '?' && c2[i] == '?' && !found) 
			{
				c1[i] = '0';
				c2[i] = '1';
				found = 1;
			}
			else if (c1[i] == '?' && !found)
			{
				if (c2[i] > '0')
				{
					c1[i] = c2[i] - 1;
					found = 1;
				}
				else
				{
					c1[i] = '0';
				}
			}
			else if (c2[i] == '?' && !found)
			{
				if (c1[i] < '9')
				{
					c2[i] = c1[i] + 1;
					found = 1;
				}
				else
				{
					c2[i] = c1[i];
				}
			}
			else
			{
				if (c1[i] == '?')
				{
					if (c2[i] == '?')
						c2[i] = '0';
					c1[i] = c2[i];
				}
				if (c2[i] == '?')
				{
					c2[i] = c1[i];
				}
			}
		}
		FOR(i, fd + 1, N)
		{
			if (c1[i] == '?')
				c1[i] = '9';
			if (c2[i] == '?')
				c2[i] = '0';
		}
		LL b1 = calc(c1), b2 = calc(c2);
		if (swaped)
		{
			ca1.swap(ca2);
			c1.swap(c2);
			swap(a1,a2);
			swap(b1,b2);
		}
		if (ABS(a1 - a2) == ABS(b1 - b2))
		{
			if (a1 < b1 || (a1==b1 && a2<b2))
			{
				printf("Case #%d: %s %s\n", tc, ca1.c_str(), ca2.c_str());
			}
			else
			{
				printf("Case #%d: %s %s\n", tc, c1.c_str(), c2.c_str());
			}
		}
		else if(ABS(a1-a2)<ABS(b1-b2))
		{
			printf("Case #%d: %s %s\n", tc, ca1.c_str(), ca2.c_str());
		}
		else
		{
			printf("Case #%d: %s %s\n", tc, c1.c_str(), c2.c_str());
		}
	}
	return 0;
}