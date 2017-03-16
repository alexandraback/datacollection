#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    int temp;
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

        int a = atoi(s.substr(0, found).c_str());
        int b = atoi(s.substr(found + 1).c_str());

        int g = gcd(a, b); a = a/g; b = b/g;
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
