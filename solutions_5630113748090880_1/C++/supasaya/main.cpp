#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 1, T, N;
int a[2501];
int result[50];

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        cin >> N;
        memset(a, 0, sizeof(a));
        memset(result, 0, sizeof(result));
        for (int i = 0; i < 2*N-1; i++) {
            for (int j = 0; j < N; j++) {
                int tmp;
                cin >> tmp;
                a[tmp]++;
            }
        }
        int k = 0;
        for (int i = 0; i < 2501; i++) {
            if (a[i]!=0 && a[i] % 2 != 0) {
                result[k] = i;
                k++;
            }
        }
        sort(result, result+N);
        cout << "Case #" << TC << ": ";
        for (int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
