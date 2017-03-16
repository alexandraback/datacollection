//#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <deque>

using namespace std;

typedef double ld;
typedef long long ll;

const ld EPS = 1e-2;
const int INF = (int) 1e9;
const int N = (int) 2e3 + 5;
const ll M = (long long) 1e9 + 7;

vector <int> solve(string &s) {
    map <char, int> cnt;
    vector <int> res;
    int n = s.length();
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    while (cnt['Z']) {
        res.push_back(0);
        cnt['Z']--, cnt['E']--, cnt['R']--, cnt['O']--;
    }

    while (cnt['W']) {
        res.push_back(2);
        cnt['W']--, cnt['T']--, cnt['O']--;
    }

    while (cnt['U']) {
        res.push_back(4);
        cnt['F']--, cnt['U']--, cnt['R']--, cnt['O']--;
    }

    while (cnt['X']) {
        res.push_back(6);
        cnt['S']--, cnt['I']--, cnt['X']--;
    }

    while (cnt['G']) {
        res.push_back(8);
        cnt['I']--, cnt['E']--, cnt['G']--, cnt['H']--, cnt['T']--;
    }

    while (cnt['F']) {
        res.push_back(5);
        cnt['F']--, cnt['E']--, cnt['I']--, cnt['V']--;
    }

    while (cnt['R']) {
        res.push_back(3);
        cnt['T']--, cnt['H']--, cnt['R']--, cnt['E'] -= 2;
    }

    while (cnt['O']) {
        res.push_back(1);
        cnt['N']--, cnt['E']--; cnt['O']--;
    }

    while (cnt['S']) {
        res.push_back(7);
        cnt['S']--, cnt['E'] -= 2, cnt['V']--, cnt['N']--;
    }

    while (cnt['N']) {
        res.push_back(9);
        cnt['N'] -= 2, cnt['E']--, cnt['I']--;
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t + 1 << ": ";
        vector <int> ans = solve(s);
        for (int i = 0; i < (int)ans.size(); i++)
            cout << ans[i];

        cout << endl;

    }
	return 0;
}

