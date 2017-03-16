#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Work {

    vector<int> s;
    int n;
    double x;

    Work() {
        cin >> n;
        s.resize(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        x = accumulate(s.begin(), s.end(), 0);
        main();
    }

    bool possible(int i, double ans) {
        double sum = 0;
        for (int j = 0; j < n; j++) {

            double now = (s[i] + x * ans - s[j]) / x;
            now = max(now, 0.0);
            sum += now;
        }
        return sum >= 1;
    }

    double get_ans(int i) {
        double l = 0, r = 1;
        while (r - l > 1e-9) {
            double m = (l + r) / 2;
            if (possible(i, m)) r = m;
            else l = m;
        }
        return r;
    }

    void main() {
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << ' ';
            cout << get_ans(i) * 100;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    cout << setiosflags(ios::fixed);
    cout << setprecision(6);
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " ;
        Work();
        cout << endl;
    }

}
