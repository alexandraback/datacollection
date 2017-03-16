#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<string> first, last;
        int dup = 0;
        for (int j = 0; j < n; j++) {
            string f, l;
            cin >> f >> l;
            first.push_back(f);
            last.push_back(l);
        }

        for (int j = 0; j < first.size(); j++) {
            string f = *(first.begin()), l = *(last.begin());
            first.erase(first.begin());
            last.erase(last.begin());

            if (find(first.begin(), first.end(), f) != first.end() && find(last.begin(), last.end(), l) != last.end())
                dup++;

            first.push_back(f);
            last.push_back(l);
        }

        cout << "Case #" << i + 1 << ": " << dup << endl;
    }
    return 0;
}