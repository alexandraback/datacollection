//Author: Artem Romanov
#include <bits/stdc++.h>
//#define TASK "file"

#define F   first
#define S   second
#define y0  y84678
#define y1  y53021

using namespace std;
typedef long double dbl;

const dbl PI = 3.141592653589793238462643383279502884L;
const dbl E = 2.718281828459045235360287471352662498L;
const dbl EPS = 1e-12L;

int t;
string s;
deque<char> q, q1, q2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(11); cout.setf(ios::fixed);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#elif defined(TASK)
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;
        q.clear();
        q.push_back(s[0]);
        q2 = q1 = q;
        for (int j = 1; j < s.size(); ++j) {
            q1.push_back(s[j]);
            q2.push_front(s[j]);
            if (lexicographical_compare(q1.begin(), q1.end(), q2.begin(), q2.end())) {
                q.push_front(s[j]);
                q1 = q2;
            } else {
                q.push_back(s[j]);
                q2 = q1;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        for (int j = 0; j < q.size(); ++j) {
            cout << q[j];
        }
        cout << '\n';
    }
    return 0;
}