#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
double N = 1;


double c(int k, int n) {
	double res = 1.0;
	for (int i = 1; i <= k; ++i) {
		res *= (n - i + 1);
		res /= i;
	}
	return res;
}

double pp(int f, int n) {
	if (f < 50)
		return 0;
	return exp(log(0.5 * n) * n - n) * sqrt(2.0 * PI * n) / exp(log(1.0 * f) * f - f) * sqrt(2.0 * PI * f) / exp(log(1.0 * (n - f)) * (n - f) - n + f) * sqrt(2.0 * PI * (n - f));
}

double prob(int f, int n) {
	if (2 * f > n)
		return 1.0 - prob(n - f - 1, n);
	if (f < 0)
		return 0;
	if (n > 1000) {
		return pp(f, n);
	}
	else {
		N = 1.0;
		for (int i = 0; i < n; ++i)
			N *= 2.0;
	}
	double res = 0;
	for (int i = f; (i >= 0) && (f - i < 50); --i) {
		res += c(i, n) / N;
	}
	return res;
}

double solve() {
	int n, x, y;
	cin >> n >> x >> y;
	int sum = abs(x) + abs(y);
	int s = (sum) * (sum - 1) / 2;
	if (n < s)
		return 0;
	n -= s;
	if (n > sum + y)
		return 1.0;
	if (x == 0) {
		if (n < 2 * y + 1)
			return 0.0;
		else
			return 1.0;
	}
	int f = n - y - 1;
	return prob(f, n);
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	//scanf("%d\n", &tt);
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		cout << "Case #" << i + 1 << ": ";
		printf("%0.10f\n", solve());
		std::cerr << i << endl;
	}
	return 0;
}
