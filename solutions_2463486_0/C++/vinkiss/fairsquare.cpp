#include <iostream>

using namespace std;

int main () {
        int t,a,b;
        int x = 0;
        cin >> t;
        int ar[] = {1, 4, 9, 121,484};

        while (t--) {
            x++;
            int cnt = 0;
            cin >> a >> b;

            for (int i = 0; i <= 4; i++) {

                if (ar[i] >= a) {

                    while (ar[i] <= b && i <= 4) {
                        i++;
                        cnt++;
                    }
                }
            }
        cout << "Case #" << x <<": " << cnt << endl;
        }
        return 0;
}
