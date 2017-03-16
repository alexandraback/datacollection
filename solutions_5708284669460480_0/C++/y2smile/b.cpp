#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
    string filename ("input_b");
    string line;
    ifstream file (filename);
    int k;

    //
    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        int k, l, s;
        int keys[26] = {0};
        long double probs[26];
        long double target_prob;
        string target;

        // parsing
        getline (file, line);

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                k = stoi(line.substr(0, i));
                line = line.substr(i + 1, line.size() - i - 1);
                break;
            }
        }

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                l = stoi(line.substr(0, i));
                s = stoi(line.substr(i + 1, line.size() - i - 1));
                break;
            }
        }

        getline (file, line);
        for (int i = 0; i < k; i++) {
            int tmp = line[i] - 'A';
            keys[tmp]++;
        }

        getline (file, target);

        // main
        for (int i = 0; i < 26; i++) {
            probs[i] = ((long double)keys[i]) / ((long double) k);
        }

        target_prob = 1;
        for (int i = 0; i < target.size(); i++) {
            target_prob *= probs[target[i] - 'A'];
        }

        if (target_prob == 0) {
            cout << "Case #" << t+1 << ": 0.0"  << "\r\n";
            continue;
        }

        int min_overlap = target.size();
        for (int o = 1; o < target.size(); o++) {
            int i;
            for (i = 0; i + o < target.size(); i++) {
                if (target[i] != target[i + o]) break;
            }
            if (i + o == target.size()) {
                min_overlap = o;
                break;
            }
        }

        int max_banana = 1 + floor(((double)(s - target.size()))/((double)(min_overlap)));
        long double expected_banana = ((long double)(s - l + 1)) * target_prob;
        long double res = ((long double) max_banana) - expected_banana;

        cout << "Case #" << t+1 << ": " << res  << "\r\n";
        /*
        for (int i = 0; i < 26; i++) {
            cout << keys[i] << " ";
        }
        cout << "\r\n";
        cout << target_prob << " " << min_overlap << " " << max_banana << "\r\n";
        */
    }

    return 0;
}