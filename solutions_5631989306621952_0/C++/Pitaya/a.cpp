#include <iostream>

using namespace std;

void count_num(int x, bool *counted) {
    while (x != 0) {
        counted[x % 10] = true;
        x = x / 10;
    }
}

bool check(bool *counted) {
    for (int i = 0; i < 10; i++) {
        if (!counted[i]) {
            return false;
        }
    }
    return true;
}

int main() 
{
    int case_num;
    int n;
    bool counted[10];
    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++)
    {
        cout << "Case #" << case_id + 1 << ": ";
        string original;
        cin >> original;
        string sorted;
        sorted.insert(sorted.begin(), original[0]);
        for (size_t i = 1; i < original.length(); i++) {
            char x = original[i];
            if (x < sorted[0]) {
                sorted.insert(sorted.end(), x);
            } else {
                sorted.insert(sorted.begin(), x);
            }
            // cout << x << " " << sorted << endl;
        }
        cout << sorted << endl;
    }
    return 0;
}
