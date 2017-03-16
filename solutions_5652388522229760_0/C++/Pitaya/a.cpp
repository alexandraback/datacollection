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
        cin >> n;
        if (n == 0) {
            cout << "INSOMNIA" << endl;
        } else {
            for (int i = 0; i < 10; i++) {
                counted[i] = false;
            }
            int x = n;
            while (!check(counted)) {
                count_num(x, counted);
                x += n;
            }
            cout << x - n << endl;
        }
    }
    return 0;
}
