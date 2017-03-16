#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

long long mod = 1e9+7;

bool valid(vector<int> &d, vector<string> &t) {
    string res = "";
    for(int i = 0; i < d.size(); i++)
        res.append(t[d[i]]);

    res.resize(unique(res.begin(), res.end())-res.begin());
    vector<char> was(256, 0);
    for(int i = 0; i < res.size(); i++) {
        if(was[res[i]])
            return false;
        was[res[i]] = true;
    }
    return true;
}

string simple(string s) {
    return string(1, s[0])+""+string(1, s[s.size()-1]);
}

int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int N;
        cin >> N;

        vector<int> d(N);
        vector<string> train(N);
        for(int i = 0; i < N; i++) {
            cin >> train[i];
            //train[i] = simple(train[i]);
            d[i] = i;
        }

        int res = 0;
        do {
            res += valid(d, train);
        } while(next_permutation(d.begin(), d.end()));

        printf("%d\n", res);
    }

    return 0;
}
