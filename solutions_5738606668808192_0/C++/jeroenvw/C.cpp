// http://en.cppreference.com/w/cpp/container
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

#include <bitset>
#include <tuple>

#include <algorithm>
#include <functional>

#include <cstdint>
#include <cstdio>

extern "C" {

// Called after load, and before each case
void reset()
{
}

int64_t frombase(int n, int base)
{
	int64_t res = 0;
	int64_t fac = 1;
	for (int i=0; i<30;i++) {
		if (n & (1<<i)) {
			res += fac;
		}
		fac *= base;
	}
	return res;
}

}

