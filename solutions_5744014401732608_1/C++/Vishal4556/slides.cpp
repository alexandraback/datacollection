#include <iostream>
using namespace std;

typedef long long int lli;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        lli B, M;
        cin >> B >> M;
        cout << "Case #" << t + 1 << ": ";
        if ((1 << (B - 2)) < M)
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            cout << 0;
            for (int i = 1; i < B - 1; i++)
                cout << 1;
            if (M == (1 << (B - 2))) {
                M--;
                cout << 1;
            } else
                cout << 0;
            cout << endl;

            for (int i = 1; i < B - 1; i++) {
                for (int j = 0; j <= i; j++)
                    cout << 0;
                for (int j = i + 1; j < B - 1; j++)
                    cout << 1;
                cout << (M % 2);
                M /= 2;
                cout << endl;
            }
            for (int i = 0; i < B; i++)
                cout << 0;
            cout << endl;
        }
    }
    return 0;
}
