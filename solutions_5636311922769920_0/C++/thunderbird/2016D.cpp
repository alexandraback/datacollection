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


int main()
{
	freopen("D-small-attempt1.in", "r", stdin); freopen("D-small-attempt1.out", "w", stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int testcase;

	ll ans = 0;

	scanf("%d", &testcase);
	for (int case_id = 1; case_id <= testcase; case_id++)
	{
		ans = 0;
		int k, c, s;
		printf("Case #%d: ", case_id);
		scanf("%d %d %d", &k,&c,&s);
		for (int i = 1; i <= k; i++)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}

