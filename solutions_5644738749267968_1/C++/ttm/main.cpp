#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n;

int normal(const deque<int>& tony, deque<int> charlie) {
    int pts = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v = tony[i];
        auto it = lower_bound(charlie.begin(), charlie.end(), v,
                [](int a, int b) -> bool { return a > b; });
        if (it != begin(charlie)) {
            --it;
            charlie.erase(it);
        } else {
            pts += v > charlie.back();
            charlie.pop_back();
        }
    }
    return pts;
}

int cheat(deque<int>& tony, deque<int>& charlie) {
    int pts = 0;
    while (!tony.empty()) {
        while (!tony.empty() && (tony.front() < charlie.front())) {
            tony.pop_back();
            charlie.pop_front();
        }
        while (!tony.empty() && (tony.front() > charlie.front())) {
            ++pts;
            tony.pop_front();
            charlie.pop_front();
        }
    }
    return pts;
}


int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 0; cas < cases; ++cas) {
        cin >> n;
        deque<int> tony(n), charlie(n);
        for (int i = 0; i < n; ++i) { double tmp; cin >> tmp; tony[i] = int(tmp * 1000000); }
        for (int i = 0; i < n; ++i) { double tmp; cin >> tmp;charlie[i] = int(tmp * 1000000); }
        sort(tony.rbegin(), tony.rend());
        sort(charlie.rbegin(), charlie.rend());
        int norm = normal(tony, charlie);
        int ch = cheat(tony, charlie);
        cout << "Case #" << cas + 1 << ": " << ch << " " << norm << "\n";
    }
}
