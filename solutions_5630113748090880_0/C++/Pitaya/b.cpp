#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    int case_num;
    int n, x;
    int count[2501];

    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++)
    {
        cout << "Case #" << case_id + 1 << ":";
        memset(count, 0, sizeof(count));
        cin >> n;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                count[x]++;
            }
        }
        for (int i = 1; i <= 2500; i++) {
            if (count[i] % 2 != 0) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
    return 0;
}
