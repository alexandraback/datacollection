#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

const long long MAXN = (long long)1e14;

long long p[39] = {
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004};

int t;
vector <long long> ans;
vector <int> c;
long long a, b;

bool palindrome(long long x) {
	c.clear();
	while (x) {
		c.push_back(x % 10);
		x /= 10;
	}
	int i = 0, j = (int)c.size() - 1;
	while (i < j) {
		if (c[i] != c[j]) 
			return false;
		i++; j--;
	}
	return true;
}

void calc() {
	for (int i = 1; (long long)1LL * i * i <= MAXN; i++) {
		if (palindrome(i) && palindrome((long long)1LL * i * i)) {
			ans.push_back((long long)1LL * i * i);
			cout << 1LL * i * i << endl;
		}
	}
}

int main() {
	freopen("C-large-1.in","r",stdin);
	freopen("output.txt","w",stdout);

	//calc();

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%I64d %I64d", &a, &b);
		int curans = 0;
		for (int i = 0; i < 39; i++) 
			if (p[i] >= a && p[i] <= b) 
				curans++;
		printf("Case #%d: %d\n", test, curans);
	}

	return 0;
}