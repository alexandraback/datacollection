#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

#define LENGTH (1100000)

char *name;
bool *valid;
int *nextInvalid;
int *constIndex;
int *firstOkay;

using namespace std;

bool isVowel(char a)
{
    return (a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u');
}

int64_t value(char *name, int64_t n)
{
    int length = strlen(name);
    for (int i = 0; i < length; i++) {
        valid[i] = !isVowel(name[i]);
    }

    int next = length;
    for (int i = (length - 1); i >= 0; i--) {
        if (!valid[i]) {
            next = i;
        }
        nextInvalid[i] = next;
    }

    constIndex[0] = 0;
    if (valid[0]) {
        constIndex[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        if (valid[i]) {
            constIndex[i] = (constIndex[i - 1] + 1);
        }
        else {
            constIndex[i] = 0;
        }
    }

    next = length + 1;
    for (int i = (length - 1); i >= 0; i--) {
        firstOkay[i] = next;
        if (nextInvalid[i] - i >= n) {
            firstOkay[i] = i + n;
            next = i + n;
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < length; i++) {
        ans += (length - firstOkay[i] + 1);
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    name = new char[LENGTH];
    valid = new bool[LENGTH];
    nextInvalid = new int[LENGTH];
    constIndex = new int[LENGTH];
    firstOkay = new int[LENGTH];
    int64_t n;

    for (int counter = 1; counter <= T; counter++) {
        cin >> name >> n;
        cout << "Case #" << counter << ": " << value(name, n) << "\n";
    }

    return 0;
}

