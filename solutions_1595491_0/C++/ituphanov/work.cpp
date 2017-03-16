#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int i, j, k;

    int tests;
    cin >> tests;
    for (int sc = 0; sc < tests; sc++) {
        int n, s, p;
        int num[3];
        num[0] = num[1] = num[2] = 0;
        cin >> n >> s >> p;
        for (i = 0; i < n; i++) {
            int x;
            cin >> x;
            int max_good;
            int max_bad;
            switch (x % 3) {
            case 0:
                max_good = x/3;
                max_bad = x == 0 ? 0 : x/3-1 + 2;
                break;
            case 1:
                max_good = x/3 + 1;
                max_bad = x == 1 ? 0 : x/3-1 + 2;
                break;
            case 2:
                max_good = x/3 + 1;
                max_bad = x/3 + 2;
                break;
            }
            if (max_bad > 10) max_bad = 0;
            if (max_good > 10) max_good = 0;

            if (max_good >= p) num[1]++;
            else if (max_bad >= p) num[2]++;
            else num[0]++;
        }

        cout << "Case #" << sc+1 << ": ";
        cout << num[1] + min(num[2], s); 
        cout << endl;
    }

    fclose(stdin); fclose(stdout);
    return 0;
}
