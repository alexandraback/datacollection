#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

bool asc(double x, double y) {
    return x < y;
}

bool desc(double x, double y) {
    return x > y;
}

double naomi[1000];
double ken[1000];

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> naomi[i];
        for (int i = 0; i < N; i++) cin >> ken[i];
        sort(naomi, naomi + N, desc);
        sort(ken, ken + N, desc);

        int pt1 = 0, pt2 = 0;
        for (int k = 0, i = 0, j = 0; k < N; k++) {
            if (ken[k] < naomi[i]) {
                pt1++;
                i++;
            }
            
            if (naomi[k] > ken[j]) pt2++;
            else j++;
        }
        cout << pt1 << ' ' << pt2 << endl;
    }
    return 0;
}



