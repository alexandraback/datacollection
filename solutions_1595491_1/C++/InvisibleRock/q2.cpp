#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Case {
    int n;
    int p;
    int s; 
    int* totals;
};

vector<Case> parse() {
    vector<Case> ret;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        Case c;
        cin >> c.n;
        cin >> c.s;
        cin >> c.p;
        c.totals = new int[c.n];
        for (int j = 0; j < c.n; j++) {
           cin >> c.totals[j]; 
        }
        ret.push_back(c);
    }
    return ret;
}

void dump(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << "Case #" << (i+1) << ": " << v[i] << endl;
    }
}

int compute(Case& c) {
    int result = 0;
    int iffy = 0;
    for (int i = 0; i < c.n; i++) {
        if (c.totals[i] < 2) {
            if (c.totals[i] >= c.p) {
                result++;
            }
            continue;
        }
        int large = (c.totals[i] - 2) / 3 + 2;
        int small = large - 1;
        if (small >= c.p) {
            result++;
            continue;
        }
        if (large < c.p) {
            continue;
        }
        if (c.totals[i] % 3 == 1) {
            if (large >= c.p) {
                result++;
            }
            continue;  
        }
        iffy++;
    }
    result += min(iffy, c.s);
    return result;
}

int main() {
    vector<Case> input = parse();

    vector<int> output;
    for (size_t i = 0; i < input.size(); i++) {
        output.push_back(compute(input[i]));
    }

    dump(output);
}
