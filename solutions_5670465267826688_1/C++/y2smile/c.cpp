#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class quat_class {
private:
    vector<string> table;
    int signs[4][4];
    int get_idx (char c) {
        if (c == '1') return 0;
        else return (c - 'h');
    }
public:
    quat_class(void) {
        table.push_back("1ijk");
        table.push_back("i1kj");
        table.push_back("jk1i");
        table.push_back("kji1");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                signs[i][j] = 1;
            }
        }
        signs[1][1] = -1;
        signs[1][3] = -1;
        signs[2][1] = -1;
        signs[2][2] = -1;
        signs[3][2] = -1;
        signs[3][3] = -1;
    }

    char multiply (string str, int *sign) {
        char c = str[0];
        char next;

        for (long long i = 1; i < str.size(); i++) {
            next = str[i];
            *sign = *sign * signs[get_idx(c)][get_idx(next)];
            c = table[get_idx(c)][get_idx(next)];
        }
        return c;
    }

    int lookfor_forward (string str, char target, int sign) {
        char c = str[0];
        char next;
        int s = 1;

        if (c == target && sign == s) return 1;
        for (long long i = 1; i < str.size() * 4; i++) {
            next = str[i % str.size()];
            s = s * signs[get_idx(c)][get_idx(next)];
            c = table[get_idx(c)][get_idx(next)];
            if (c == target && sign == s) return i + 1;
        }
        return 0;
    }

    int lookfor_backward (string str, char target, int sign) {
        char c = str[str.size()-1];
        char next;
        int s = 1;

        if (c == target && sign == s) return 1;
        for (long long i = 1; i < str.size() * 4; i++) {
            next = str[(str.size()-1-i)%str.size()];
            s = s * signs[get_idx(next)][get_idx(c)];
            c = table[get_idx(next)][get_idx(c)];
            if (c == target && sign == s) return i + 1;
        }
        return 0;
    }
};

int main() {
    string filename ("input_c");
    string line;
    ifstream file (filename);
    quat_class quat;
    int k;

    //
    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        bool res;
        int sign = 1;
        long long L, X;
        string input;

        // parsing
        getline (file, line);
        for (long long i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                L = stoll(line.substr(0, i));
                X = stoll(line.substr(i+1, line.size()-i-1));
                break;
            }
        }

        getline (file, line);

        // check first condition
        char c = quat.multiply(line, &sign);
        //cout << "c: " << c << ", sign: " << sign << ", X: " << X << "\n";

        if (c == '1' && (sign == 1 || X % 2 == 0)) res = false;
        else if (c != '1' && X % 4 != 2) res = false;
        else {
            //passed first condition
            int a = quat.lookfor_forward(line, 'i', 1);
            int b = quat.lookfor_backward(line, 'k', 1);

            //check second condition
            if (a == 0 || b == 0 || a + b >= L * X)
                res = false;
            else
                res = true;
            //cout << a << " " << b << "\n";
        }

        if (res) {
            cout << "Case #" << t+1 << ": " << "YES" << "\n";
        } else {
            cout << "Case #" << t+1 << ": " << "NO" << "\n";
        }

        //cout << "L: " << L << ", X: " << X << "\n";
    }

    return 0;
}