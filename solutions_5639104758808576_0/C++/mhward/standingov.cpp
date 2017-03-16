#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int p;
        cin >> p;
        vector<int> ppl(p+1);
        string ps;
        cin >> ps;
        for (int i = 0; i < ps.size(); ++i)
            ppl[i] = ps[i]-'0';
        /*for (int i = 0; i < ppl.size(); ++i)
            cout << ppl[i] << " ";
        cout << endl;*/
        int count = 0;
        int standing = ppl[0];
        for (int i = 1; i < ppl.size(); ++i) {
            if (i > standing) {
                count += i - standing;
                standing += i - standing;
            }
            standing += ppl[i];
        }
        cout << "Case #" << tc << ": " << count << endl;
    }
    return 0;
}
