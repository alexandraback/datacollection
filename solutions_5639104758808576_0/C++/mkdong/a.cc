#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int i;
    for (int i=0; i<T; ++i) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int stands = 0;
        int ans = 0;
        for (int j=0; j<n+1; ++j) {
            if (stands < j) {
                ans += j - stands;
                stands = j;
            }
            stands += s[j] - '0';
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}
