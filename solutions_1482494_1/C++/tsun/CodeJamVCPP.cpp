#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;


void runCase(int caseNum) {
	int N;
	cin >> N;

	vector<pair<int, int> > stars;

	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		stars.push_back(make_pair(a, b));
	}

	vector<int> taken(N, 0);

	int score = 0;
	int cnt = 0;

	while (true) {
		int next = -1;
		int m = -1;

		for (int i = 0; i < N; ++i) {
			if (taken[i] == 2)
				continue;
			if (stars[i].second <= score) {
				next = i;
				break;
			}
			if (stars[i].first <= score && taken[i] == 0) {
				if (stars[i].second > m) {
					m = stars[i].second;
					next = i;
				}
			}
		}

		if (next == -1)
			break;
		++cnt;
		if (taken[next] == 0) {
			if (stars[next].second <= score) {
				taken[next] = 2;
				score += 2;
			} else {
				taken[next] = 1;
				++score;
			}
		} else {
			taken[next] = 2;
			++score;
		}
	}

	cout.precision(10);
	cout << "Case #" << caseNum << ": " ;

	if (score == 2 * N)
		cout << cnt;
	else
		cout << "Too Bad";
	cout << endl;
}

int main(int argc, char* argv[])
{
#ifdef __TSUN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		runCase(i + 1);

//	runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

