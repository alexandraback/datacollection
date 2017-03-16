#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

const int32_t N = 101;
int32_t x, y;

void Reflect(string *ans, char a, char b) {
    for (uint32_t i = 0; i < ans->size(); i++) {
        if ((*ans)[i] == a) {
            (*ans)[i] = b;
        }
        else if ((*ans)[i] == b) {
            (*ans)[i] = a;
        }
    }
}
int32_t main() {
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        scanf("%d%d", &x, &y);
        string ans = "";
        int32_t ax = abs(x);
        int32_t ay = abs(y);
        for (int32_t i = 0; i < ax; i++) {
            ans.push_back('W');
            ans.push_back('E');
        }
        for (int32_t i = 0; i < ay; i++) {
            ans.push_back('S');
            ans.push_back('N');
        }
        if (x < 0) {
            Reflect(&ans, 'W', 'E');
        }
        if (y < 0) {
            Reflect(&ans, 'N', 'S');
        }
        printf("Case #%d: %s\n", ic, ans.c_str());
    }
    return 0;
}
