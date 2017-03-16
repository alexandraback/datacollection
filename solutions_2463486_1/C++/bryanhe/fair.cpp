#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <inttypes.h>
#include <vector>

using namespace std;

bool isPalindrome(uint64_t n)
{
    char digit[105];
    int digits = 0;
    while (n > 0) {
        digit[digits] = (n % 10) + '0';
        n /= 10;
        digits++;
    }

    for (int i = 0; i < (digits / 2); i++) {
        if (digit[i] != digit[digits - i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;

    uint64_t i = 0;
    vector<uint64_t> palindrome;
    while ((i * i) <= 10e15) {
        if (isPalindrome(i) && isPalindrome(i * i)) {
            palindrome.push_back(i * i);
        }
        i++;
    }

    for (int counter = 1; counter <= T; counter++) {
        uint64_t A, B;
        uint64_t count = 0;
        cin >> A >> B;

        for (size_t n = 0; n < palindrome.size(); n++) {
            uint64_t n2 = palindrome[n];
            if (n2 >= A && n2 <= B && isPalindrome(n2)) {
                count++;
            }
        }

        cout << "Case #" << counter << ": " << count << "\n";
    }

    return 0;
}

