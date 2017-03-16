#include <iostream> 
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set> 
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

const int INF = 2147483647;
const double EPS = 1E-10;

vector <int> S[2000001], A;
bool found = false;
int ans1, ans2;

void rec(int cur, int sum, int mask) {
	if(cur == 20) {
		if(sum > 0)
			S[sum].push_back(mask);
		return;
	}
	rec(cur + 1, sum, mask);
	rec(cur + 1, sum + A[cur], mask | (1 << cur));
}

void rec2(int cur, int sum, int mask) {
	if(found)
		return;
	if(cur == 20) {
		for(size_t i = 0; i < S[sum].size(); ++i)
			if(!(S[sum][i] & mask)) {
				ans1 = S[sum][i];
				ans2 = mask;
				found = true;
				break;
			}
		return;
	}
	rec2(cur + 1, sum, mask);
	rec2(cur + 1, sum + A[cur], mask | (1 << cur));
}

int main() { 
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		A.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> A[i];
		found = false;
		for(int i = 0; i < 2000000; ++i)
			S[i].clear();
		rec(0, 0, 0);
		rec2(0, 0, 0);
		cout << "Case #" << t + 1 << ":" << endl;
		if(found) {
			for(int i = 0; i < 20; ++i)
				if(ans1 & (1 << i))
					cout << A[i] << " ";
			cout << endl;
			for(int i = 0; i < 20; ++i)
				if(ans2 & (1 << i))
					cout << A[i] << " ";
		}
		else
			cout << "Impossible";
		cout << endl;
		
	}

	return 0;
} 