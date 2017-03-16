#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while(b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int check(ll x) {
    int first_pos = -1;
    int num_ones = 0;
    for(int i = 0; i < 64; ++i) {
        if(x & (1LL << i)) {
            if(first_pos == -1)
                first_pos = i+1;
            ++num_ones;
        }
    }

    if(num_ones != 1) 
        return -1;

    return first_pos;
}

int last_bit(ll x) {
    int pos = 0;
    for(int i = 0; i < 64; ++i) {
        if(x & (1LL << i))
            pos = i;
    }
    return pos;
}


int main()
{
    ios::sync_with_stdio(false);
    
    fstream in("D:\\input.txt");
    fstream out("D:\\output.txt");

    int t;
    in >> t;

    for(int q = 1; q <= t; ++q) {
        ll x, y;

        in >> x;
        in.ignore(1);
        in >> y;

        ll g = gcd(x, y);
        x /= g;
        y /= g;

        int ans = check(y);
        int b1 = last_bit(x);
        int b2 = last_bit(y);

        out << "Case #" << q << ": ";
        if(ans == -1 || x == 0)
            out << "impossible";
        else
            out << b2 - b1;

        out << "\n";
    }

    system("pause");

    return 0;
} 