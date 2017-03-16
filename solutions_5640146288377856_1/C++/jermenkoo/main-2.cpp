#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double T, t, R, C, W, answer;
    cin >> T;
    for(t = 1; t <= T; t++) {
        cin >> R >> C >> W;
        answer = (ceil(C / W) * R + (W - 1));
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
