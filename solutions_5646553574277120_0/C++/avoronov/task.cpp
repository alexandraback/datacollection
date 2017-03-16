#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void print_answer(int id, int x) {
    cout << "Case #" << id << ": " << x << endl;
}

vector<int> set2vector(set<int>& s) {
    vector<int> v;
    for (auto it = s.begin(); it != s.end(); ++it)
        v.push_back(*it);
    return v;
}

set<int> vector2set(vector<int> &v) {
    set<int> s;
    for (auto it = v.begin(); it != v.end(); ++it)
        s.insert(*it);
    return s;

}

int check_set(set<int> denoms, int max_value) {
    vector<int> dv = set2vector(denoms);
    vector<int> covered(max_value, 0);
    int denom_count = dv.size();

    for (int i = 0; i < (1 << (denom_count)); ++i) {
        int sum = 0;
        for (int j = 0; j < denom_count; ++j) {
            if ((1 << j) & (i + 1))
                sum += dv[j];
        }
        if (sum > 0 && sum <= max_value)
            covered[sum - 1] = 1;
    }

    int result = 0;
    for (int i = 0; i < covered.size(); ++i) {
        if (!covered[i]) {
            cerr << "notcov: " << i + 1;
            return i + 1;
        }
    }
    return 0;
    
}

void process_test(int id) {
    int count, denom_count, max_value;
    cin >> count >> denom_count >> max_value;
    set<int> denoms;
    for (int i = 0; i < denom_count; ++i) {
        int d;
        cin >> d;
        denoms.insert(d);
    }
    cerr << count << " " << denom_count << " " << max_value << endl;

    int result = 0;
    int new_add = check_set(denoms, max_value);

    while (new_add != 0) {
        denoms.insert(new_add);
        ++result;
        new_add = check_set(denoms, max_value);
    }

    cerr << "answer: " << result << endl;
    print_answer(id, result);
}

int main() {
    int test_count;
    cin >> test_count;
    for (int i = 0; i < test_count; ++i) {
        process_test(i + 1);
    }
    return 0;
}