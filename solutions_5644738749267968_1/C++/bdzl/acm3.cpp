#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>
 
using namespace std;

typedef long long ll;

const int max_n = 1e3 + 10;

int n;
int a[max_n];
int b[max_n];
int used[max_n];
int used2[max_n];

char str[100];

int my_scanf()
{
    scanf("%s", str);
    int len = strlen(str);
    while (len < 7) {
        str[len] = '0';
        ++len;
    }
    int x = 0;
    for (int i = 2; i < len; ++i)
        x = x * 10 + str[i] - '0';
    return x;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);
    for (int test = 1; test <= tests; ++test) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i)
            a[i] = my_scanf();
        for (int i = 0; i < n; ++i)
            b[i] = my_scanf();
        printf("Case #%d: ", test);
        sort(a, a + n);
        sort(b, b + n);
        int ans2 = 0;
        for (int i = 0; i < n; ++i) used[i] = 0;
        
        int Ra = n - 1;
        int Lb = 0;
        while (Ra >= 0 && a[Ra] > b[n - 1]) {
            ++ans2;
            --Ra;
            used[Lb] = 1;
            ++Lb;
        }
        for (int i = 0; i <= Ra; ++i) {
            int id = -1;
            for (int j = 0; j < n; ++j)
                if (!used[j] && b[j] > a[i]) {
                    id = j;
                    used[j] = 1;
                    break;
                }
            if (id == -1) {
                ++ans2;
                for (int j = 0; j < n; ++j) 
                    if (!used[j]) {
                        used[j] = 1;
                        break;
                    }
            }
        }
        
        int ans1 = 0;
        for (int i = 0, j = 0; i < n; ++i)
            if (a[i] > b[j]) {
                ++j;
                ++ans1;
            }
        
        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}
