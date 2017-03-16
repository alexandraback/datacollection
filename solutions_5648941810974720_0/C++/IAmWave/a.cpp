// * (Partaking in worthless garbage fills you with determination.)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    vector<int> a(128, 0), b(10, 0);
    int n = s.length();
    rep(i,0,n){
        a[s[i]]++;
    }
    while(a['Z']){
        a['Z']--, a['E']--, a['R']--, a['O']--, b[0]++;
    }
    while(a['W']){
        a['T']--, a['W']--, a['O']--, b[2]++;
    }
    while(a['U']){
        a['F']--, a['O']--, a['U']--, a['R']--, b[4]++;
    }
    while(a['X']){
        a['S']--, a['I']--, a['X']--, b[6]++;
    }
    while(a['G']){
        a['E']--, a['I']--, a['G']--, a['H']--, a['T']--, b[8]++;
    }
    //
    while(a['O']){
        a['O']--, a['N']--, a['E']--, b[1]++;
    }
    while(a['R']){
        a['T']--, a['H']--, a['R']--, a['E']--, a['E']--, b[3]++;
    }
    while(a['F']){
        a['F']--, a['I']--, a['V']--, a['E']--, b[5]++;
    }
    while(a['S']){
        a['S']--, a['E']--, a['V']--, a['E']--, a['N']--, b[7]++;
    }
    b[9] = a['I'];
    rep(i,0,10){
        rep(j,0,b[i]) cout << i;
    }
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(i, 0, q) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
