#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 1, T, K, C, S;

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        cin >> K >> C >> S;
        cout << "Case #" << TC << ": ";
        for (int i = 1; i <= S; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
