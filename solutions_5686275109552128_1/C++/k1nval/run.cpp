#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
//#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
const int MAX = 2147483647;
const int MAXN = 205000;
typedef long long LL;
const LL MOD = 1000000000 + 7;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	int TC;
	scanf("%d", &TC);
	forn(tc, 0, TC){
		int d;
		
		scanf("%d", &d);
		vector<int> p(d);
		forn(i,0,d)
		{
			scanf("%d", &p[i]);
		}
		int ans = 1000000000;
		for(int i = 1; i <= 1000; ++i)
		{
			int plus = 0;
			for(int j = 0; j < p.size(); ++j)
			{
				if(p[j] > i)
				{
					plus += (((p[j] - i) - 1) / i) + 1;
				}
			}

			ans = min(ans, i + plus);
		}


		printf("Case #%d: ", tc + 1);
		printf("%d\n", ans);

	}
	
    return 0;
}