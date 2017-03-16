#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x) x

using namespace std;

const int TABLE[8][8] = {
    { 0,1,2,3,4,5,6,7 },
    { 1,4,3,6,5,0,7,2 },
    { 2,7,4,1,6,3,0,5 },
    { 3,2,5,4,7,6,1,0 },
    { 4,5,6,7,0,1,2,3 },
    { 5,0,7,2,1,4,3,6 },
    { 6,3,0,5,2,7,4,1 },
    { 7,6,1,0,3,2,5,4 }
};

const string names[] = {
    "1", "i", "j", "k", "-1", "-i", "-j", "-k"
};

vector<int> make_table(int factor, const vector<int>& targets) {
    vector<int> result(25);

    for (int i = 0; i < 24; i++) {
        int quat = i % 8;
        int pos = i / 8;

        result[i] = 1 << (TABLE[quat][factor] + pos*8);
        if (TABLE[quat][factor] == targets[pos]) {
            result[i] |= 1 << ((pos+1)*8);
        }
    }

    return result;
}

vector<int> mult_table(const vector<int>& a, const vector<int>& b) {
    vector<int> result(25);

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if (a[i] & (1<<j)) {
                result[i] |= b[j];
            }
        }
    }

    return result;
}

void print_table(const vector<int>& a) {
    for (int i = 0; i < 25; i++) {
        int quat = i % 8;
        int pos = i / 8;

        cerr << names[quat] << "@" << pos << " ->";
        for (int j = 0; j < 25; j++) {
            if (a[i] & (1<<j)) {
                int quat2 = j%8;
                int pos2 = j/8;

                cerr << " " << names[quat2] << "@" << pos2;
            }
        }
        cerr << endl;
    }
}

vector<int> pow_table(const vector<int>& a, long long n) {
    if (n == 1) {
        return a;
    } else {
        vector<int> square = mult_table(a, a);
        if (n & 1) {
            return mult_table(pow_table(square, n/2), a);
        } else {
            return pow_table(square, n/2);
        }
    }
};

int main() {
    map<char, int> lookup;
    lookup['i'] = 1;
    lookup['j'] = 2;
    lookup['k'] = 3;

    vector<int> targets = { 1, 2, 3 };

    vector<int> identity(25);
    for (int i = 0; i < 25; i++) {
        identity[i] = 1<<i;
    }

    map<char, vector<int>> table_lookup;
    table_lookup['i'] = make_table(1, targets);
    table_lookup['j'] = make_table(2, targets);
    table_lookup['k'] = make_table(3, targets);

    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        long long L, X;
        cin >> L >> X;

        string seq;
        cin >> seq;

        vector<int> mapping = identity;
        for (int i = 0; i < L; i++) {
            const char c = seq[i];

            vector<int> next = mult_table(mapping, table_lookup[c]);
            mapping = next;
        }

        vector<int> repeated = pow_table(mapping, X);

        bool result = repeated[0] & (1<<24);

        cout << "Case #" << testCase << ": " << (result ? "YES" : "NO") << endl;
    }
}
