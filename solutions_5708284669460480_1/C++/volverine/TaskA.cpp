#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <string.h>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <assert.h>
#include <deque>
#include <sstream>

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif // WIN32

#define INF (1LL << 30)
#define md 1000000007
#define F first
#define S second
#define ll long long
#define mp make_pair
#define pb push_back
#define next(i) (i) + ((i) & (-i))
#define prev(i) (i) - ((i) & (-i))

using namespace std;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int getMaxCount(string need, int s) {
    vector<int> z = z_function(need + '#' + need);
    int p = -1;
    for (int i = need.size() + 2; i < z.size(); i++) {
        int cur = z[i];
        int pos = i - need.size() - 1;
        if (pos + cur == need.size()) {
            p = need.size() - cur;
            break;
        }
    }

    if (p == -1) {
        return s / (int)need.size();
    } else {
        return 1 + (s - need.size()) / p;
    }
}

int getNum(string cur, string &need) {
    int k = 0;
    for (int i = 0; i <= cur.size() - need.size(); i++) {
        bool f = true;
        for (int j = 0; j < need.size(); j++) {
            if (cur[i + j] != need[j]) {
                f = false;
                break;
            }
        }
        k += f;
    }
    return k;
}

double rec(string cur, double letters[], int s, double chance, string &need) {
    if (cur.size() == s) {
    //    cout << cur << " " << getNum(cur, need) << " " << chance << endl;
        return 1.0 * getNum(cur, need) * chance;
    }
    double result = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (letters[i] > 0) {
            result += rec(cur + (char)i, letters, s, chance * letters[i], need);
        }
    }
    return result;
}

double BruteForce(string keyboard, string need, int s) {
    int maxBananas = getMaxCount(need, s);
    for (int i = 0; i < need.size(); i++) {
        bool f = false;
        for (int j = 0; j < keyboard.size(); j++) {
            if (need[i] == keyboard[j]) {
                f = true;
            }
        }
        if (!f) {
            return 0;
        }
    }

    double letters['Z' + 1];
    for (int i = 'A'; i <= 'Z'; i++) {
        letters[i] = 0;
    }
    for (int i = 0; i < keyboard.size(); i++) {
        letters[keyboard[i]] += 1.0 / (double)keyboard.size();
    }
    //cout << rec("", letters, s, 1, need) << endl;
    return maxBananas - rec("", letters, s, 1, need);
}


double solve(string keyboard, string need, int s) {
    int maxBananas = getMaxCount(need, s);
    for (int i = 0; i < need.size(); i++) {
        bool f = false;
        for (int j = 0; j < keyboard.size(); j++) {
            if (need[i] == keyboard[j]) {
                f = true;
            }
        }
        if (!f) {
            return 0;
        }
    }

    double letters['Z' + 1];
    for (int i = 'A'; i <= 'Z'; i++) {
        letters[i] = 0;
    }
    for (int i = 0; i < keyboard.size(); i++) {
        letters[keyboard[i]] += 1.0 / (double)keyboard.size();
    }

    double d[200][200];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            d[i][j] = 0;
        }
    }
    d[0][0] = 1;
    for (int i = 1; i <= s; i++) {
        d[i][0] = 1;
        for (int j = 1; j <= min(i, (int)need.size()) ; j++) {
            d[i][j] = d[i - 1][j - 1] * letters[need[j - 1]];
        }
    }
    double p = 0;
    for (int i = 1; i <= s; i++) {
        p += d[i][need.size()];
    }
    //cout << p << endl;
    return (double)maxBananas - p;
}


int main() {
    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
    #else
            //freopen("input.txt", "r", stdin);
            //freopen("output.txt", "w", stdout);
    #endif //
    int t;
    cin >> t;
    //t = 1;
    for (int i = 1; i <= t; i++) {
        int k, l, s;
        scanf("%d %d %d", &k, &l, &s);
        string keyboard, need;
        cin >> keyboard;
        cin >> need;
        printf("Case #%d: %0.7f\n", i, solve(keyboard, need, s));
        //solve(keyboard, need, s);
    }

    return 0;
}

