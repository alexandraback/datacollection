#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define all(v) v.begin(), v.end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, b, a) for (int i = b; i > a; i--)
#define Si(a) scanf("%d", &(a))
#define Sl(a) scanf("%lld", &(a))
#define SZ size()
#define F first
#define S second
#define B begin()
#define E end()

#define mod 1000000007

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T>
T power(T a, int n){
	T res = 1;
	while (n) {
		if (n & 1) res = (res * a) % mod;
		n >>= 1; a = (a * a) % mod;
	}
	return res;
}

int main()
{
	int T;
	int a, b, k;
	int x;


	cin >> T;
	For (t, 1, T+1) {
		cin >> a >> b >> k;

		x = 0;

		for (int i= 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i&j) < k) {
					x++;
				}
			}
		}
		cout << "Case #" << t << ": " << x << endl;
	}
	
	return 0;
}
