#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int canonize(int a)
{
	static char temp[30];
	snprintf(temp, 30, "%d", a);
	string s(temp);
	int result = a;
	for (int i = 0; i < s.size(); i++) {
		result = min(result, atoi(s.c_str()));
		rotate(s.begin(), s.begin()+1, s.end());
	}
	return result;
}

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int test = 0; test < ntest; test++) {
		int left, right;
		lint ret = 0;

		scanf("%d %d", &left, &right);
		
		map <int, lint> many;
		for (int a = left; a <= right; a++)
			ret += many[canonize(a)]++;

		printf("Case #%d: %lld\n", test+1, ret);
	}

	return 0;
}
