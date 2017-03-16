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
const int INF = 2000000000;

struct arc {
	//int left, rigth, up, down;
	vector<pii> a;
};



int main() {	
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, h;
		scanf("%d %d %d", &h, &n, &m);
		vector<vector<int> > up(n, vector<int> (m)), down(n, vector<int> (m));
		vector<vector<arc> > gr(n, vector<arc> (m));
		for (int i1 = 0; i1 < n; ++i1) {
			for (int i2 = 0; i2 < m; ++i2) {
				scanf("%d", &up[i1][i2]);
			}
		}
		for (int i1 = 0; i1 < n; ++i1) {
			for (int i2 = 0; i2 < m; ++i2) {
				scanf("%d", &down[i1][i2]);
			}
		}
		for (int i1 = 0; i1 < n; ++i1) {
			for (int i2 = 0; i2 < m; ++i2) {
				if (i1 > 0) {
					if ((up[i1 - 1][i2] < down[i1 - 1][i2] + 50) ||
						(up[i1 - 1][i2] < down[i1][i2] + 50) ||
						(up[i1][i2] < down[i1 - 1][i2] + 50)) {}
						
					else
						gr[i1][i2].a.push_back(make_pair(i1 - 1, i2));
						
				}
				if (i2 > 0) {
					if ((up[i1][i2 - 1] < down[i1][i2 - 1] + 50) ||
						(up[i1][i2 - 1] < down[i1][i2] + 50) ||
						(up[i1][i2] < down[i1][i2 - 1] + 50)){}
					else
						gr[i1][i2].a.push_back(make_pair(i1, i2 - 1));

				}
				if (i1 < n - 1) {
					if ((up[i1 + 1][i2] < down[i1 + 1][i2] + 50) ||
						(up[i1 + 1][i2] < down[i1][i2] + 50) ||
						(up[i1][i2] < down[i1 + 1][i2] + 50)){}
					else
						gr[i1][i2].a.push_back(make_pair(i1 + 1, i2));
				}
				if (i2 < m - 1) {
					if ((up[i1][i2 + 1] < down[i1][i2 + 1] + 50) ||
						(up[i1][i2 + 1] < down[i1][i2] + 50) ||
						(up[i1][i2] < down[i1][i2 + 1] + 50)) {}
					else
						gr[i1][i2].a.push_back(make_pair(i1, i2 + 1));
				}
			}
		}
		vector<vector<int> > time(n, vector<int>(m, INF));
		time[0][0] = 0;
		priority_queue<pair<int, pair<int, int>> > tr;
		tr.push(make_pair(0, make_pair(0, 0)));
		while(!tr.empty()) {
			pii v = tr.top().second;
			int cur_t = -tr.top().first;
			tr.pop();
			if (cur_t > time[v.first][v.second])
				continue;
			for (int j = 0; j < gr[v.first][v.second].a.size(); ++j) {
				pii to = gr[v.first][v.second].a[j];
				int tt = max(h - (up[to.first][to.second] - 50), time[v.first][v.second]);
				if (tt == 0) {
					if (!(time[to.first][to.second] == 0))
						tr.push(make_pair(0, to));
					time[to.first][to.second] = 0;
					continue;
				}
				if (h - tt - down[v.first][v.second] >= 20) {
					if (time[to.first][to.second] > tt + 10) {
						time[to.first][to.second] = tt + 10;
						tr.push(make_pair(-time[to.first][to.second], to));
					}
				}
				else {
					if (time[to.first][to.second] > tt + 100) {
						time[to.first][to.second] = tt + 100;
						tr.push(make_pair(-time[to.first][to.second], to));
					}
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << (double)(time[n - 1][m - 1]) / 10.0 << endl;
		//std::cerr << i << endl;
	}
	return 0;
}
