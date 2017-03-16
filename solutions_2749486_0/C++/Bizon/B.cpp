#include <iostream>

using namespace std;

void work(int n) {
    int f_x, x = 0;
    int f_y, y = 0;
    cin >> f_x >> f_y;
    cout << "Case #" << n << ": ";
    for (uint64_t i = 1; i < 500; i++) {
        if (f_x > x && i <= f_x - x) {
            x += i;
            cout << "E";
        }
        else if (f_x < x && i <= x - f_x) {
            x -= i;
            cout << "W";
        }
        else if (f_y > y && i <= f_y - y) {
            y += i;
            cout << "N";
        }
        else if (f_y < y && i <= y - f_y) {
            y -= i;
            cout << "S";
        }
        else if (f_y < y) {
            i++;
            y--;
            cout << "NS";
        }
        else if (f_y > y) {
            i++;
            y++;
            cout << "SN";
        }
        else if (f_x < x) {
            i++;
            x--;
            cout << "EW";
        }
        else if (f_x > x) {
            i++;
            x++;
            cout << "WE";
        }
    }
    cout << endl;
}

int main(void) {
    int n_cases;
    cin >> n_cases;
    for (int i = 0; i < n_cases; i++) {
        work(i+1);
    }
    return 0;
}