#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
#include <functional>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
using namespace std;

#define FOR(_i,_n) for(int (_i)=0;(_i)<(_n);(_i)++)
#define iss istringstream
#define oss ostringstream
#define mp make_pair
#define pb push_back
#define px first
#define py second
#define pi 3.141592653589793
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> Pair;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	for(int tt=1;tt<=T;tt++) {
		int64 r, t;
		cin >> r >> t;
		int cnt = 0;
		int64 sum = 0;
		
		int64 x = 1;
		
		while(sum + (2LL * r + x) <= t) {
			sum += (2LL * r + x);
			x += 4LL;
			cnt ++;
		}
	
		printf("Case #%d: %d\n", tt, cnt);	
	}
	
	return 0;
}
