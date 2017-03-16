#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

void openfiles()
{
#ifndef ONLINE_JUDGE
	freopen("test.in","rt",stdin);
	freopen("test.out","wt",stdout);
#endif
}

int getlen(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

int pow10(int n) {
	int out = 1;
	for (int i = 0; i < n; i++) {
		out *= 10;
	}
	return out;
}

int getLastN(int a, int n) {
	int m = 1, r = 0;
	for (int i = 0; i < n; i++) {
		r += m * (a % 10);
		a /= 10;
		m *= 10;
	}
	return r;
}

bool validate(int a, int b, int A) {
	int len = getlen(b);
	assert(getlen(a) == getlen(b));

	bool found = false;
	for (int i = 1; i < len; i++) {
		char x[10];
		sprintf(x, "%d", a);
		char y[10];
		for (int j = len - i; j < len; j++) {
			y[j - len + i] = x[j];
		}
		for (int j = 0; j < len - i; j++) {
			y[i + j] = x[j];
		}
		//cout << a << " " << b << endl;
		if (atoi(y) == b) found = true;
	}
	return found;
}

int process(int A, int b) {
	int len = getlen(b);
	int cnt = 0;
	set<int> done;	
	for (int i = 1; i < len; i++) {
		//cout << b << " " << i << endl;
		int a = getLastN(b, i);
		//cout << a << " ";
		a *= pow10(len - i);
		//cout << a << " ";
		a += b / pow10(i);
		//cout << a << " ";
		if (a >= A && a < b && a >= pow10(len - 1) && done.find(a) == done.end()) {
			//cout << b << " " << a << endl;
			cnt++;
			done.insert(a);
			assert(validate(a, b, A));
		}
		//cout << endl;
	}
	return cnt;
}
	
void solve(int test)
{
	int A, B; scanf("%d %d ", &A, &B);
	int sum = 0;
	for (int b = A; b <= B; b++) {
		sum += process(A, b);
	}
	static int ntest = 0;
	printf("Case #%d: %d\n", ++ntest, sum);
}

int main()
{
	openfiles();
	int n; scanf("%d ",&n); REP(i,n) solve(i + 1);
	
	return 0;
}