#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector <int> vi;
typedef vector<vi>	vvi;

#define PROBLEM "A-small-attempt0"

const char* digits[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char flag[10];
int order[10];

void solve(string& s) {
    vi cnt('Z' + 1, 0);
    for (int i = 0; i < (int)s.size(); ++i) {
        cnt[s[i]]++;
    }
    vi cnt2(10, 0);
    for (int i = 0; i < 10; ++i) {
        int cur = order[i];
        char a = flag[cur];
        int d = cnt[a];
        cnt2[cur] = d;
        for (int j = 0; digits[cur][j]; ++j) {
            cnt[digits[cur][j]] -= d;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt2[i]; ++j) {
            cout << i;
        }
    }
    std::cout << std::endl;
}

int main()
{
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	std::cin >> T;

	int n = 10;
	vi vis(n, 0);
	for (int i = 0; i < n; ++i) {
		bool found = false;
		for (char a = 'A'; !found && a <= 'Z'; ++a) {
			int cnt = 0, ind;
			for (int j = 0; j < n; ++j) {
				if (vis[j]) continue;
				for (int k = 0; digits[j][k]; ++k) {
					if (digits[j][k] == a) {
						++cnt;
                        ind = j;
                        break;
					}
				}
			}
			if (cnt == 1) {
				cerr << a << ": " << digits[ind] << endl;
				found = true;
				vis[ind] = 1;
				order[i] = ind;
				flag[ind] = a;
			}
		}
		if (!found) {
			return 1;
		}
	}

	for (int t = 1; t <= T; ++t) {
		string s;
		std::cin >> s;
		std::cout << "Case #" << t << ": ";
		solve(s);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
