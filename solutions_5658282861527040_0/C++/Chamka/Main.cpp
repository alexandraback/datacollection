#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

int main(){
    int test, testN, i, j, n, m, x, y;
    char s[200];
    scanf("%d\n", &testN);
    for (test = 1; test <= testN; test++)
    {
        int a, b, k, c = 0;
        scanf("%d%d%d", &a, &b, &k);
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < b; j++)
            {
                x = i & j;
                if (x < k) c++;
            }
        }
        printf("Case #%d: %d\n", test, c);
    }
    return 0;
}
