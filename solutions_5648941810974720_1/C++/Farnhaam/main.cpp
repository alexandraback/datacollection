#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>

using namespace std;

int arr[500], res[10];
string s;

void process(int num, char c, string word)
{
    int cnt = arr[c];
    for (char a : word)
        arr[a] -= cnt;

    res[num] += cnt;
}

int main()
{
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        cin >> s;

        memset(arr, 0, sizeof arr);
        memset(res, 0, sizeof res);

        for (char c : s)
            ++arr[c];

        process(0, 'Z', "ZERO");
        process(2, 'W', "TWO");
        process(6, 'X', "SIX");
        process(8, 'G', "EIGHT");
        process(4, 'U', "FOUR");
        process(1, 'O', "ONE");
        process(5, 'F', "FIVE");
        process(7, 'V', "SEVEN");
        process(3, 'R', "THREE");
        process(9, 'I', "NINE");

        printf("Case #%d: ", CASE);
        for (int i = 0; i <= 9; ++i)
            for (int j = 0; j < res[i]; ++j)
                printf("%d", i);
        printf("\n");
    }


    return 0;
}
