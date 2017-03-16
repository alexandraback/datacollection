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
		vector<int> data(2000001, 0);
		int n;
		scanf("%d", &n);
		vector<int> num(20);
		for (int j = 0; j < 20; ++j)
			scanf("%d", &num[j]);
		int mask = 1;
		while (true) {
			int mas = mask;
			int x = 0;
			int in = 0;
			while (mas > 0) {
				if (mas % 2 == 1)
					x += num[in];
				mas /= 2;
				++in;
			}
			if (data[x] == 0)
				data[x] = mask;
			else {
				cout << "Case #" << i + 1 << ":" << endl;
				in = 0;
				while (mask > 0) {
					if (mask % 2 == 1)
						cout << num[in] << " ";
					mask /= 2;
					++in;
				}
				cout << endl;
				in = 0;
				mask = data[x];
				while (mask > 0) {
					if (mask % 2 == 1)
						cout << num[in] << " ";
					mask /= 2;
					++in;
				}
				cout << endl;
				break;
			}
			++mask;
		}
		//std::cerr << i << endl;
	}
	return 0;
}
