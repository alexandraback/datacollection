#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const bool ONE_SIDE = false;

long long rev(long long x)
{
    char temp[20];
    sprintf(temp, "%I64d", x);
    int len = strlen(temp);
    reverse(temp, temp + len);
    sscanf(temp, "%I64d", &x);
    return x;
}

long long steps(long long start, long long end)
{
    char starts[20], ends[20];
    sprintf(ends, "%I64d", end);
    sprintf(starts, "%I64d", start);

    long long ret = end - start;
    int len = strlen(ends);
    for (int i = 0; i <= len; ++ i) {
        vector<int> values;
        if (strlen(starts) < strlen(ends)) {
            if (i == len) {
                continue;
            }
            for (int j = i; j > 0; -- j) {
                values.push_back(ends[j] - '0');
            }
        } else {
            for (int j = i - 1; j >= 0; -- j) {
                values.push_back(ends[j] - '0');
            }
        }


        // same
        if (true) {
            long long x = 0;
            for (int i = 0; i < values.size(); ++ i) {
                x = x * 10 + values[i];
            }
            if (rev(start + x) <= end) {
                ret = min(ret, x + (end - rev(start + x)) + 1);
            }
        }

        // minus one
        if (values.size() > 0) {
            -- values[0];
            for (int i = 0; i < values.size() && values[i] < 0; ++ i) {
                values[i] += 10;
                if (i + 1 < values.size()) {
                    -- values[i + 1];
                }
            }

            long long x = 0;
            for (int i = 0; i < values.size(); ++ i) {
                x = x * 10 + values[i];
            }
            //cerr << i << " " << x << " " << rev(start + x ) << " " << (end - rev(start + x)) << endl;
            if (rev(start + x) <= end) {
                ret = min(ret, x + (end - rev(start + x)) + 1);
            }
        }
    }
    //cerr << start << " " << end << ": " << ret << endl;
    return ret;
}

long long solve(long long n)
{
    if (n == 1) {
        return 0;
    }
    long long x = 1, answer = 0;
    while (x != n) {
        long long base = 1;
        while (base <= x) {
            base *= 10LL;
        }
        if (base <= n) {
            answer += steps(x, base);
            x = base;
        } else {
            answer += steps(x, n);
            x = n;
        }
    }
    return answer;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        long long n;
        scanf("%I64d", &n);
        printf("Case #%d: %I64d\n", test, solve(n) + 1);
    }
    return 0;
}
