#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

const int N = 2000;

int parse(string s) {
    for (int i = s.size(); i < 7; i++)
        s += '0';
    int res = 0, pow = 1;
    for (int i = 6; i >= 2; i--) {
        res += (s[i] - '0') * pow;
        pow *= 10;
    }
    return res;
}

void del(set<int> &st, int val) {
    st.erase(st.find(val));
}

int a[N], b[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        set<int> aMin, bMin, bMax;
        scanf("%d\n", &n);
        for (int j = 0; j < n; j++) {
            string s;
            cin  >> s;
            a[j] = parse(s);
            aMin.insert(a[j]);
        }
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            b[j] = parse(s);
            bMin.insert(b[j]);
            bMax.insert(-b[j]);
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int x = *aMin.begin();
            int y = *bMin.begin();
            if (x > y)
                cnt++;
            else
                y = -(*bMax.begin());
            del(aMin, x);
            del(bMin, y);
            del(bMax, -y);
        }
        int cnt1 = 0;
        for (int j = 0; j < n; j++) {
            aMin.insert(a[j]);
            bMin.insert(b[j]);
        }
        for (int j = 0; j < n; j++) {
            int x = *aMin.begin();
            int y = *bMin.begin();
            set<int>::iterator f = bMin.upper_bound(x);
            if (f == bMin.end())
                cnt1++;
            else
                y = *f;
            del(aMin, x);
            del(bMin, y);
        }
        cout << "Case #" << i + 1 << ": " <<cnt << ' ' << cnt1 << endl;
    }
    return 0;
}
