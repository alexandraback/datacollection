#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;

#define all(X) (X).begin(), (X).end()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int mod = 1e9 + 7;
const int maxn = 100001;

string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int freq[300];

void remove(int idx) {
    for (int i = 0; i < num[idx].size(); ++i) {
        freq[num[idx][i]]--;
    }
}

int main() {
    int T, N;
    string s, t;
    cin >> T;
    for (int _test = 1; _test <= T; ++_test) {
        cout << "Case #" << _test << ": ";
        cin >> s;
        t = "";
        N = s.size();
        fill(freq, freq + 300, 0);
        for (int i = 0; i < N; ++i) {
            freq[s[i]]++;
        }
        while (freq['Z']) {
            t += '0';
            remove(0);
        }
        while (freq['W']) {
            t += '2';
            remove(2);
        }
        while (freq['U']) {
            t += '4';
            remove(4);
        }
        while (freq['G']) {
            t += '8';
            remove(8);
        }
        while (freq['O']) {
            t += '1';
            remove(1);
        }
        while (freq['R']) {
            t += '3';
            remove(3);
        }
        while (freq['X']) {
            t += '6';
            remove(6);
        }
        while (freq['F']) {
            t += '5';
            remove(5);
        }
        while (freq['V']) {
            t += '7';
            remove(7);
        }
        while (freq['N']) {
            t += '9';
            remove(9);
        }
        sort(all(t));
        cout << t << "\n";
    }
    return 0;
}