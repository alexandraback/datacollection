#include <iostream>
#include <climits>

using namespace std;

int solver(int N)
{
    int history = 0;
    int compared = (1 << 10) - 1; // 1023
    int i = 1;

    if (N == 0) return -1;

    while(history != compared) {
        int value = N * i;
        while (value != 0) {
            int digit = value % 10;
            history = history | (1 << digit);
            value = value / 10;
        }
        i++;
    }
    
    return N * (i - 1);
}


int main()
{
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int sol;
        cin >> N;

        cout << "Case #" << (i + 1) << ": ";
        if ((sol = solver(N)) != -1)
            cout << sol << endl;
        else
            cout << "INSOMNIA" << endl;
    }

    return 0;
}