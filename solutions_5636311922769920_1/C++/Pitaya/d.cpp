#include <iostream>

using namespace std;

int main() 
{
    int case_num;
    int k, c, s, x;
    long long sum;
    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++)
    {
        cout << "Case #" << case_id + 1 << ":";
        cin >> k >> c >> s;
        if (s * c < k) {
            cout << " IMPOSSIBLE" << endl;
        } else {
            x = k - 1;
            while (x >= 0) {
                sum = 0;
                for (int i = 0; i < c; i++) {
                    sum = sum * k + x;
                    if (--x < 0) {
                        break;
                    }
                }
                cout << " " << sum + 1;
            }
            cout << endl;
        }
    }
    return 0;
}
