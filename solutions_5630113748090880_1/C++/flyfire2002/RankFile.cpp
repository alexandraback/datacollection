#include <iostream>
#include <string>
using namespace std;

string construct(string original) {

}



int main () {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        bool acc [2501] = {false};
        cin >> N;
        int h = 0;
        for (int i = 0; i < 2 * N - 1; i++) {
            for (int j = 0; j < N; j++) {
                cin >> h;
                acc[h] = !acc[h];
            }
        }
        cout << "Case #" << t << ":";
        for (int i = 0; i <= 2500; i++) {
            if (acc[i]) cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}
