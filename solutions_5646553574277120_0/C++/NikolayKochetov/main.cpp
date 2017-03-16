#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

string path = "/home/nicolai/work/CLionProjects/untitled/";

bool check(set<int> &mn, int n) {
    vector<int> v(n + 1, 0);
    v[0] = 2;
    for (auto it = mn.begin(); it != mn.end(); ++it) {
        for (int i = 0; i <= n; i++)
            if (v[i] == 2 && i + *it <= n)
                v[i + *it] = max(1,v[i + *it]);
        for (int i = 0; i <= n; i++)
            if (v[i])
                v[i] = 2;
    }
    for (int i = 0; i <= n; i++)
        if (!v[i])
            return false;
    return true;
}

void outs(set<int> &mn, ostream &out) {
    for (auto it = mn.begin(); it != mn.end(); ++it)
        out << *it << ' ';
    out << endl;
}

bool rec(set<int> &mn, int n, ostream &out, int deep = 0) {
    if (deep == 0)
        return check(mn, n);
    for (int i = 2; i <= n; i++)
        if (mn.find(i) == mn.end()) {
            mn.insert(i);
            if (rec(mn, n, out, deep - 1)) {
                //outs(mn, out);
                return true;
            }
            mn.erase(i);
        }
    return false;
}

int main() {

    int N;
    ifstream in(path + "input.txt");
    in.sync_with_stdio(false);
    ofstream out(path + "output.txt");
    in >> N;
    for (int t = 0; t < N; t++) {
        int c, d, v;
        in >> c >> d >> v;
        set<int> coins;
        for (int i = 0; i < d; i++) {
            int buf;
            in >> buf;
            coins.insert(buf);
        }
        int ans = 0;
        if (coins.find(1) == coins.end()) {
            coins.insert(1);
            ans++;
        }
        if (rec(coins, v, out, 0));
        else if (rec(coins, v, out, 1))
            ans++;
        else if (rec(coins, v, out, 2))
            ans += 2;
        else if (rec(coins, v, out, 3))
            ans += 3;
        else
            ans += 4;
        out << "Case #" << t + 1 << ": " << ans << "\n";
    }
    return 0;
}

