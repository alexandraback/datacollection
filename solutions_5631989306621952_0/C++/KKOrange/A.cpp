#include <iostream>
#include <vector>

using namespace std;
int T, L;
string s;
vector<char> v;
int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> s;
        L = s.size();
        v.clear();
        for(int i = 0; i < L; i++) {
            if(v.size() == 0 || v[0] <= s[i]) {
                v.insert(v.begin(), s[i]);
            } else {
                v.push_back(s[i]);
            }
        }
        cout << "Case #" << t << ": ";
        for(int i = 0; i < L; i++) {
            cout << v[i];
        }
        cout << "\n";
    }
    return 0;
}
