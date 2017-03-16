#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        long long ans = 0;

        int A, B, K;
        cin >> A >> B >> K;
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    ans++;
        
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
