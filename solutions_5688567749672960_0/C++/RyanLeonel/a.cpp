#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector <int> num1;

int len1(long long n) {
    int len = 0, n1 = n;
    while (n1) {
        n1 /= 10; len++;
    }
    return len;
}

long long flip(long long n) {
    long long i, len = 0, n1 = n, res = 0;
    vector <int> x;
    while (n1) {
        len++; x.resize(len);
        x[len - 1] = n1 % 10; n1 /= 10;
    }
    for (i = 0; i < len; i++) {
        res *= 10; res += x[i];
    }
    return res;
}

long long num(long long n) {
    int a, b, n2, res;
    if (num1[n]) return num1[n];
    if (n == 1) return 1;
    a = num(n - 1) + 1;
    n2 = flip(n); res = a;
    if ((n2 < n) && (len1(n2) == len1(n))) {
        b = num(n2) + 1;
        if (b < a) res = b;
    }
    num1[n] = res;
    return res;
}

int main()
{
    long long cnt, i, j, n, res, t;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    num1.resize(1000001);
    num1[0] = 0; num1[1] = 1; for (i = 2; i < 1000001; i++) num1[i] = 0;
    for (i = 1; i < 1000000; i++) res = num(i);
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n;
        res = num(n);
        cout << "Case #" << cnt << ": " << res << endl;
    }
    return 0;
}
