#include <stdio.h>
#include <iostream>

using namespace std;

int a[2001];

int main()
{
    int T;
    cin >> T;
    for (int i=0; i<T; ++i) {
        int n;
        cin >> n;
        int max = 0;
        for (int j=0; j<n; ++j) {
            cin >> a[j];
            if (a[j] > max) max = a[j];
        }
        for (int j=1; j<max; ++j) {
            int bonus = 0;
            for (int k=0; k<n; ++k) {
                if (a[k] > j) {
                    bonus += (a[k] + j-1) / j - 1;
                }
            }
            if (bonus + j < max) {
                max = bonus + j;
            }
        }
        cout << "Case #" << i+1 << ": " << max << endl;
    }
    return 0;
}
