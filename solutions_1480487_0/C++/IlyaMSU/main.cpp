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






int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		vector<pii> data(n);
		vector<double> ans(n, 0.0);
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &data[j].first);
			data[j].second = j;
			sum += data[j].first;
		}
		int summ = sum;
		sort(data.begin(), data.end());
		int level = data[0].first;
		int j = 1;
		double l;
		while (j < n) {
			if (sum >= (data[j].first - level) * j) {
				sum -= (data[j].first - level) * j;
				level = data[j].first;
			}
			else {
				l = level + (double)sum / j;
				sum = 0;
				break;
			}
			++j;
		}
		if (j == n)
			l = level;
		if (sum != 0)
			l = level + (double)sum / n;
		for (j = 0; j < n; ++j) {
			if (data[j].first > l)
				ans[data[j].second] = 0;
			else
				ans[data[j].second] = l - data[j].first;
		}
		cout << "Case #" << i + 1 << ":";

		for(j = 0; j < n; ++j)
			printf(" %0.20f", ans[j] * 100.0 / summ);
		cout << endl;
		//std::cerr << i << endl;
	}
	return 0;
}
