#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream ifs("D-small-attempt1.in");
    ofstream ofs("D-small-attempt1.out");
    int num;
    ifs >> num;
    for (int i = 1; i <= num; i++) {
        int k, c, s;
        ifs >> k >> c >> s;
        ofs << "Case #" << i << ":";
        if (k == 1) ofs << " 1\n";
        else if (c == 1) {
            if (s < k) ofs << " IMPOSSIBLE\n";
            else {
                for (int i = 1; i <= k; i++) ofs << ' ' << i;
                ofs << endl;
            }
        }
        else {
            int needed = k / 2;
            if (k % 2 == 1) needed++;
            if (s < needed) ofs << " IMPOSSIBLE\n";
            else {
                if (k % 2 == 1) needed--;
                vector<int> result;
                int current = 2;
                for (int j = 0; j < needed; j++) {
                    result.push_back(current);
                    current += 2 * k + 2;
                }
                if (k % 2 == 1) result.push_back(current - k - 1);
                long long factor = pow(k, c - 2);
                for (int k = 0; k < result.size(); k++) {
                    ofs << ' ' << result[k] * factor;
                }
                ofs << endl;
            }
        }
    }
}