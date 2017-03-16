#include <iostream>
#include <string>
using namespace std;

int T, L;
long long X;

char str[123456];
string s;
int lsum[123456];
int rsum[123456];

int mult[8][8] = {{0, 1, 2, 3, 4, 5, 6, 7},
                  {1, 4, 3, 6, 5, 0, 7, 2},
                  {2, 7, 4, 1, 6, 3, 0, 5},
                  {3, 2, 5, 4, 7, 6, 1, 0},
                  {4, 5, 6, 7, 0, 1, 2, 3},
                  {5, 0, 7, 2, 1, 4, 3, 6},
                  {6, 3, 0, 5, 2, 7, 4, 1},
                  {7, 6, 1, 0, 3, 2, 5, 4}};

void solve_case(int t) {
    cout << "Case #" << t << ": ";

    cin >> L >> X >>  s;
    if (X > 11) X = 8 + X % 4;
    for (int i = 0; i < L; ++i) {
        str[i] = s[i];
    }   
    int len = L;
    L *= X;
    for (int i = len; i < L; ++i) {
        str[i] = str[i - len];
    }   

    int sum = 0;
    for (int i = 0; i < L; ++i) {
        sum = mult[sum][str[i] - 'h'];
    }
    if (sum != 4) {
        cout << "NO\n";
        return;
    }

    sum = 0;
    int best_left = L + 1000;
    for (int i = 0; i < L; ++i) {
        sum = mult[sum][str[i] - 'h'];
        if (sum == 1) {
            best_left = i;
            break;
        }
    }

    sum = 0;
    int best_right = -1000;
    for (int i = L - 1; i >= 0; --i) {
        sum = mult[str[i] - 'h'][sum];
        if (sum == 3) {
            best_right = i;
            break;
        }
    }

    if (best_right >= best_left + 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin >> T;
    for (int i=1; i <= T; ++i) solve_case(i);
    return 0;
}
