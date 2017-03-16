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
		char a[5000];
		int n;
		scanf("%d %s", &n, &a);
		vector<int> b;
		forn(i,0,n + 1) {
			forn(j,0,a[i] - '0')
			{
				b.push_back(i);
			}
		}
		sort(all(b));
		int counter = 0;
		for(int i = 0; i < b.size(); ++i)
		{
			while (b[i] > (i + counter)){
				counter++;
			}
		}



		printf("Case #%d: ", tc + 1);
		printf("%d\n", counter);

	}
	
    return 0;
}