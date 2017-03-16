#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <ctime>

using namespace std;

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make_triple(x,y,z) make_pair((x), make_pair((y),(z)))
#define fr first
#define sc second
#define ts second.first
#define td second.second

typedef long long ll;
typedef unsigned long long ull; 
typedef double ld;

const long double eps = 1e-9;
const int inf = LONG_MAX;
const ll inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;

#define N 40000

int main()
{
	freopen("output1.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ld c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		if (x <= c)
		{
			printf("Case #%d: %.7lf\n", i+1, x/2);
			continue;
		}
		ld ans = c/2.0;
		ld sp = 2.0;
		ld temp = f*(x-c)/c;
		while(temp > sp)
			sp += f, ans += c/sp;
		ans += (x-c)/sp;
		printf("Case #%d: %.7lf\n", i+1, ans);	
	}
	return 0;	
}