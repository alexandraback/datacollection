#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <climits>

using namespace std;

inline void read(int & n) {
    scanf("%d", & n);
}

vector<int> num;
set<int> sums;
int found;
int super;

deque<bool> ans0;
deque<bool> ans1;

void f(int start, int sum) {
    if (start == num.size()) {
        if (super != -1) {
            if (super == sum) {
                found = 1;
            }
            return;
        }
        set<int>::iterator it = sums.lower_bound(sum);
        if (it != sums.end() && *it == sum)
            found = sum;
        else {
            if (it != sums.begin())
                --it;
            sums.insert(it, sum);
        }
        return;
    }

    int next = start + 1;
    f(next, sum);
    if (found != -1) {
        if (ans1.empty())
            ans0[start] = false;
        else
            ans1[start] = false;
        return;
    }
    f(next, sum + num[start]);
}

void print(const deque<bool> & ans) {
    bool sp = false;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i]) {
            if (sp)
                cout << ' ' << num[i];
            else {
                sp = true;
                cout << num[i];
            }
        }
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);
    freopen("cout", "w", stdout);
#endif

    int cases;
    cin >> cases;

    for (int cas = 1;cas <= cases;++cas) {
        cout << "Case #" << cas << ":\n";
        int n;
        cin >> n;
        num.clear();
        num.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> num[i];
        sums.clear();
        found = -1;
        ans0.clear();
        ans1.clear();
        ans0.resize(n, true);
        super = -1;
        f(0, 0);
        if (found == -1) {
            cout << "Impossible\n";
            continue;
        }
        ans1.resize(n, true);
        super = found;
        found = -1;
        f(0, 0);
        print(ans0);
        print(ans1);
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    putchar('\n');
#endif
}

