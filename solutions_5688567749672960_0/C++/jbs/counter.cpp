#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 1000000;
//const int MAX_SIZE = 100;
int a[MAX_SIZE + 1];

int reverse(int n) {
    int result = n%10;
    if (result == 0) return 0;
    while (n > 9) {
        n /= 10;
        result *= 10;
        result += n%10;
    }
    return result;
}

int main() {
    for (int i = 1; i <= 20; ++i) a[i] = i;
    for (int i = 21; i <= MAX_SIZE; ++i) {
        int rev = reverse(i);
        if (rev && i > rev &&  a[rev] < a[i-1]) a[i] = a[rev]+1;
        else a[i] = a[i-1]+1;
        //        cerr << i << ' ' << rev << ' ' << a[i] << endl;
    }
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int x;
        cin >> x;
        cout << "Case #" << i << ": " << a[x] << endl;
    }

}
