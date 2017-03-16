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
	string s, ans;
	cin >> s;
    ans = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (ans[0] <= s[i]) ans = s[i] + ans;
        else ans = ans + s[i];
    }
	cout << ans << endl;
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		proc();
	}
}
