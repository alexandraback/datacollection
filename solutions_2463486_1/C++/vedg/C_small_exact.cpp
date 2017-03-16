

//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <cfloat>
#include <cctype>
#include <sstream>
using namespace std;

typedef long long L;


bool isPalindrome(L n)
{
    static L digits[120];

    int last = -1;
    do {
        digits[++last] = n % 10;
        n /= 10;
    } while (n != 0);

    int middle = (last + 1) / 2;
    for (int i = 0; i != middle; ++i) {
        if (digits[i] != digits[last - i])
            return false;
    }
    return true;
}

void printIfPalindrome(L n)
{
    if (isPalindrome(n))
        cout << /*L(sqrt(n)+0.5) << ' ' <<*/ n << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("<10^18", "w", stdout);
#endif

    for (int s = 1; s <= 9; ++s) { // sqrt length
        int middle = (s+1) / 2;
        vector<L> digits(middle);
        if (s > 2) {
            digits.front() = 1;
            digits.back() = -1;
        }

        bool end = false;
        while (true) {
            for (int i = middle - 1; ; --i) {
                if (digits[i] != 9)
                    ++digits[i];
                else if (i != 0) {
                    digits[i] = 0;
                    continue;
                }
                else
                    end = true;
                break;
            }
            if (end)
                break;

            L num = 0;
            for (int i = 0; i != digits.size(); ++i)
                num = num * 10 + digits[i];
            for (int i = s / 2 - 1; i >= 0; --i)
                num = num * 10 + digits[i];

            printIfPalindrome(num * num);
        }
    }







#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}


