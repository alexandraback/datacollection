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

int n;
int m;
string str[10], ans, ans2;
bool edge[10][10];


bool profit(vector<int> &v)
{
	ans2 = "";
	For(i, 0, n) ans2 += str[v[i] - 1];
	return ans2 < ans;
}

bool isValidPath(vector<int> &v)
{
	stack<int> s;

	s.push(v[0]);
	int i = 1;

	while (!s.empty() && i < n) {
		if (edge[s.top()][v[i]]) {
			s.push(v[i]);
			i++;
		}
		else {
			s.pop();
		}
	}
	
	return (i == n);
}

int main()
{
	int T;
	int x, y;

	cin >> T;
	For (t, 1, T+1) {
		cin >> n;
		cin >> m;
		vector<int> v;
		ans = "";
		For (i, 0, n) {
			cin >> str[i];
			v.PB(i+1);
			ans = ans + "99999";
		}
		For (i, 0, 10) {
			For (j, 0, 10) {
				edge[i][j]  = 0;
			}
		}

		For (i, 0, m) {
			x = y = 0;
			cin >> x >> y;
			edge[x][y] = edge[y][x] = 1;
		}

		do {
			if (profit(v) && isValidPath(v)) {
				ans = ans2;
			}
		} while (next_permutation(all(v)));

		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
