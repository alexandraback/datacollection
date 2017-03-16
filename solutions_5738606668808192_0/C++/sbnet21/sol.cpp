#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void solver(int N, int J)
{
    for (int i = 0; i < J; i++) {
        long *divisor = new long[9];

        string str(N, '0');
        str.at(0) = str.at(N-1) = '1';

        int high = N/2;
        if (N % 2 == 1) high += 1;

        str.at(high) = str.at(N/2-1) = '1';

        int j = 1;
        int k = i+1;

        for (int m = 0; m < 9; m++)
            divisor[m] = 1 + pow(m+2, N/2-1);

        while(k != 0) {
            int l = k % 2;
            k = k / 2;
            str.at(j) = str.at(high+j) = l+'0';
            if (l == 1) {
                for (int m = 0; m < 9; m++)
                    divisor[m] += pow(m+2, N/2-j-1);
            }

            j++;
        }
        cout << str;
        for (int m = 0; m < 9; m++)
            cout << " " << divisor[m];
        cout << endl;

        delete divisor;
    }

}


int main()
{
    int T, N, J;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> J;
        cout << "Case #" << (i+1) << ":" << endl;
        solver(N, J);
    }

    return 0;
}