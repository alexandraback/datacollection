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

const int MAXN = 1000;

int t;
int d[105000];
bool ok[105000];
vector <int> c;
int a, b;

bool palindrome(int x) {
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
	for (int i = 1; i * i <= MAXN; i++) {
		if (palindrome(i) && palindrome(i * i))
			ok[i * i] = true;
	}
	for (int i = 1; i <= MAXN; i++) 
		d[i] = d[i - 1] + ok[i];
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	calc();

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", test, d[b] - d[a - 1]);
	}

	return 0;
}