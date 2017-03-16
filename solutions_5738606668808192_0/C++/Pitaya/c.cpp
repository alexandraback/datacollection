#include <iostream>

using namespace std;

int main() 
{
    int case_num;
    int n, j;
    bool digits[32];
    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++)
    {
        cout << "Case #" << case_id + 1 << ": " << endl;
        cin >> n >> j;
        for (int even_first = 2; even_first < n; even_first += 2) {
            for (int even_second = even_first + 2; even_second < n; even_second += 2) {
                for (int odd_first = 1; odd_first < n - 1; odd_first += 2) {
                    for (int odd_second = odd_first + 2; odd_second < n - 1; odd_second += 2) {
                        for (int digit = 0; digit < n; digit++) {
                            if (digit % 2 == 0) {
                                if (digit == 0 || digit == even_first || digit == even_second) {
                                    cout << 1;
                                } else {
                                    cout << 0;
                                }
                            } else {
                                if (digit == n - 1 || digit == odd_first || digit == odd_second) {
                                    cout << 1;
                                } else {
                                    cout << 0;
                                }
                            }
                        }
                        cout << " 3 2 5 2 7 2 9 2 11" << endl;
                        j--;
                        if (j == 0) {
                            break;
                        }
                    }
                    if (j == 0) {
                        break;
                    }
                }
                if (j == 0) {
                    break;
                }
            }
            if (j == 0) {
                break;
            }
        }
    }
    return 0;
}
