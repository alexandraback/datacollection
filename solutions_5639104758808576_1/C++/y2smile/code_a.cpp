#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


int main() {
    string filename ("input_a");
    string line;
    ifstream file (filename);
    int k;

    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        vector<int> v;
        string str;
        int s_max;
        int s;
        int max_gap = 0;
        char c;

        getline (file, line);

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                s_max = stoi(line.substr(0, i));
                str = line.substr(i + 1, line.size() - i - 1);
            }
        }

        for (int i = 0; i <= s_max; i++) {
            c = str[i];
            s = atoi(&c);
            for (int j = 0; j < s; j++) {
                v.push_back(i);
            }
        }
        //cout << "s_max: " << s_max << ", str: " << str << ", size v: " << v.size() << "\n";

        for (int i = 0; i < v.size(); i++) {
            if (v[i] - i > 0) {
                max_gap = max(max_gap, v[i] - i);
            }
        }

        cout << "Case #" << t+1 << ": " << max_gap << "\n";
    }

    return 0;
}