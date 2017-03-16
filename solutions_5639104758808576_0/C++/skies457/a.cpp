#include <iostream>
using namespace std;

char audience[1005];

int main()
{
    int T, n, s;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> n >> audience;
        s = audience[0] - '0';
        int ans = 0;
        for(int j = 1; j <= n; j++) {
            if(audience[j] - '0' && j > s) {
                ans += j - s;
                s = j;
            }
            s += audience[j] - '0';
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
