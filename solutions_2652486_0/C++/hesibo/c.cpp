#include <iostream>
#include <vector>
using namespace std;

bool flag[200][1000];

int main() {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(flag, 0, sizeof(flag));
    for (int a = 2; a <= 5; a++) {
        for (int b = a; b <= 5; b++) {
            for (int c = b; c <= 5; c++) {
                int num = a * 100 + b * 10 + c;
                flag[1][num] = 1;
                flag[a][num] = 1;
                flag[b][num] = 1;
                flag[c][num] = 1;
                flag[a * b][num] = 1;
                flag[b * c][num] = 1;
                flag[a * c][num] = 1;
                flag[a * b * c][num] = 1;
            }
        }
    }
        
    int temp, r, n, m, k;
    cin >> temp;
    cin >> r >> n >> m >> k;
    cout << "Case #1:" << endl;
    for (int i = 0; i < r; i++) {
        int products[12];
        for (int j = 0; j < k; j++) {
            cin >> products[j];
        }
        bool ok = false;
        for (int num = 1; num <= 555; num++) {
            bool check = true;
            for (int j = 0; j < k; j++) {
                if (!flag[products[j]][num]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ok = true;
                cout << num << endl;
                break;
            }
        }
        if (!ok) {
            cout << "222" << endl;
        }
    }
}
