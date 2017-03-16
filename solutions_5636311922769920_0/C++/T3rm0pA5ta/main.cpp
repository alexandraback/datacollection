#include <iostream>
#include <string>
using namespace std;

int main()
{

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int k, c, s;
        cin >> k >> c >> s;

        cout << "case #" << i + 1 << ": ";
        for (int i = 0; i < s; i++) {
            cout << i + 1 << " ";
        }
        cout << "\n";

    }
    return 0;
}
