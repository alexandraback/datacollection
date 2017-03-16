#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int my_reverse(int n) {
    int t = 0;
    while (n != 0) {
        t = t * 10 + (n % 10);
        n /= 10;
    }
    return t;
}

void set_min(int n, int &a) {
    if (a == 0) {
        a = n;
    } else {
        a = min(a, n);
    }

}

int main()
{
    ifstream cin("test.in");
    ofstream cout("test.out");

    vector<int> v;
    v.reserve(1000001);
    v[0] = 0;
    v[1] = 1;
    int to = 1000000;
    for (int i = 2; i <= to; i++) {
        if (i < 10) { v[i] = v[i-1]+1; continue; }
        int rev = my_reverse(i);

        set_min(v[i-1]+1, v[i]);
        set_min(v[i]+1, v[rev]);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i+1 << ": " << v[n] << "\n";
    }
}
