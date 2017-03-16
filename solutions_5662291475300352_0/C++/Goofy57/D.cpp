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
#include <unordered_map>

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

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int t; 
	cin >> t; 

	for (int tc = 0; tc < t; tc++) {
		int n = 0; 
		cin >> n; 

		vector<double> st; 
		vi p;
		vector<double> v; 
		
		for (int i = 0; i < n; i++) {
			int d, m, vel; 
			cin >> d >> m >> vel; 

			for (int j = 0; j < m; j++) {
				st.pb(d);
				p.pb(vel + j); 
				v.pb(360.0 / p[j]);
			}

		}
		
		if (st.size() < 2) {
			cout << "Case #" << tc + 1 << ": " << "0\n"; 
		} else 
		if (st.size() > 2) {
			cout << "Case #" << tc + 1 << ": " << "lol\n"; 
		} else {
			int ans = 1;  

			if (st[0] > st[1]) {
				swap(st[0], st[1]); 
				swap(v[0], v[1]); 
				swap(p[0], p[1]); 
			}
			if (p[0] == p[1]) {
				ans = 0; 
			} else if (p[0] > p[1]) {
				double t0 = (360 - st[0]) / v[0]; 
				double t1 = (st[1] - st[0]) / (v[1] - v[0]); 
				if (t1 < 1e-6) t1 = 360 / (v[1] - v[0]);
				if (t0 < t1) {
					ans = 0; 
				}
			} else {
				double tmeet = (st[1] - st[0]) / (v[0] - v[1]);
				double x = st[0] + v[0] * tmeet; 
				if (x > 360) {
					ans = 0; 
				} else {
					st[0] = st[1] = x; 
					swap(v[0], v[1]); 
					double t0 = (360 - st[0]) / v[0]; 
					double t1 = (st[1] - st[0]) / (v[1] - v[0]); 
					if (t1 < 1e-6) t1 = 360 / (v[1] - v[0]);
					if (t0 < t1) {
						ans = 0; 
					}
				}
			}

			cout << "Case #" << tc + 1 << ": " << ans << "\n"; 
		}
	}

	return 0;
}


