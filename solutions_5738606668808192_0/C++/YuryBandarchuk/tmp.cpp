#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory.h>
#include <cassert>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <complex>
#include <queue>
#include <ctime>
#include <deque>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef vector<int> lnum;
const int base = 1000*1000*1000;

void print(lnum &a) {
	printf ("%d", a.empty() ? 0 : a.back());
for (int i=(int)a.size()-2; i>=0; --i)
	printf ("%09d", a[i]);
}

void add(lnum &a, lnum &b) {
	int carry = 0;
for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
	if (i == a.size())
		a.push_back (0);
	a[i] += carry + (i < b.size() ? b[i] : 0);
	carry = a[i] >= base;
	if (carry)  a[i] -= base;
}
}

void mult(lnum &a, int b) {
	int carry = 0;
for (size_t i=0; i<a.size() || carry; ++i) {
	if (i == a.size())
		a.push_back (0);
	long long cur = carry + a[i] * 1ll * b;
	a[i] = int (cur % base);
	carry = int (cur / base);
}
while (a.size() > 1 && a.back() == 0)
	a.pop_back();
}

int getRem(lnum &a, int b) {
	int carry = 0;
for (int i=(int)a.size()-1; i>=0; --i) {
	long long cur = a[i] + carry * 1ll * base;
//	a[i] = int (cur / b);
	carry = int (cur % b);
}
return carry;
}

set< vector<int> > have;

int get(vector<int> &kek, int osn) {
	lnum o;
	o.pb(1);
	lnum now;
	now.pb(0);
	for (int i = (int)kek.size() - 1; i >= 0; --i) {
		if (kek[i] == 1) {
			add(now, o);
		}
		mult(o, osn);
	}
	for (int i = 2; i <= 1000; i++) {
		if (getRem(now, i) == 0) {
			return i;
		}
	}
	return -1;
}

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  srand(time(NULL));
  printf("Case #1:\n");
	int rem = 50;
	int len = 16;
	vector<int> good(len);
	while (true) {
		good[0] = good[len - 1] = 1;
		for (int i = 1; i < len - 1; i++) {
			if (rand() % 2 == 0) {
				good[i] = 1;
			} else {
				good[i] = 0;
			}
		}
		if (have.find(good) != have.end()) {
			continue;
		}
		vector<int> result;
	//	for (int i = 0; i < len; i++) printf("%d", good[i]);
	//	puts("");
	//	puts("?");
		for (int i = 2; i <= 10; i++) {
			int val = get(good, i);
			if (val == -1) {
				result.clear();
				break;
			}
			result.pb(val);
		}
		have.insert(good);	
		if ((int)result.size() == 0) {
		//	puts("FAIL!");
			continue;
		}
		--rem;
		for (int i = 0; i < len; i++) printf("%d", good[i]);
		for (int i = 0; i < (int)result.size(); i++) printf(" %d", result[i]);
		puts("");
		if (rem == 0) break;
	}
	return 0;
}