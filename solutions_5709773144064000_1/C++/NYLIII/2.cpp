#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        double C, F, X;
        cin >> C >> F >> X;
        double total = 0, wage = 2;
        while ((X / wage) > (C / wage + X / (wage + F))) {
            total += C / wage;
            wage += F;
        }
        total += X / wage;
        cout << "Case #" << test << ": ";// << showpoint << total << endl;
        printf("%.7lf\n", total);
    }
    return 0;
}



