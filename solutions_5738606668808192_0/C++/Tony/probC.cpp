
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void print_all(int N, int J) {
    // need N even
    // need choose(N / 2 - 1, 2)^2 >= J
    for (int i1 = 1; i1 + 1 < N; i1 += 2)
        for (int i2 = 1; i2 < i1; i2 += 2)
            for (int i3 = 2; i3 + 1 < N; i3 += 2)
                for (int i4 = 2; i4 < i3; i4 += 2) {
                    string s(N, '0');
                    s[0] = '1';
                    s[N - 1] = '1';
                    s[i1] = s[i2] = s[i3] = s[i4] = '1';

                    cout << s;
                    for (int b = 2; b <= 10; b++)
                        cout << " " << b + 1;
                    cout << endl;

                    J--;
                    if (J == 0)
                        return;
                }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, J;
        cin >> N >> J;
        cout << "Case #" << t << ":" << endl;
        print_all(N, J);
    }
}
