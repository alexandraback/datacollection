#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long long ull;

#define REPI(i,s,n)  	for(int i=s;i<(n);++i)
#define FORI(i, n)		REPI(i, 0, n)

vector<ull> nChoosen(ull max, ull n, ull m)
{
	ull total=0;
	vector<ull> pick;
	if(max == 1)
	{
		pick.resize(n, 2);
		return pick;
	}

	for(int i = m; i >= 2; )
	{
		if(max%i == 0)
		{
			max /=i;
			total++;
			pick.push_back(i);
			if((total == n) && (max == 1))
				return pick;
		}
		else
			i--;
	}
	if((total == n) && (max == 1))
		return pick;
	else
	{
		pick.resize(n, 2);
		return pick;
	}
}

int main()
{

#if 0
	freopen("..//Debug//goodluckinput.in", "r", stdin); 
	freopen("..//Debug//goodluckout.txt", "w", stdout);
#endif
	int tc=0;
	ull max=0;
	ull K = 0, M=2, R=0, N=0;
	vector<ull> vi;
	scanf("%d\n", &tc);
	FORI(i, tc)
	{
		scanf("%llu %llu %llu %llu\n", &R, &N, &M, &K);
		printf("Case #%d:\n", i+1);
		FORI(r, R)
		{
			max=0;
			FORI(k, K)
			{
				ull v;
				scanf("%llu", &v);
				if(v > max)
					max = v;
				vi.push_back(v);
			}

			vector<ull> newv = nChoosen(max, N, M);
			for(int ii=0; ii < newv.size(); ii++)
			{

				printf("%llu", newv[ii]);
			}
			printf("\n");
			vi.erase(vi.begin(), vi.end());
		}
		//sort(vi.begin(), vi.end(), std::greater<int>());
		

	}
	//====//
	return getchar();
}