#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;
bool flg[10];
bool fillflg(ll n)
{
	bool c = true;
	if (n == 0)
		flg[0] = true;
	while (n > 0)
	{
		int tmp = n % 10;
		flg[tmp] = true;
		n /= 10;
	}
	for (int i = 0; i < 10;i++)
		if (!flg[i])
			return false;
	return c;
}
ll GetAns(int n)
{
	bool c = fillflg(n);
	int l = 0;
	int tmp = n;
	int max = 1;
	while (tmp > 0)
	{
		l++;
		tmp /= 10;
	}
	for (int i = 0; i <= l; i++)
		max *= 10;
	for (int i = 2; i<=max+1; i++)
	{
		ll ret =1L*n*i;
		if (fillflg(ret))
			return ret;
	}
	return -1;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int testcase;

	ll ans = 0;
	
	scanf("%d", &testcase);
	for (int case_id = 1; case_id <= testcase; case_id++)
	{
		ans = 0;
		int n = 0;
		printf("Case #%d: ", case_id);
		scanf("%d", &n);
		for (int i = 0; i < 10; i++)
			flg[i] = false;
		ans = GetAns(n);
		if (ans==-1)
			printf("%s", "INSOMNIA");
		else
			printf("%d", ans);
		printf("\n");
	}
	return 0;
}

