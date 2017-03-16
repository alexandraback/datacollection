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
int a[50];

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
	printf("Case #%d: ", testcase);
	if(ls(x) == 0) {
		x--;
		ans++;
	}
	n = 0;
	while(x) {
		a[n++] = x%10;
		x /= 10;
	}
	while(n) {
		if(n == 1) {
			ans += a[0];
			break;
		}
		ans += a[0] + a[n-1] - 1;
		long long now = 10;
		bool flag = false;
		for(int i = 1; i <= (n>>1); ++i) {
			int j = n-i-1;
			if(j > i) {
				ans += a[i]*now + a[j]*now;
				if(a[j] > 0) {
					flag = true;
				}
			} else if(j == i) {
				ans += a[i]*now;
			} else {
				break;
			}
			now *= 10;
		}
		if(!flag && a[n-1] == 1) {
			ans--;
		}
		ans += 2;
		for(int i = 0; i < n; ++i) {
			a[i] = 9;
		}
		n--;
	}
	cout << ans << endl;
	//printf(" %d\n", ans);
}
	

int main( int argc , char *argv[] )
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
/*
	for(int i = 1; i < 10000000; ++i) {
		f[i] = 100000000;
	}
	f[1] = 1;
	for(int i = 1; i < 10000000; ++i) {
		f[i+1] = min(f[i+1], f[i] + 1);
		int t = rv(i);
		f[t] = min(f[t], f[i]+1);
	}
	for(int i = 10; i < 10000000; i *= 10) {
		printf("%d\n", f[i-1]);
	}
	for(int i = 1; i < 1000000; ++i) {
		work(i);
	}
	*/
	scanf("%d", &TestCase);
	for(int i = 1; i <= TestCase; ++i) {
		work(i);
	}
	return 0;
}
