/**
* Change is impossible in this fog of ignorance.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
using namespace std;

#define trace(x) {cerr << #x << "=" << x <<endl;}
#define trace2(x, y) {cerr << #x << "=" << x << " " << #y << "=" << y <<endl;}
#define track(x) {cerr << #x << ":" << endl; for (int q = 0; q < x.size(); q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackarr(x, n) {cerr << #x << ":" << endl; for (int q = 0; q < n; q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackvv(x) {cerr << #x << ":" << endl; for (int i = 0; i < x.size(); i++) { cerr << "i:" << i << endl; for (int j = 0; j < x[i].size(); j++){cerr << x[i][j] << " ";} cerr << endl;} cerr << endl;}
#define trackcr(x) {cerr << #x << ":" << endl; for (auto i = x.begin(); i != x.end(); i++) {cerr << *i << " ";} cerr << endl;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

typedef long long ll;

const int MAX = 100005;
const int MOD = 1000000000+7;
const int INF = 1000000000;

void inout() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
}

string digits[15] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void doTask() {
    vector<int> f(256);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        f[s[i]]++;
    }

    int Count[15]={};
    Count[0] = f['Z'];
    Count[2] = f['W'];
    Count[4] = f['U'];
    Count[6] = f['X'];
    Count[8] = f['G'];
    for (int i = 0; i <= 8; i+=2) {
        string word = digits[i];
        for (int j = 0; j < word.size(); j++) {
            char c = word[j];
            f[c] -= Count[i];
        }
    }

    Count[1] = f['O'];
    Count[3] = f['R'];
    Count[5] = f['F'];
    Count[7] = f['S'];

    for (int i = 1; i <= 9; i+=2) {
        string word = digits[i];
        for (int j = 0; j < word.size(); j++) {
            char c = word[j];
            f[c] -= Count[i];
        }
    }

    Count[9] = f['I'];

    string answer;
    for (int i = 0; i <= 9; i++) {
        while (Count[i]--) {
            answer.push_back(i+'0');
        }
    }
    cout << answer << endl;
}

int main() {
    inout();
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        doTask();
    }
}
