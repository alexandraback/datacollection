#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    int T, d, p[1005], ans, maxp, sum;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> d;
        maxp = 0;
        for(int j = 0; j < d; j++) {
            cin >> p[j];
            maxp = max(p[j], maxp);
        }
        ans = maxp;
        for(int j = maxp; j >= 1; j--) {
            sum = j;
            for(int k = 0; k < d; k++) {
                if(p[k] > j) {
                    if(p[k] % j)
                        sum += p[k] / j;
                    else
                        sum += p[k] / j - 1;
                }
            }
            ans = min(ans, sum);
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
