//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int suma, sumb, v[20], n, sum;
vector<int> a, b;

void rec(int i) {
    if (i >= n || 2*suma > sum || 2*sumb > sum) return;
    if (suma == sumb && suma > 0) return;
    a.push_back(v[i]);
    suma += v[i];
    rec(i+1);
    if (suma == sumb && suma > 0) return;
    a.pop_back();
    suma -= v[i];
    b.push_back(v[i]);
    sumb += v[i];
    rec(i+1);
    if (suma == sumb && suma > 0) return;
    b.pop_back();
    sumb -= v[i];
    rec(i+1);
}

void solve(int t) {
    cin >> n;
    sum = 0;
    a.clear();
    b.clear();
    suma = sumb = 0;
    for (int i = 0; i < n; ++i) {cin >> v[i];sum += v[i];}
    rec(0);
    cout << "Case #" << t << ":\n";
    if (suma != 0) {
        for (int i = 0; i < (int)a.size(); ++i) cout << a[i] << ' ';
        cout << endl;
        for (int i = 0; i < (int)b.size(); ++i) cout << b[i] << ' ';
        cout << endl;
    } else cout << "Impossible\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve(i+1);

    return 0;
}
