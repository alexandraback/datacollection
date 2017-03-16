#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool allAdjacent(const string& s) {
    int lastPos[26];
    memset(lastPos, -1, sizeof(lastPos));

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (lastPos[c - 'a'] != -1 && lastPos[c - 'a'] != i-1)
            return false;
        lastPos[c - 'a'] = i; 
    }

    return true;
}

string sall;
bool isOk(const vector<string>& s, const vector<int>& perm) {

    int lenSoFar = 0;
    for (int x: perm) {
        copy(s[x].begin(), s[x].end(), sall.begin() + lenSoFar);
        lenSoFar += s[x].size();
    }

    return allAdjacent(sall);
}

int solve(const vector<string>& s) {
    vector<int> perm(s.size());
    iota(perm.begin(), perm.end(), 0);

    int count = 0;
    do {
        if (isOk(s, perm))
            count++;
    } while (next_permutation(perm.begin(), perm.end()));

    return count;
}

vector<string> readData() {
    int n;
    cin >> n;

    vector<string> result;
    int lenTot = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        lenTot += s.length();
        result.push_back(s);
    }

    sall.resize(lenTot);
    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        vector<string> s = readData();
        cout << "Case #" << t << ": " << solve(s) << endl;
    }

    return 0;
}
