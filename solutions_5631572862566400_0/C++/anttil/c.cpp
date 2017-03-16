#include <iostream>
#include <vector>

using namespace std;

int t;
int n;
int f[1111], z[1111];
vector<int> v;
int p;
int q;

bool ok() {
    for (int i = 1; i < v.size()-1; i++) {
        if (f[v[i]] == v[i-1]) continue;
        if (f[v[i]] == v[i+1]) continue;
        return false;
    }
    int c = 0;
    if (f[v[0]] == v[1] || f[v[0]] == v[v.size()-1]) c++;
    if (f[v[v.size()-1]] == v[0] || f[v[v.size()-1]] == v[v.size()-2]) c++;
    return c == 2;
}

void haku() {
    if (v.size() > 1 && ok() && v.size() > p) p = v.size();
    for (int i = 1; i <= n; i++) {
        if (z[i]) continue;
        v.push_back(i);
        z[i] = 1;
        haku();
        v.pop_back();
        z[i] = 0;
    }
}

void solve(int x) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    p = 1;
    haku();
    cout << "Case #" << x << ": " << p << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
