#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

typedef vector <int> vi;
typedef vector<vi>	vvi;

#define PROBLEM "B-small-attempt0"

bool test(int n, string& s) {
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != '?' && s[i] - '0' != n % 10) {
            return false;
        }
        n /= 10;
    }
    return true;
}

void solve(string& c, string& c2) {
    bool same = true;
    int m = c.size();
    int deg[] = {0, 10, 100, 1000}, n = deg[m], a, b, d = 999;
    for (int i = 0; i < n; ++i) {
        if (test(i, c)) {
            for (int j = 0; j < n; ++j) {
                if (abs(i-j) < d && test(j, c2)) {
                    a = i, b = j;
                    d = abs(a - b);
                }
            }
        }
    }
    std::cout << setfill('0') << setw(m) << a << " " << setfill('0') << setw(m) << b << std::endl;
}

int main()
{
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	std::cin >> T;

	for (int t = 1; t <= T; ++t) {
		string c, j;
		std::cin >> c >> j;
		std::cout << "Case #" << t << ": ";
		solve(c, j);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
