#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;

int pow10(int n)
{
    int r = 1;
    while (n--) {
        r *= 10;
    }
    return r;
}

inline bool valid(const string &s, int num)
{
    int n = s.size();
    vector<int> digits;
    while (digits.size() < n) {
        digits.push_back(num % 10);
        num /= 10;
    }
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && (s[i] - '0') != digits[i]) {
            return false;
        }
    }
    return true;
}

void print_num(int num, int len)
{
	vector<int> digits;
    while (digits.size() < len) {
        digits.push_back(num % 10);
        num /= 10;
    }
    reverse(digits.begin(), digits.end());
    for (int i : digits) {
		cout << i;
    }
}

void run()
{
    string a, b;
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    int pa = pow10(la), pb = pow10(lb);

    int minDiff = 2147483647;
    int minA = -1, minB = -1;

    // cerr << a << " " << b << " " << pa << " " << pb << endl;

    for (int i = 0; i < pa; i++) {
        if (!valid(a, i)) {
            continue;
        }
        for (int j = 0; j < pb; j++) {
            if (!valid(b, j)) {
                continue;
            }

            // cerr << i << " " << j << endl;
            if (abs(i - j) < minDiff || (abs(i - j) == minDiff && j < minB)) {
                minDiff = abs(i - j);
                minA = i;
                minB = j;
                // cerr << minDiff << " " << minA << " " << minB << endl;
            }
        }
    }
    print_num(minA, la);
    cout << " ";
    print_num(minB, lb);
}

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif // LOCAL

    int n;
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
        cout << "Case #" << tc << ": ";
        run();
        cout << endl;
    }
    return 0;
}
