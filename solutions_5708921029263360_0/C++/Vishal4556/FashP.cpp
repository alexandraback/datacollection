#include <iostream>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int J, P, S, K, A[2000], count = 0;
        cin >> J >> P >> S >> K;
        cout << "Case #" << t + 1 << ": ";
        for (int &i : A)
            i = 0;
        for (int k = 1; k <= S; ++k)
            for (int j = 1; j <= P; ++j)
                for (int i = 1; i <= J; ++i)
                    if (A[i * 100 + j * 10] < K && A[j * 10 + k] < K && A[i * 100 + k] < K) {
                        count++;
                        A[i * 100 + j * 10]++;
                        A[j * 10 + k]++;
                        A[i * 100 + k]++;
                    }
        cout << count << endl;
        for (int &i : A)
            i = 0;
        for (int k = 1; k <= S; ++k)
            for (int j = 1; j <= P; ++j)
                for (int i = 1; i <= J; ++i)
                    if (A[i * 100 + j * 10] < K && A[j * 10 + k] < K && A[i * 100 + k] < K) {
                        A[i * 100 + j * 10]++;
                        A[j * 10 + k]++;
                        A[i * 100 + k]++;
                        cout << i << " " << j << " " << k << endl;
                    }

    }
    return 0;
}
