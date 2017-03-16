#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int id = 1; id <= T; ++id) {
        string s;
        cin >> s;
        int N;
        cin >> N;

        long long cnt = 0;
        int last = -1;
        int cons = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                    s[i] == 'o' || s[i] == 'u') {
                cons = 0;
                cnt += static_cast<long long>(last + 1);
            } else {
                ++cons;
                if (cons == N) {
                    --cons;
                    last = i - N + 1;
                }
                cnt += static_cast<long long>(last + 1);
            }
        }

        cout << "Case #" << id << ": " << cnt << "\n";
    }

    return 0;
}
