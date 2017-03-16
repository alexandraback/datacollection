#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


//vector<int> get_prime_numbers(int maximum) {
    
//}

bool find(int size, int* values, int target, int current, int pos, int* result) {
    if (pos >= size) return false;
    if ((result[pos] & 1) != 0) {
        return find(size, values, target, current, pos + 1, result);
    }
    int next = values[pos] + current;
    if (next > target) {
        return false;
    } else if (next == target) {
        // for (int i = pos; i < size; i++) {
        //     result[pos] &= 1;
        // }
        result[pos] |= 2;
        return true;
    } else {
        if (find(size, values, target, next, pos + 1, result)) {
            result[pos] |= 2;
            return true;
        } else if (find(size, values, target, current, pos + 1, result)) {
//        result[pos] = false;
            return true;
        }
        return false;
    }
}

int get_sum(int n, int* values, int* flags) {
    int s = 0;
    // for (int i = 0; i < n; i++) {
    //     cout << values[i] << ":" << flags[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        if ((flags[i] & 1) != 0) {
//            cout << " +" << values[i] << endl;
            s += values[i];
        }
    }
    return s;
}

void show_answer(int cn, int n, int* values, int* flags) {
    // for (int i = 0; i < n; i++) {
    //     cout << values[i] << ":" << flags[i] << endl;
    // }
    cout << "Case #" << cn << ":\n";
    bool first = true;
    for (int i = 0; i < n; i++) {
        if ((flags[i] & 1) != 0) {
            if (!first) cout << " ";
            cout << values[i];
            first = false;
        }
    }
    cout << endl;
    first = true;
    for (int i = 0; i < n; i++) {
        if ((flags[i] & 2) != 0) {
            if (!first) cout << " ";
            cout << values[i];
            first = false;
        }
    }
    cout << endl;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int* values = new int[N];
        int* result = new int[N];
        for (int i = 0; i < N; i++) {
            cin >> values[i];
            //cout << values[i] << " ";
            result[i] = 0;
        }
        // for (int i = 0; i < N; i++) {
        //     cout << values[i] << " ";
        // }
        //cout << endl;

        int fig = 0;
        while (fig < N) {
            if (result[fig] == 0) {
                result[fig] = 1;
                int target = get_sum(N, values, result);
//                cout << "target is " <<  target << " fig " << fig << endl;
                if (find(N, values, target, 0, 0, result)) {
                    show_answer(t + 1, N, values, result);
                    break;
                }
                fig = 0;
            } else {
                result[fig] = 0;
                fig++;
            }
        }
        delete[] values;
        delete[] result;
    }
}
