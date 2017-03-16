#include <iostream>
#include "../../gcjoutput.h"
#include <vector>
#include <limits>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        vector <int> arr(n);
        int maxval = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
            maxval = max(maxval, arr[j]);
        }

        int minans = numeric_limits<int>::max();
        for (int j = 1; j <= maxval; j++) {
            int ans = j;
            for (int k = 0; k < n; k++)
                ans += arr[k] / j + (arr[k] % j != 0) - 1;
            if (ans < minans)
                minans = ans;
        }

        output << nextCase << minans;

    }
    return 0;
}
