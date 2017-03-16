#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

void proc()
{
	int N;
	cin >> N;

    bool isOdd[2500];
    for (int i = 0; i < 2500; ++i) isOdd[i] = false;

    for (int i = 0; i < 2*N-1; ++i) {
        for (int j = 0; j < N; ++j) {
            int tmp;
            cin >> tmp;
            isOdd[tmp] = !isOdd[tmp];
        }
    }
    vector <int> ans;
    for (int i = 0; i < 2500; ++i) if (isOdd[i]) ans.push_back(i);
   
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << " " << ans[i];
	cout << endl;
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":";
		proc();
	}
}
