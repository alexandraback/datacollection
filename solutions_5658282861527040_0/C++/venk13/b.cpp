//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int t, cas = 1; cin >> t;
	while(t--) {
		cout << "Case #" << cas++ << ": ";
		int a, b, k, count = 0; cin >> a >> b >> k;
		for(int i = 0; i < a; i++)
			for(int j = 0; j < b; j++) {
				if((i & j) < k)
					count++;
			}
		cout << count << '\n';
	}
	return 0;
}