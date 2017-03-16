#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <map>
#include <stack>
#include <ctime>
#include <cstring>
#include <cassert>

typedef signed char int8;
typedef unsigned char uint8;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

#define mp(a, b) std::make_pair(a, b)
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int CASE = 1; CASE <= T; ++CASE)
    {
        uint64 a;
        int n;
        cin >> a >> n;

        vector<int> v;
        v.clear();
        v.resize(n);


        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        sort(v.begin(), v.end());
        int res = 123456;
        int curr = 0;

        for (int i = 0; i < v.size(); ++i)
        {
            if (a > v[i])
            {
                a += v[i];
                continue;
            }

            res = min<int>(res, curr + v.size() - i);

            if (a == 1)
            {
                curr = res;
                break;
            }

            ++curr;
            a += a - 1;
            --i;
        }

        if (res == 123456)
            res = 0;

        printf("Case #%d: %d\n", CASE, min(res, curr));
    }

    return 0;
}
