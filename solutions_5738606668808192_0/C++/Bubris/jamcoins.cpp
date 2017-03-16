#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

int isPrime(long long n) {
    for (long long i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;

}

int toBase(int n, int base) {

    return n;
}

string DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}


int main () {
    int t, n, j, count;
    count = 0;
    long long number = 32769;
    long long max = 65535;
    cin >> t >> n >> j;
    long long divisors[11];
    bool flag;
    int hurra;
    string s;
    cout << "Case #1: " << endl;
    while(number <= max && count < 50) {
        s = DecToBin(number);
        flag = true;
        for (int i = 2; i < 11; i++) {
            hurra = isPrime(stol(s, nullptr, i));
            if (hurra != -1) {
                divisors[i] = hurra;
            } else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << s;
            for (int i = 2; i < 11; i++) {
                cout << " " << divisors[i];
            }
            cout << endl;
            count++;
        }

        number += 2;
    }



        //    }

    return 0;
}
