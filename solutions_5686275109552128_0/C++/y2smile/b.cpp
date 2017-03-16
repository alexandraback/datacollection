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

    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        int res;
        int d;
        int pos = 0;
        int nonspecial;
        vector<int> ps;
        int max_p;

        // parsing
        getline (file, line);
        d = stoi(line);

        getline (file, line);
        while (true) {
            int i;
            for (i = 1; i < line.size(); i++) {
                if (line[i] == ' ') { 
                    int p = stoi(line.substr(0, i));
                    line = line.substr(i + 1, line.size() - i - 1);
                    ps.push_back(p);
                    break;
                }
            }
            if (i == line.size()) {
                ps.push_back(stoi(line));
                break;
            }
        }

        // max(p)
        sort(ps.begin(), ps.end());
        max_p = ps[ps.size()-1];
        res = max_p;

        //
        for (nonspecial = 1; nonspecial < max_p; nonspecial++) {
            int total = nonspecial;
            for (int i = 0; i < ps.size(); i++) {
                double p = (double)(ps[i]);
                total += (int) ceil(p / ((double)(nonspecial))) - 1;
            }
            res = min(res, total);
        }

        //cout << "size ps: " << ps.size() << ", max_p: " << max_p << "\n";
        cout << "Case #" << t+1 << ": " << res << "\n";
    }

    return 0;
}