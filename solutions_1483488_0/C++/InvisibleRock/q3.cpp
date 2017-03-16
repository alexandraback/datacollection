#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

typedef pair<int, int> pint;

vector<pint> parse() {
    vector<pint> ret;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int A, B;
        cin >> A;
        cin >> B;
        ret.push_back(pint(A, B));
    }
    return ret;
}

void dump(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << "Case #" << (i+1) << ": " << v[i] << endl;
    }
}

string itos(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

void rotate(string& m) {
    char start = m[0];
    for (size_t i = 0; i < m.size() - 1; i++) {
        m[i] = m[i+1];
    }
    m[m.size()-1] = start;
}


int compute(pint& p) {
    int A = p.first;
    int B = p.second;
    int result = 0;
    int digits = itos(A).size();
    //cout << A << " " << B << endl;
    bool checked[2000001] = {0};

    for (int i = A; i <= B; i++) {
        if (checked[i]) continue;
        string m = itos(i);
        int cnt = 1;
        for (int j = 0; j < digits - 1; j++) {
            rotate(m);
            int m_i = atoi(m.c_str());
            if (m_i == i) break;
            if (m_i <= B && m_i >= A) {
                //cout << i << " " << m_i << endl;
                checked[m_i] = true;
                cnt++;
            }
        }
        result += cnt * (cnt - 1) / 2;
    }

    //cout << "XXX" << endl;
    
    return result;
}

int main() {
    vector<pint> input = parse();

    vector<int> output;
    for (size_t i = 0; i < input.size(); i++) {
        output.push_back(compute(input[i]));
    }

    dump(output);
}
