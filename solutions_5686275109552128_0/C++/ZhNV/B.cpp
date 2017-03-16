#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int M = 1e5 + 10;
const ld Q = 1e9 + 15.;
int a[M];
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tq = 1; tq <= t; tq++){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)                                                                            
			scanf("%d", &a[i]);
		int ans = 3000;
		for (int x = 1; x <= 1000; x++){
			int cur = x;
			for (int i = 0; i < n; i++)
				if (a[i] > x) 
					cur += (a[i] - 1) / x;
			ans = min(ans, cur);
		}
		printf("Case #%d: %d\n", tq, ans);
		cerr << "test " << tq << " done" << endl;
	}
	return 0;       
}                                              	