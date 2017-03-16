#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int ni=0; ni<n; ni++) {
        long m;
        cin >> m;

        if (m == 0) {
            cout << "Case #" << (ni+1) << ": INSOMNIA" << endl;
            continue;
        }

        bool seen[10];
        for (int i=0; i<10; i++) seen[i] = false;

        int left = 10;
        char buf[100];
        long x = m;
        while (true) {
            sprintf(buf, "%ld", x);
            int len = strlen(buf);
            for (int i=0; i<len; i++) {
                int digit = buf[i] - '0';
                if (!seen[digit]) {
                    seen[digit] = true;
                    left --;
                }
            }
            if (left == 0) {
                cout << "Case #" << (ni+1) << ": " << x << endl;
                break;
            }
            x += m;
        }
    }
}
