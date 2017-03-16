#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <numeric>

#define all(x) x.begin(), x.end()
#define INF 0x7fffffff
#define PI acos(-1)

using namespace std;

int cnt = 39;
long long sq[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 
12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};

int main() {
	int testcases;
	cin >> testcases;
	for (int t = 1; t <= testcases; t++) {
		long long A, B; cin >> A >> B;
		int cnt = upper_bound(sq, sq+39, B) - lower_bound(sq, sq+39, A);
		cout << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}
