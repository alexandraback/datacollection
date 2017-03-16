#include <iostream>

using namespace std;

#define HHH 1002

int s;
int p[HHH];

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> s;
        string ptemp;
        cin >> ptemp;
        for (int i = 0; i <= s; i++) {
            p[i] = ptemp[i] - '0';
        }

        int ans = 0;
        int acc = p[0];
        int need = 0;
        for (int i = 1; i <= s; i++) {
            if (p[i] == 0)
                continue;

            need = max(0, i - acc);
            ans += need;
            acc += p[i] + need;

            // cout << "i = " << i << ", need = " << need << ", acc = " << acc << ", ans = " << ans << endl;
        }

        cout << "Case #" << c << ": " << ans << endl;
    }
}