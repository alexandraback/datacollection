#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool occ[27];

bool check(const string &s) {
    memset(occ, false, sizeof(occ));
    char prev = 'A';
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != prev) {
            if (occ[s[i]-'a']) return false;
            prev = s[i];
            occ[prev-'a'] = true;
        }
    }
    return true;
}

int solve() {
    int N;
    cin>>N;
    vector<string> v(N);
    vector<int> perm(N);
    for (int i = 0; i < N; ++i) {
        cin>>v[i];
        perm[i] = i;
    }

    int ans = 0;
    do {
        string s = "";
        for (int i = 0; i < v.size(); ++i) s += v[perm[i]];
        if (check(s)) ans++;
    } while (next_permutation(begin(perm), end(perm)));
    return ans;
}

int main() {
    int N;
    cin>>N;

    for (int i = 0; i < N; ++i) {
        cout<<"Case #"<<i+1<<": ";
        cout<<solve()<<endl;
    }
}
