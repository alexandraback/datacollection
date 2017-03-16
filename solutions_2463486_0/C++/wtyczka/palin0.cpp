#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;


bool is_palin(unsigned long long x)
{
    vector<char> digits;

    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    return equal(digits.begin(), digits.begin() + digits.size() / 2, digits.rbegin());
}

unsigned long long sqrt(unsigned long long x)
{
    unsigned long long a = 0, b = x;

    while (a < b) {
        unsigned long long cur = a + (b - a) / 2;
        if (cur * cur > x) {
            b = cur - 1;
        } else
        if (cur * cur < x) {
            a = cur + 1;
        } else
            return cur;
    }

    return a;
}


void test_is_palin()
{
    assert(is_palin(101));
    assert(is_palin(1001));
    assert(!is_palin(1201));
    assert(!is_palin(1021));
}

void test_sqrt()
{
    assert(sqrt(9) == 3);
    assert(sqrt(16) == 4);
    assert(sqrt(25) == 5);
    assert(sqrt(1024) == 32);
    assert(sqrt(1024) == 32);

    assert(sqrt(100000000000000) == 10000000);
}


int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    //test_sqrt();
    //test_is_palin();

    for (int i = 0; i < t; i++) {
        unsigned long long a, b;
        cin >> a >> b;

        unsigned long long z = sqrt(a) - 1;
        unsigned long long counter = 0;

        while (true) {
            unsigned long long mu = z * z;

            if (mu > b)
                break;

            if (mu >= a) {
                if (is_palin(z) && is_palin(mu)) {
                    //cout << "z " << z << " " << mu << endl;
                    counter++;
                }
            }

            z++;
        }

        cout << "Case #" << i + 1 << ": " << counter << endl;
    }
}


