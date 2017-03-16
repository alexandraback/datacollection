#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

bool valid(vector<string>& vec) {
    vector<char> hash;
    string s;
    for (int i = 0; i < vec.size(); i++) {
        s += vec[i];
    }
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && (s[i] == s[i-1])) {
            continue;
        }
        hash.push_back(s[i]);
    }
    unordered_set<char> set(hash.begin(), hash.end());
    return (set.size() == hash.size());
}

void dfs(vector<string>& current, vector<string>& vec, int pos, long& count) {
    if (pos == vec.size() || count == 0) {
        return;
    }

    string s = vec[pos];
    for (int i = 0; i <= current.size(); i++) {
        current.insert(current.begin() + i, s);
        if (valid(current)) {
//            count = (count + 1) % 1000000007;
            count = count + 1;
            dfs(current, vec, pos + 1, count);
            current.erase(current.begin() + i);
        }
        else {
            current.erase(current.begin() + i);
        }
    }

    count--;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        vector<string> vec;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string data;
            cin >> data;
            vec.push_back(data);
        }
        vector<string> current;
        current.push_back(vec[0]);
        long count = 1;
        dfs(current, vec, 1, count);
        cout << "Case #" << t << ": ";
        cout << count << endl;
    }
}
