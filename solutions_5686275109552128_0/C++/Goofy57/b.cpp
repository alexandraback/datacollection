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

const int maxn = 111; 


int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	// ios::sync_with_stdio(false);

	int t;
	cin >> t; 

	for (int tc = 0; tc < t; tc++) {
		int n, sum = 0; 
		cin >> n; 
		
		vi a(n); 

		for (int i = 0; i < n; i++) {
			cin >> a[i]; 
			sum += a[i]; 
		}

		int ans = 1000000; 
		for (int k = 1; k < 1000; k++) {
			int cur = k; 
			for (int i = 0; i < n; i++) {
				cur += max(0, (a[i] - k + k - 1) / k); 
			}

			if (cur < ans) ans = cur; 
		}

		cout << "Case #" << tc + 1 << ": " << ans << "\n"; 
	}

	return 0;
}


