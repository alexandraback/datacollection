#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct Group
{
	ull h, m, d;
};

int solve(vector <Group> &h)
{
	if(h.size() == 1) {
		return 0;
	}
	if(h[1].m < h[0].m) {
		swap(h[1], h[0]);
	}
	if(360ull * h[0].m <= (h[1].m - h[0].m) * (360 - h[1].d)) {
		return 1;
	} else {
		return 0;
	}
}

int main()
{
	int t;
	int n;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cin >> n;
		vector <Group> h(n);
		for(int j = 0; j < n; ++j) {
			cin >> h[j].d >> h[j].h >> h[j].m;
		}
		cout << "Case #" << i << ": " << solve(h) << endl;
	}
	return 0;
}
