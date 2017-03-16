#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void process_case() {
    int n;
    cin >> n;
    map<int, int> count;
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            auto it = count.find(temp);
            if (it == count.end()) {
                count[temp] = 1;
            } else {
                ++count[temp];
            }
        }
    }

    vector<int> row;
    for (auto it = count.begin(); it != count.end(); ++it) {
        if (it->second % 2 == 1) {
            row.push_back(it->first);
        }
    }

    sort(row.begin(), row.end());
    for (auto it = row.begin(); it != row.end(); ++it) {
        cout << " " << *it;
    }
}

int main() {
    std::ifstream in("B-small-attempt0.in");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("B-small-attempt0.out");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << (i + 1) << ":";
        process_case();
        cout << endl;
    }

    return 0;
}
