#include <iostream>
#include <string>

using namespace std;

#define all(a) begin(a),end(a)
#define sz(a) ((int)((a).size()))

void solve_case(int case_id);

int main() {
    int num_case;
    cin >> num_case;
    for (int i=1; i<=num_case; i++)
        solve_case(i);
    return 0;
}

void solve_case(int case_id) {
    string s;
    cin >> ws >> s;
    int ans = 0;
    for (int i = 0; i < sz(s) - 1; i++)
        if (s[i] != s[i+1])
            ans++;
    if (s[sz(s)-1] == '-')
        ans++;
    cout << "Case #" << case_id << ": " << ans << '\n';
}
