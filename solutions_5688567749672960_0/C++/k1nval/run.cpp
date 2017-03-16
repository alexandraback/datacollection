#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <hash_map>
#include <string>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <stack> 
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
const int MAX = 2147483647;
const int MAXN = 1000000 + 10000;
typedef long long LL;
const LL MOD = 1000000000 + 7;

LL d[MAXN];
LL N;
int fact(int n)
{
	if (n == 0) return 1;
	return n * fact(n - 1);
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("f.in", "r", stdin); freopen("f.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	mems(d, 127);
	d[1] = 1;
	queue<pair<int,int> > q;
	q.push(mp(1,1));
	while(q.size() > 0)
	{
		vector<int> nums;
		pair<int,int> v = q.front();
		q.pop();
		int cur = v.first;
		if (d[v.first] < v.second) continue;

		if (v.first + 1 < MAXN && d[v.first + 1] > v.second + 1)
		{
			d[v.first + 1] = v.second + 1;
			q.push(mp(v.first + 1, v.second + 1));
		}

		while(v.first > 0)
		{
			nums.push_back(v.first % 10);
			v.first /= 10;
		}

		//for(int i = 0; i < fact(nums.size()); ++i)
		{
			int tmp = 0;

			for(int j = 0; j < nums.size(); ++j)
			{
				tmp *= 10;
				tmp += nums[j];
			}

			if (tmp >= MAXN) continue;
			
			if (d[tmp] > v.second + 1)
			{
				d[tmp] = v.second + 1;
				q.push(mp(tmp, v.second + 1));
			}

			//next_permutation(all(nums));
		}
	}

	forn(asdasd, 0, T)
	{
		
		scanf("%I64d", &N);



		printf("Case #%d: %I64d\n", asdasd + 1, d[N]);
	}

    return 0;
}