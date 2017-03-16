#include <iostream>

using namespace std;

int tests, d, p[1001], answer, tmp;

int main() {
    cin >> tests;
    for (int test = 0 ; test < tests ; test ++) {
        cin >> d;
        for(int i = 0 ; i < d ; i ++) {
            cin >> p[i];
        }
        answer = 1000;
        for (int j = 1 ; j <= 1000 ; j ++) {
            tmp = j;
            for (int i = 0 ; i < d ; i ++) {
                tmp += (p[i] - 1) / j;
            }
            if (tmp < answer) answer = tmp;
        }
        cout << "Case #" << test + 1 << ": " << answer << endl;
    }
    return 0;
}
