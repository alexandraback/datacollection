#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b)
{
    long long temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int tc; cin >> tc;
    int ori_tc = tc;
    while (tc) {
        string s; cin >> s;

        size_t found = s.find("/");

        long long a = atoll(s.substr(0, found).c_str());
        long long b = atoll(s.substr(found + 1).c_str());

        long long g = gcd(a, b); a = a/g; b = b/g;
        int gen = 0;
        while (b % 2 == 0) {
            if(a >= b) break;
            b /= 2;

            gen ++;
        }
     
        while (b % 2 == 0) b /= 2;
        if(b != 1) printf("Case #%d: %s \n", ori_tc - tc + 1, "impossible");
        else printf("Case #%d: %d \n", ori_tc - tc + 1, gen);        
        tc --;
    }
}

