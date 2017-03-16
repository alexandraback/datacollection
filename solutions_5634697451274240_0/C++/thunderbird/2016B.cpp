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

ll GetAns(string s, char f)
{
	int ret = 0;
	int last = s.length() - 1;
	while (last>=0&&s[last] == f )
	{
		last--;
	}
	if (last == -1) return 0;
	return 1 + GetAns(s.substr(0, last + 1), f == '+' ? '-' : '+');
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int testcase;

	ll ans = 0;

	scanf("%d", &testcase);
	for (int case_id = 1; case_id <= testcase; case_id++)
	{
		ans = 0;
		string s;
		printf("Case #%d: ", case_id);
		cin >> s;
		ans = GetAns(s, '+');


		printf("%d", ans);
		printf("\n");
	}
	return 0;
}

