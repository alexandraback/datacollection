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


LL rev(LL n)
{
	vector<int> tmp;
	while(n > 0)
	{
		tmp.push_back(n % 10);
		n /= 10;
	}
	LL ans = 0;
	for(int i = 0;i < tmp.size(); ++i)
	{
		ans *= 10;
		ans += tmp[i];
	}

	return ans;
}

LL rec(LL n)
{
	if (n <= 1) return n;
	LL v = n;
	vector<int> nums;
	while(v > 0)
	{
		nums.push_back(v % 10);
		v /= 10;
	}

	int deg = nums.size() / 2;
	reverse(all(nums));
	LL dec = 1;
	

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
	cin>>T;
	map<LL, LL> M;
	LL tmp = 0;
	vector<LL> nines;
	for(int i = 0; i < 18; ++i)
	{
		tmp *= 10;
		tmp += 9;
		nines.push_back(tmp);
	}
	tmp = 9;
	M[9] = 9;
	for(int i = 1; i < 17; ++i)
	{
		tmp *= 10;
		tmp += 9;
		if (i % 2 == 1)
		{
			M[tmp] = (nines[i / 2] - 1 + nines[i / 2] + 1) + M[tmp / 10] + 1;
		}
		else
		{
			M[tmp] = (nines[i /2 - 1] - 1 + nines[i / 2] + 1) + M[tmp / 10] + 1;
		}
	}


	forn(asdasd, 0, T)
	{
		LL N;
		scanf("%I64d", &N);
		//N = asdasd + 1;
		if (N <= 10)
		{
			printf("Case #%d: %I64d\n", asdasd + 1, N);
			continue;
		}
		LL add = 0;
		if (N % 10 == 0) {add++;N--;}
		if (M.count(N))
		{
			printf("Case #%d: %I64d\n", asdasd + 1, M[N] + add);
			continue;
		}

		int nine = -1;
		for(int i = 0; i < nines.size(); ++i)
		{
			if (nines[i + 1] > N) {nine = i;break;}
		}

		LL result = 999999999999999999;
		tmp = N;
		vector<int> nums;

		while(tmp > 0)
		{
			nums.push_back(tmp % 10);
			tmp /= 10;
		}
		reverse(all(nums));
		result = min(result, M[nines[nine]] + (N - nines[nine]));
		for(int i = 1; i < nums.size(); ++i)
		{
			LL vleft = 0;
			LL vright = 0;
			for(int j = i - 1; j >= 0; --j)
			{
				vleft *= 10;
				vleft += nums[j];
			}
			for(int j = i; j <nums.size(); ++j)
			{
				vright *= 10;
				vright += nums[j];
			}
			if (vright == 0) continue;
			result = min(result, vleft + 1 + (vright - 1) + M[nines[nine]] + 1);
		}

		printf("Case #%d: %I64d\n", asdasd + 1, result + add);
	}

    return 0;
}