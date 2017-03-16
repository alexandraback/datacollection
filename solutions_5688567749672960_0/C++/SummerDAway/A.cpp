//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

long long n;
int f[10001111];
int TestCase;

int ls(long long x) {
	return x%10;
}

int fs(long long x) {
	int ret = 0;
	while(x) {
		ret = x%10;
		x /= 10;
	}
	return ret;
}

bool mid(long long x) {
	x /= 10;
	long long ret = 0, y = 0;
	while(x > 10) {
		ret *= 10;
		ret += x%10;
		x /= 10;
	}
	x = ret;
	while(x) {
		y *= 10;
		y += x%10;
		x /= 10;
	}
	return ret < y;
}

long long rv(long long x) {
	long long ret = 0;
	while(x) {
		ret *= 10;
		ret += x%10;
		x /= 10;
	}
	return ret;
}

void work(int testcase) {
	long long x;
	cin >> x;
	long long ans = 0;
	printf("Case #%d: %d\n", testcase, f[x]);
	/*while(x) {
		int t = rv(x);
		if(t < x && ls(x) != 0) {
			x = t;
		} else {
			x--;
		}
		ans++;
	}*/
	//printf(" %d\n", ans);
}
	

int main( int argc , char *argv[] )
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	for(int i = 1; i < 10000000; ++i) {
		f[i] = 100000000;
	}
	f[1] = 1;
	for(int i = 1; i < 10000000; ++i) {
		f[i+1] = min(f[i+1], f[i] + 1);
		int t = rv(i);
		f[t] = min(f[t], f[i]+1);
	}
	scanf("%d", &TestCase);
	for(int i = 1; i <= TestCase; ++i) {
		work(i);
	}
	return 0;
}
