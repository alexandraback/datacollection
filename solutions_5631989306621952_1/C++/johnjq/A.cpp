#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

string s;
string solve(const int i, const int j) {
    string ans;
    if (i > j)
        return ans;
    if (i == j) {
        ans.push_back(s[i]);
        return ans;
    }

    int best = i;
    for (int c = i+1; c <= j; ++c)
        if (s[c] >= s[best])
            best = c;

    ans.push_back(s[best]);
    ans += solve(i, best-1);
    for (int c = best+1; c <= j; ++c)
        ans.push_back(s[c]);
    return ans;
}

int main() {
    int testcases;
    cin>>testcases;
    for (int t = 1; t <= testcases; ++t) {
        cin>>s;
        const int n = s.size();
        cout<<"Case #"<<t<<": "<<solve(0, n-1)<<endl;
    }
}
