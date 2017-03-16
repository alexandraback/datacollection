#include <iostream>
#include <deque>

using namespace std;

void work(int case_n) {
    string word;
    int n;
    cin >> word >> n;
    const char *ptr = word.c_str();
    deque<int> shortest;
    for (int i = 0; i < word.length() - n + 1; i++) {
        bool isConsecutive = true;
        for (int j = 0; j < n; j++) {
            if (ptr[i + j] == 'a' || ptr[i + j] == 'e' || ptr[i + j] == 'i' || ptr[i + j] == 'o' || ptr[i + j] == 'u') {
                isConsecutive = false;
                break;
            }
        }
        if (isConsecutive) {
            shortest.push_back(i);
        }
    }
    int total = 0;
    for (auto it = shortest.begin(); it != shortest.end(); it++) {
        if (it == shortest.begin()) {
            total += (word.length() - n - (*it) + 1) * ((*it) + 1);
        }
        else {
            total += ((*it) - (*(it - 1))) * (word.length() - (*it) - n + 1);
        }
    }
    cout << "Case #" << case_n << ": " << total << endl;
    
}

int main(void) {
    int n_cases;
    cin >> n_cases;
    for (int i = 0; i < n_cases; i++) {
        work(i+1);
    }
    return 0;
}