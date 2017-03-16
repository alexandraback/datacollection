#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

int ans[2000000]; 
set<pii> d; 

int solve() {
	int n; 
	cin >> n; 

	return ans[n] + 1; 
}

int mirror(int x) {
	int ans = 0; 
	while (x) {
		ans = 10 * ans + x % 10; 
		x /= 10; 
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);
	
	int n = 1000000; 

	for (int i = 1; i <= n + 1; i++) {
		ans[i] = 1000000000; 
		d.insert(mp((i > 1) * 1000000000, i));
	}
	ans[1] = 0; 

	for (int i = 0; i < n; i++) {
		auto w = *d.begin(); 
		d.erase(d.begin()); 
		int v = w.second; 
		if (v + 1 <= n && ans[v + 1] > ans[v] + 1) {
			d.erase(d.find(mp(ans[v + 1], v + 1))); 
			ans[v + 1] = ans[v] + 1; 
			d.insert(mp(ans[v + 1], v + 1)); 
		}
		int mir = mirror(v); 
		if (mir > 0 && mir <= n && ans[mir] > ans[v] + 1) {
			d.erase(d.find(mp(ans[mir], mir))); 
			ans[mir] = ans[v] + 1; 
			d.insert(mp(ans[mir], mir)); 
		}
	}

	int t; 
	cin >> t;  

	for (int tc = 0; tc < t; tc++) {
		cout << "Case #" << tc + 1 << ": " << solve() << "\n"; 
	}

	return 0;
}


