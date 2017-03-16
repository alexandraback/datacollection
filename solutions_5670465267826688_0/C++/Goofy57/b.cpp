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

int getch(char c) {
	if (c == 'i') return 2; 
	if (c == 'j') return 3; 
	if (c == 'k') return 4; 
	return 1; 
}

inline int sgn(int x) {
	return (x < 0 ? -1 : 1); 
}

int mulm[5][5] = {{ 0 }, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}}; 

int mult(int a, int b) {
	int sign = sgn(a) * sgn(b); 
	a = abs(a); 
	b = abs(b); 
	return mulm[a][b] * sign; 
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	// ios::sync_with_stdio(false);

	int t;
	cin >> t; 

	for (int tc = 0; tc < t; tc++) {
		string s; 
		int l, x; 

		cin >> l >> x; 

		cin >> s; 
		string t; 
		for (int i = 0; i < x; i++) {
			t += s; 
		}

		swap(s, t); 

		int res = 1; 
		for (int i = 0; i < s.length(); i++) {
			res = mult(res, getch(s[i])); 
		}
		
		if (res != -1) {
			cout << "Case #" << tc + 1 << ": NO\n"; 
			continue; 
		}
		
		res = 1; 
		int leftans = 10000; 
		int rightans = -10000; 
		for (int i = 0; i < s.length(); i++) {
			res = mult(res, getch(s[i])); 
			if (res == 2) {
				leftans = i; 
				break; 
			}
		}

		res = 1;  
		for (int i = (int)s.length() - 1; i >= 0; i--) {
			res = mult(getch(s[i]), res); 
			if (res == 4) {
				rightans = i; 
				break; 
			}
		}

		if (leftans + 1 < rightans) {
			cout << "Case #" << tc + 1 << ": YES\n"; 
			continue; 
		} else {
			cout << "Case #" << tc + 1 << ": NO\n"; 
			continue; 
		}
	}

	return 0;
}


