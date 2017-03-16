#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int A, B, K;
        cin >> A >> B >> K;

        int result = 0;
        for (int a = 0; a < A; a ++) {
            for (int b = 0; b < B; b++) {
                if ((a & b) < K) {
                    result += 1;
                }
            }
        }

        cout << "Case #" << t + 1 << ": ";
        cout << result;
        cout << std::endl;
    }
}
