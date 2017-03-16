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

string s; 

char get_s(ll i) {
	i %= s.length(); 
	return s[i]; 
}


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

int my_power(int x, ll p) {
	if (!p) return 1; 
	if (p % 2) return mult(my_power(x, p - 1), x);
	else { 
		int t = my_power(x, p / 2); 
		return mult(t, t); 
	}
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	// ios::sync_with_stdio(false);

	int t;
	cin >> t; 

	for (ll tc = 0; tc < t; tc++) {
		cerr << tc << "\n"; 
		ll l, x; 

		cin >> l >> x; 

		cin >> s; 


		ll res = 1; 
		for (ll i = 0; i < s.length(); i++) {
			res = mult(res, getch(s[i])); 
		}
		
		if (my_power(res, x) != -1) {
			cout << "Case #" << tc + 1 << ": NO\n"; 
			continue; 
		}
		
		res = 1; 
		ll leftans = 1000000000000000000LL; 
		ll rightans = -1000000000000000000LL; 
		for (ll i = 0; i < 10000000 && i < l * x; i++) {
			res = mult(res, getch(get_s(i))); 
			if (res == 2) {
				leftans = i; 
				break; 
			}
		}

		res = 1;  
		for (ll i = l * x - 1; i >= max(0LL, l * x - 10000000); i--) {
			res = mult(getch(get_s(i)), res); 
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


