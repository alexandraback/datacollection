#include <iostream>
using namespace std;

int main()
{
    int T, N;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cin >> N;
        int count[10] = {0,0,0,0,0,0,0,0,0,0}, i;
        for (i = 1; i < 100; i++) {
            int M = i * N;
            while (M > 0) {
                count[M%10]++;
                M /= 10;
            }
            bool finished = true;
            for (int j = 0; j < 10; j++) {
                if (count[j] == 0) {
                    finished = false;
                    break;
                }
            }
            if (finished) break;
        }
        cout << "Case #" << c << ": ";
        if (i == 100) cout << "INSOMNIA";
        else cout << i * N;
        cout << endl;
    }
    return 0;
}
