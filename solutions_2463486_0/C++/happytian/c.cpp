#include<iostream>
using namespace std;

bool is_palindrome (long long n) {
    int bit[110], p = 0;
    while (n != 0) {
        bit[p++] = n % 10;
        n /= 10;
    }
    if (bit[0] == 0)
        return false;
    for (int i = 0; ; i++) {
        if (i > p - 1 -i)
            break;
        if (bit[i] != bit[p-1-i])
            return false;
    }
    return true;
}

int p_s(long long begin, long long end) {
    long long num = 0;
    for (long long i = 1; ; i++) {
        long long temp = i * i;
        if (temp >= begin && temp <= end && is_palindrome(i) && is_palindrome(temp)) {
            num++;
        }
        if (temp > end)
            break;
    }
    return num;
}

int main() {
    int T;
    long long a, b;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << p_s(a, b) << endl;
    }
}
