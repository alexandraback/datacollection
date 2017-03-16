#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)
#define foreach(itr, c) forl(itr, (c).begin(), (c).end())
#define rforeach(itr, c) forl(itr, (c).rbegin(), (c).rend())

#define gcase int T; cin >> T; for(int gtest = 1; gtest <= T; gtest++)
#define gstate() cerr << "Case: " << gtest << '/' << T << endl
#define gout cout << "Case #" << gtest << ": "

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int main() {
	gcase {
		gstate();
		int N, S, p;
		cin >> N >> S >> p;
		vector<int> t(N);
		set<int> pass;
		int x = max(p, 3*p - 2), y = max(p, 3*p - 4);
		forl(n, 0, N) {
			cin >> t[n];
			if(t[n] >= x) pass.insert(n);
			else if(t[n] >= y && S > 0) {
				pass.insert(n);
				S--;
			}
		}
		gout << pass.size() << endl;
	}
}
