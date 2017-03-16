#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);

		int n;
		cin >> n;
		vector<pair<string, string> > articles(n);
		for (int i = 0; i < n; i++) {
			cin >> articles[i].first >> articles[i].second;
		}

		int maxm = 0;
		for (int i = 0; i < (1 << n); i++) {
			bool works = true;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					cnt++;
					bool firstCovered = false;
					bool secondCovered = false;
					for (int k = 0; k < n; k++) {
						if (!(i & (1 << k)) && articles[k].first == articles[j].first) {
							firstCovered = true;
						}
						if (!(i & (1 << k)) && articles[k].second == articles[j].second) {
							secondCovered = true;
						}
					}
					if (!firstCovered || !secondCovered) {
						works = false;
						break;
					}
				}
			}
			if (works)
				maxm = max(maxm, cnt);
		}

		cout << maxm << endl;
	}
	return 0;
}

